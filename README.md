# MSI - Market Services and Infrastructure - Design Overview
The project's objective is to provide a compendium of libraries, not unlike boost, but more abstract and focused on financial markets services.

There are 3 main concepts: modules, connectors and services.

## Modules
Modules can be seen as a block that takes an input, performs some logic and produces an output. Input can be in the form of I/O or public functions exposed by the module, and output can also be in the form of I/O or events, which are implemented using std::function.

At first every module had public typedefs defining its event's signatures. This behaviour was eventually refactored using variadic templates and abstracted into the event and event_handler templates (msi/event.hpp and msi/event_handler.hpp), although some of the earlier code still uses typedefs. 

The event template can be seen in use in marketdata\common\receiver.hpp as an event source and umdf\ticker_plant\src\ticker_plant.cpp (line 46) as an event receiver.

Modules can be further divided in border modules and intermediary modules.

Border modules perform I/O on one side and connect to other modules on the other side, e.g. a multicast_receiver module receives multicast data from the network and outputs the received datagrams to be used in another library, and a multicast_sender module takes input from other modules and sends over the network using multicast.

Modules are intended to provide a specific functionality, .e.g. FAST decoding, datagram sequencing, etc,  and do not concern themselves with thread synchronization or messaging, meaning that none of the modules should be assumed to be thread safe.

## Connectors
Between modules there is the concept of connectors which are used to connect output from one module to the input of another. 

Connectors are optional and modules may be linked directly to one another, e.g. the multicast_receiver module has an on_receive(const unsigned char*, std::size_t) event, which matches one of the inputs of the sequencing_machine module, so a simple std::bind can be used instead of a more complex connector.

If a module is to receive input from multiple threads, then a connector can be used between the producer modules and the consumer module to provide synchronization. For instance if we have two async tcp clients running on different threads and we want a single handler to handle input from both, we would instantiate a connector that register with the on_data event of both producers and lock on a mutex before calling the consumers input function.

Connectors can also provide other functionality when building module pipelinesm, e.g. a fan-out connector might receive events from a producer and send them to multiple consumers.

Implementation details of connectors vary according to the needs of the user. The fan-out connector for instance could be implemented using zeromq pub-sub sockets and inproc protocol. 

In fact, the inspiration for this module-connector-module pipeline design comes from zeromq's architecture.

## Services

Services are units of business funcionality.

A service will orchestrate one or more modules to achieve its goal. An example of such composition can be seen in the umdf_ticker_plant module. It is configured via injection with receiver and decoder modules, and also makes use of the tcp_server and marketdata_serialization modules.

The ticker_plant module wires the output from the receiver to the input of the decoder and the output of the decoder to a function template that will use the marketdata_serialization module to serialize the decoded message and the tcp_server module to write to connected parties.

The ticker_plant_service would then use the module, as can be seen in the umdf_test_ticker_plant project. The service instantiates and injects all the module's dependencies and wires modules to one another.

# Description of available modules

##
