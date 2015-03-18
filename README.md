# MSI - Market Services and Infrastructure - Design Overview
The project's objective is to provide a compendium of libraries, not unlike boost, but more abstract and focused on financial markets services. It takes design ideas from established libraries like boost, zeromq and the LMAX architecture popularized by Martin Fowler.

There are 3 main concepts: modules, connectors and services.

## Modules
Modules can be seen as a block that takes an input, performs some logic and produces an output. Input can be in the form of I/O or public functions exposed by the module, and output can also be in the form of I/O or events, which are implemented using std::function.

At first every module had public typedefs defining its event's signatures. This behaviour was eventually refactored using variadic templates and abstracted into the event and event_handler templates (msi/event.hpp and msi/event_handler.hpp), although some of the earlier code still uses typedefs. 

The event template can be seen in use in marketdata\common\receiver.hpp as an event source and umdf\ticker_plant\src\ticker_plant.cpp (line 46) as an event receiver.

Modules can be further divided in border modules and intermediary modules.

Border modules perform I/O on one side and connect to other modules on the other side, e.g. a multicast_receiver module receives multicast data from the network and outputs the received datagrams to be used in another library, and a multicast_sender module takes input from other modules and sends over the network using multicast.

Intermediary modules receive input as function calls and produce output in the form of events.

Modules are intended to provide a specific functionality, .e.g. FAST decoding, datagram sequencing, etc,  and do not concern themselves with thread synchronization or messaging.

The modules are not thread safe, so do not use the same instance of a module from multiple threads.

The modules do not make any assumption as to how the data they produce will be used, they may however make assumptions on input data.

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


#Structure and Environment

The directory structure follows the one used by boost. In the root of the project you'll find an *msi* directory which contains all headers and a *libs* directory which contains the sources, mpc files for project generation, miscellaneous tools related to the library and unit tests. Resources such as FIX dictionaries are in the *resources* directory. The *etc* directory contains scripts and tools. Compiled libraries go into *lib*, executables into *bin* and unit tests into *unittests*.

The project uses MPC (Makefile Project Creator) to generate Visual Studio solutions for Windows or makefiles for Linux.

Like boost, modules are grouped into a single library when appropriate, for instance the network library contains the tcp server and client modules, as well as the multicast sender and receiver modules.

The code is meant to be portable, even though at this point development has been in Windows only. Also some of the performance tests contain windows specific code (mainly QueryPerformanceCounter stuff) that would need to be removed when compiling for Linux.

Dependencies (versions reflect the last successful build, currently building with VC12):
* [MPC 4.1.0](https://www.ociweb.com/products/mpc)
* [QuickFIX 1.14.3](http://www.quickfixengine.org/)
* [QuickFAST 1.5.0](https://www.ociweb.com/products/QuickFAST)
* [boost 1.57.0](http://www.boost.org/)
 
To build on windows, adjust your *setenv.bat* script, run it, and then in the *libs* directory run "mwc.pl -type vc12 msi.mwc". This will generate the solution file to open in Visual Studio.


# Description of available libraries

##concepts
The concepts library is just a sandbox for testing ideas and performance.

##logging
Logging library. Currently contains 3 types of loggers: Console, File and Null (which just ignores log requests). The console logger is thread-safe.

##marketdata_common
Contains interfaces and constants that are shared by marketdata related modules.

##marketdata_messages
Contains the definition of the internal representation of messages available to marketdata modules. These should be used by other modules in order to maintain portability over different protocols. Adapters can be used to translate between third party formats and MSI's internal format.

Messages are meant to be reused in order to avoid unecessary memory allocations so all messages contain a presence map along with its fields. The reset function zeroes out the presence map.

The message classes are generated using scripts and XSLT, which are located in *libs/marketdata/messages/tools*.

##marketdata_serialization
Specialized serializers for the messages defined in the marketdata_messages library.

The idea is to provide low latency serialization, which is accomplished by preallocating a buffer large enough to contain all fixed-width fields plus a sensible buffer for strings. A tradeoff was made to favour the cpu over the network, so fixed width fields are always transmitted even if they are not present. The client then needs to rely on the presence map to determine wheter or not to use a field. Strings on the other hand are only transmitted when present.

Generated using XSLT.

##network
Provides higher level abstractions over boost::asio. At this point there are tcp and multicast clients and servers available.

##umdf_messages
Defines messages that are received from BMFBovespa UMDF. This is a one to one map to the exchange's FAST messages and are meant to be used by the FAST decoder.

Generated using XSLT.

##umdf_decoder_quickfast
Implements builders for each message type defined in umdf_messages to be decoded using the QuickFAST engine.

The engine will take a data pointer and output events for each decoded message.

Generated using XSLT.

##umdf_adapter
Implements an adapter layer to convert between umdf_messages and marketdata_messages.

##umdf_recovery
Implements TCP Recovery functionality according to the specification of BMFBovespa UMDF.

Only the null service is implemented at this point. The module's API is defined and the extensions to QuickFIX message types are already implemented but the QuickFIX client itself still isn't.

##umdf_receiver
Implements datagram ordering, chunk assembly and loss recovery according to the specification of BMFBovespa UMDF.

##umdf_ticker_plant
A higher level module, intended to be used by the ticker_plant service to publish UMDF marketdata via TCP using the protocol and messages defined in marketdata_messages and marketdata_serialization.

This module defines the pipeline from receiver -> decoder -> marketdata_serialization -> tcp_server.

The receiver and decoder modules are injected. In the umdf_ticker_plant_test project the entire pipeline can be seen:

*multicast_receiver -> sequencing_machine -> quickfast_decoder -> umdf_adapter -> marketdata_serialization -> tcp_server*

Based on the ideas published by LMAX this entire pipeline tries to allocate as little as possible and runs entirely in a single thread in order to avoid concurrency problems, scheduling latency and keep the data as close to the cache as possible. This is achieved by wiring modules directly with std::bind.

# Latency results

To put things in context, the entirety of BMFBovespa - including both markets - at it's peak does not produce more than around 3,000 messages per second. The feed is received either through a dedicated fiber network or inside the exchange's colocation. These are the paremeters I worked with when considering the performance of the application.

Performance tests then assume the expected scenario of small messages (mostly bid, ask and trade) and near-zero packet loss and reordering.

The system that this library was initially intended to replace presented an average lantecy of around 3ms from receiving a datagram to being able to use the data in my code.

* Benchmark: 3ms from datagram to business logic
* MSI Datagram Sequencing: 36ns/msg = 27.560.000msg/s.
* Decoding of Bid MDEntry: 6,569us/msg = 152.219 msg/s
* Serialization + Deserialization: 238ns/msg = 4.186.900msg/s
* Total time from network to business logic: ~6.8us/msg = ~147.000msg/s.

The new system is capable of handling 49x the peak volume of the entire marketdata. Also most of the time is spent in the decoding step and replacing QuickFAST with a commercial or a purpose-built decoder should improve those times significantly.


#Roadmap

* Finish the implementation of the QuickFIX recovery service
* Detach tcp_server from the ticker_plant module, thus making it an intermediary module
* Implement a filtered_ticker_plant module that takes the output from ticker_plant and performs topic based filtering before outputting messages
* Implement the filtered_ticker_plant service using tcp_server as an interface for the ticker_plant module.
* Replace explicit std::function typedefs with the new event/event_handler model.
* Replace all XSLT based code generation with a python compiler.
* Review code for opportunities to templatize or abstract. Especially in modules that deal with marketdata, e.g. umdf_adapter and umdf_decoder_quickfast, where there is a lot of repetition.
