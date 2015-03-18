<xsl:stylesheet version='1.0'
                xmlns:xsl='http://www.w3.org/1999/XSL/Transform'>

<xsl:output method="text"/>
<xsl:strip-space elements="*"/>

<xsl:variable name="lower" select="'abcdefghijklmnopqrstuvwxyz'" />
<xsl:variable name="upper" select="'ABCDEFGHIJKLMNOPQRSTUVWXYZ'" />

<xsl:param name="message_name" select="message_name"/>

<xsl:template name="field_type">
  <xsl:choose>
    <xsl:when test="local-name()='uInt32'">
      <xsl:text>FieldUInt32</xsl:text>
    </xsl:when>
    <xsl:when test="local-name()='uInt64'">
      <xsl:text>FieldUInt64</xsl:text>
    </xsl:when>
    <xsl:when test="local-name()='int32'">
      <xsl:text>FieldInt32</xsl:text>
    </xsl:when>
    <xsl:when test="local-name()='int64'">
      <xsl:text>FieldInt64</xsl:text>
    </xsl:when>
    <xsl:when test="local-name()='decimal'">
      <xsl:text>FieldDecimal</xsl:text>
    </xsl:when>
    <xsl:when test="local-name()='string'">
      <xsl:text>FieldAscii</xsl:text>
    </xsl:when>
  </xsl:choose>
</xsl:template>

<xsl:template name="field_value">
  <xsl:choose>
    <xsl:when test="constant">
      <xsl:value-of select="constant/@value"/>
    </xsl:when>
    <xsl:otherwise>
      <xsl:value-of select="@id"/>
    </xsl:otherwise>
  </xsl:choose>
</xsl:template>

<xsl:template name="field_create">
  <xsl:choose>
    <xsl:when test="local-name()='uInt32'">
      <xsl:call-template name="field_value"/>
    </xsl:when>
    <xsl:when test="local-name()='uInt64'">
      <xsl:call-template name="field_value"/>
    </xsl:when>
    <xsl:when test="local-name()='int32'">
      <xsl:call-template name="field_value"/>
    </xsl:when>
    <xsl:when test="local-name()='int64'">
      <xsl:call-template name="field_value"/>
    </xsl:when>
    <xsl:when test="local-name()='decimal'">
      <xsl:call-template name="field_value"/>
      <xsl:text>, 0</xsl:text>
    </xsl:when>
    <xsl:when test="local-name()='string'">
      <xsl:text>"</xsl:text>
      <xsl:call-template name="field_value"/>
      <xsl:text>"</xsl:text>
    </xsl:when>
  </xsl:choose>
</xsl:template>

<xsl:template name="field_create_check">
  <xsl:choose>
    <xsl:when test="local-name()='uInt32'">
      <xsl:call-template name="field_value"/>
    </xsl:when>
    <xsl:when test="local-name()='uInt64'">
      <xsl:call-template name="field_value"/>
    </xsl:when>
    <xsl:when test="local-name()='int32'">
      <xsl:call-template name="field_value"/>
    </xsl:when>
    <xsl:when test="local-name()='int64'">
      <xsl:call-template name="field_value"/>
    </xsl:when>
    <xsl:when test="local-name()='decimal'">
      <xsl:text>apoena::msi::decimal( </xsl:text>
      <xsl:call-template name="field_value"/>
      <xsl:text>, 0 )</xsl:text>
    </xsl:when>
    <xsl:when test="local-name()='string'">
      <xsl:text>"</xsl:text>
      <xsl:call-template name="field_value"/>
      <xsl:text>"</xsl:text>
    </xsl:when>
  </xsl:choose>
</xsl:template>

<xsl:template match="templates">
  <xsl:text>#include &lt;msi/umdf/decoder/quickfast/umdf_decoder_quickfast_pch.hpp&gt;
#define BOOST_TEST_NO_MAIN umdf_quickfast_decoder_test
#include &lt;boost/test/unit_test.hpp&gt;

#include &lt;functional&gt;
#include &lt;Codecs/Encoder.h&gt;
#include &lt;Codecs/Decoder.h&gt;
#include &lt;Codecs/DataDestination.h&gt;
#include &lt;Codecs/DataSourceString.h&gt;
#include &lt;Common/Types.h&gt;
#include &lt;Messages/Message.h&gt;
#include &lt;Messages/FieldIdentity.h&gt;
#include &lt;Messages/FieldInt32.h&gt;
#include &lt;Messages/FieldUInt32.h&gt;
#include &lt;Messages/FieldInt64.h&gt;
#include &lt;Messages/FieldUInt64.h&gt;
#include &lt;Messages/FieldAscii.h&gt;
#include &lt;Messages/FieldByteVector.h&gt;
#include &lt;Messages/FieldDecimal.h&gt;
#include &lt;Messages/FieldGroup.h&gt;
#include &lt;Messages/FieldSequence.h&gt;
#include &lt;Messages/FieldUtf8.h&gt;
#include &lt;Messages/Sequence.h&gt;

#include &lt;msi/decimal/decimal.hpp&gt;
#include &lt;msi/umdf/messages/field_id.hpp&gt;
#include &lt;msi/umdf/decoder/quickfast/builder_selector.hpp&gt;
</xsl:text>
  <xsl:text>#include &lt;msi/umdf/messages/</xsl:text>
  <xsl:value-of select="$message_name"/>
  <xsl:text>.hpp&gt;&#xa;</xsl:text>

  <xsl:text>#include &lt;msi/umdf/decoder/quickfast/</xsl:text>
  <xsl:value-of select="$message_name"/>
  <xsl:text>_builder.hpp&gt;&#xa;&#xa;</xsl:text>

  <xsl:text>namespace &#xa;{&#xa;&#xa;</xsl:text>
  <xsl:text>using namespace apoena::msi::umdf::decoder::quickfast;&#xa;</xsl:text>
  <xsl:text>using namespace apoena::msi::umdf::messages;&#xa;</xsl:text>
  <xsl:text>using namespace QuickFAST;&#xa;&#xa;</xsl:text>

  <xsl:text>struct message_container&#xa;{&#xa;</xsl:text>
  <xsl:text>  void on_message( const </xsl:text>
  <xsl:value-of select="$message_name"/>
  <xsl:text>&amp; message )&#xa;  {&#xa;    message_ = message;&#xa;  }&#xa;</xsl:text>
  <xsl:text>&#xa;  </xsl:text>
  <xsl:value-of select="$message_name"/>
  <xsl:text> message_;&#xa;};&#xa;&#xa;</xsl:text>
  <xsl:text>}&#xa;&#xa;</xsl:text>

  <xsl:text>BOOST_AUTO_TEST_SUITE( suite_</xsl:text>
  <xsl:value-of select="$message_name"/>
  <xsl:text>_builder )&#xa;&#xa;</xsl:text>

  <xsl:apply-templates select="template"/>

  <xsl:text>&#xa;BOOST_AUTO_TEST_SUITE_END()&#xa;</xsl:text>
</xsl:template>

<xsl:template match="template">

  <xsl:text>BOOST_AUTO_TEST_CASE( test_builder_</xsl:text>
  <xsl:value-of select="@id"/>
  <xsl:text> )&#xa;{&#xa;</xsl:text>
  <xsl:text>  std::string xml( std::getenv( "MSI_ROOT" ) );&#xa;</xsl:text>
  <xsl:text>  xml += "/resources/templates-PUMA.xml";&#xa;</xsl:text>
  <xsl:text>  std::ifstream template_file( xml, std::ifstream::binary );&#xa;&#xa;</xsl:text>
  <xsl:text>  BOOST_REQUIRE( template_file.good() ) ;&#xa;&#xa;</xsl:text>
  <xsl:text>  Codecs::XMLTemplateParser parser;&#xa;</xsl:text>
  <xsl:text>  Codecs::TemplateRegistryPtr template_registry = parser.parse( template_file );&#xa;&#xa;</xsl:text>
  <xsl:text>  Codecs::Encoder encoder( template_registry );&#xa;</xsl:text>
  <xsl:text>  Codecs::DataDestination destination;&#xa;&#xa;</xsl:text>
  
  <xsl:text>  typedef Messages::FieldIdentity id;&#xa;&#xa;</xsl:text>
  <xsl:text>  Messages::Message msg( template_registry->maxFieldCount() );&#xa;&#xa;</xsl:text>

  <xsl:for-each select="*[not(self::template)]">
    <xsl:call-template name="id"/>
  </xsl:for-each>
  <xsl:apply-templates select="sequence" mode="id"/>

  <xsl:text>&#xa;</xsl:text>

  <xsl:for-each select="*[not(self::template) and not(self::sequence)]">
    <xsl:call-template name="addfield"/>
  </xsl:for-each>
  <xsl:text>&#xa;</xsl:text>
  <xsl:apply-templates select="sequence" mode="addfield"/>

  <xsl:for-each select="*[(self::sequence)]">
    <xsl:text>  msg.addField( </xsl:text>
    <xsl:value-of select="translate(@name, $upper, $lower)"/>
    <xsl:text>_id, Messages::FieldSequence::create( </xsl:text>
    <xsl:value-of select="@name"/>
    <xsl:text>_seq ) );&#xa;&#xa;</xsl:text>
  </xsl:for-each>

  <xsl:text>  encoder.encodeMessage( destination, </xsl:text>
  <xsl:value-of select="@id"/>
  <xsl:text>, msg );&#xa;</xsl:text>
  <xsl:text>  std::string fast_string;&#xa;</xsl:text>
  <xsl:text>  destination.toString( fast_string );&#xa;</xsl:text>
  <xsl:text>  destination.clear();&#xa;&#xa;</xsl:text>
  <xsl:text>  Codecs::Decoder decoder( template_registry );&#xa;&#xa;</xsl:text>
  <xsl:text>  message_container container;&#xa;</xsl:text>
  <xsl:text>  auto builder = std::make_shared&lt;</xsl:text>
  <xsl:value-of select="$message_name"/>
  <xsl:text>_builder&gt;();&#xa;</xsl:text>
  <xsl:text>  builder->register_on_message_callback( std::bind( &amp;message_container::on_message, &amp;container, std::placeholders::_1 ) );&#xa;&#xa;</xsl:text>

  <xsl:text>  builder_selector selector;&#xa;</xsl:text>
  <xsl:text>  selector.add_builder( "</xsl:text>

  <xsl:if test="string[@name='MessageType']">
    <xsl:value-of select="string[@name='MessageType']/constant/@value"/>
  </xsl:if>

  <xsl:if test="string[@name='MsgType']">
    <xsl:value-of select="string[@name='MsgType']/constant/@value"/>
  </xsl:if>

  <xsl:text>", builder );&#xa;&#xa;</xsl:text>

  <xsl:text>  Codecs::DataSourceString source( fast_string );&#xa;</xsl:text>
  <xsl:text>  decoder.reset();&#xa;</xsl:text>
  <xsl:text>  decoder.decodeMessage( source, selector );&#xa;&#xa;</xsl:text>
  
  <xsl:text>  </xsl:text>
  <xsl:value-of select="$message_name"/>
  <xsl:text>&amp; m = container.message_;&#xa;&#xa;</xsl:text>

  <xsl:for-each select="*[not(self::template) and not(self::sequence)]">
    <xsl:call-template name="add_check"/>
  </xsl:for-each>
  <xsl:text>&#xa;</xsl:text>
  <xsl:apply-templates select="sequence" mode="add_check"/>

  <xsl:text>}&#xa;&#xa;</xsl:text>

</xsl:template>

<xsl:template name="id">
  <xsl:text>  id </xsl:text>
  <xsl:value-of select="translate(@name, $upper, $lower)"/>
  <xsl:text>_id( "</xsl:text>
  <xsl:value-of select="@name"/>
  <xsl:text>" );&#xa;</xsl:text>
  <xsl:apply-templates select="*[@id]"/>
</xsl:template>

<xsl:template name="addfield">
  <xsl:text>  </xsl:text>
  <xsl:choose>
    <xsl:when test="parent::template">
      <xsl:if test="parent::template">
        <xsl:text>msg.addField( </xsl:text>
      </xsl:if>
    </xsl:when>
    <xsl:otherwise>
      <xsl:value-of select="parent::sequence/@name"/>
      <xsl:text>->addField( </xsl:text>
    </xsl:otherwise>
  </xsl:choose>

  <xsl:value-of select="translate(@name, $upper, $lower)"/>
  <xsl:text>_id, Messages::</xsl:text>
  <xsl:call-template name="field_type"/>
  <xsl:text>::create( </xsl:text>
  <xsl:call-template name="field_create"/>
  <xsl:text> ) );&#xa;</xsl:text>
</xsl:template>

<xsl:template name="check_name">
   <xsl:choose>
    <xsl:when test="parent::template">
      <xsl:if test="parent::template">
        <xsl:text>m.</xsl:text>
      </xsl:if>
    </xsl:when>
    <xsl:otherwise>
      <xsl:value-of select="parent::sequence/@name"/>
      <xsl:text>_msg.</xsl:text>
    </xsl:otherwise>
  </xsl:choose>
</xsl:template>

<xsl:template name="add_check">
  <xsl:text>  BOOST_CHECK( </xsl:text>
  <xsl:call-template name="check_name"/> 

  <xsl:value-of select="@name"/>
  <xsl:text>().first );&#xa;</xsl:text>

  <xsl:text>  BOOST_CHECK_EQUAL( </xsl:text>
  <xsl:call-template name="check_name"/> 
  <xsl:value-of select="@name"/>
  <xsl:text>().second, </xsl:text>
  <xsl:call-template name="field_create_check"/>
  <xsl:text> );&#xa;</xsl:text>
</xsl:template>

<xsl:template match="sequence" mode="id">
  <xsl:for-each select="*">
    <xsl:call-template name="id"/>
  </xsl:for-each>
  <xsl:apply-templates select="sequence" mode="id"/>
</xsl:template>

<xsl:template match="sequence" mode="addfield">
  <xsl:text>  Messages::SequencePtr </xsl:text>
  <xsl:value-of select="@name"/>
  <xsl:text>_seq( new Messages::Sequence( </xsl:text>
  <xsl:value-of select="translate(@name, $upper, $lower)"/>
  <xsl:text>_id, 1 ) );&#xa;</xsl:text>
  <xsl:text>  Messages::FieldSetPtr </xsl:text>
  <xsl:value-of select="@name"/>
  <xsl:text>( new Messages::FieldSet( </xsl:text>
  <xsl:value-of select="count(*[not(self::length)])"/>
  <xsl:text> ) );&#xa;&#xa;</xsl:text>

  <xsl:for-each select="*[not(self::sequence) and not(self::length)]">
    <xsl:call-template name="addfield"/>
  </xsl:for-each>
  <xsl:text>&#xa;</xsl:text>

  <xsl:apply-templates select="sequence" mode="addfield"/>

  <xsl:text>  </xsl:text>
  <xsl:value-of select="@name"/>
  <xsl:text>_seq->addEntry( </xsl:text>
  <xsl:value-of select="@name"/>
  <xsl:text> );&#xa;&#xa;</xsl:text>

  <xsl:if test="parent::sequence">
    <xsl:text>  </xsl:text>
    <xsl:value-of select="parent::sequence/@name"/>
    <xsl:text>->addField( </xsl:text>
    <xsl:value-of select="translate(@name, $upper, $lower)"/>
    <xsl:text>_id, Messages::FieldSequence::create( </xsl:text>
    <xsl:value-of select="@name"/>
    <xsl:text>_seq ) );&#xa;&#xa;</xsl:text>
  </xsl:if>
</xsl:template>

<xsl:template match="sequence" mode="hierarchy">
  <xsl:apply-templates select="parent::sequence" mode="hierarchy"/>

  <xsl:text>::</xsl:text>
  <xsl:value-of select="translate(@name, $upper, $lower)"/>
</xsl:template>

<xsl:template name="sequence_hierarchy">
  <xsl:if test="local-name()='sequence'">
    <xsl:apply-templates select="parent::sequence" mode="hierarchy"/>
    <xsl:text>::</xsl:text>
    <xsl:value-of select="translate(@name, $upper, $lower)"/>
  </xsl:if>
</xsl:template>

<xsl:template match="sequence" mode="add_check">
  <xsl:text>  BOOST_REQUIRE_EQUAL( </xsl:text>
  <xsl:call-template name="check_name"/>
  <xsl:value-of select="@name"/>
  <xsl:text>().size(), 1 );&#xa;</xsl:text>
  <xsl:text>  const </xsl:text>
  <xsl:value-of select="$message_name"/>
  <xsl:call-template name="sequence_hierarchy"/>
  <xsl:text>&amp; </xsl:text>
  <xsl:value-of select="@name"/>
  <xsl:text>_msg = </xsl:text>

  <xsl:if test="parent::template">
    <xsl:text>m</xsl:text>
  </xsl:if>

  <xsl:if test="parent::sequence">
    <xsl:value-of select="parent::sequence/@name"/>
    <xsl:text>_msg</xsl:text>
  </xsl:if>

  <xsl:text>.</xsl:text>
  <xsl:value-of select="@name"/>
  <xsl:text>()[0];&#xa;&#xa;</xsl:text>

  <xsl:for-each select="*[not(self::sequence) and not(self::length)]">
    <xsl:call-template name="add_check"/>
  </xsl:for-each>

  <xsl:text>&#xa;</xsl:text>

  <!-- nested sequence definitions -->
  <xsl:apply-templates select="sequence" mode="add_check"/>
</xsl:template>

</xsl:stylesheet>

