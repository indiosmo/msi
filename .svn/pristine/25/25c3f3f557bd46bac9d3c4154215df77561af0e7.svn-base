<xsl:stylesheet version='1.0'
                xmlns:xsl='http://www.w3.org/1999/XSL/Transform'>

<xsl:output method="text"/>
<xsl:strip-space elements="*"/>

<xsl:variable name="lower" select="'abcdefghijklmnopqrstuvwxyz'" />
<xsl:variable name="upper" select="'ABCDEFGHIJKLMNOPQRSTUVWXYZ'" />

<xsl:param name="message_name" select="message_name"/>

<xsl:template name="type_name">
  <xsl:choose>
    <xsl:when test="local-name()='uInt32'">
      <xsl:text>uint32_t</xsl:text>
    </xsl:when>
    <xsl:when test="local-name()='uInt64'">
      <xsl:text>uint64_t</xsl:text>
    </xsl:when>
    <xsl:when test="local-name()='int32'">
      <xsl:text>int32_t</xsl:text>
    </xsl:when>
    <xsl:when test="local-name()='int64'">
      <xsl:text>int64_t</xsl:text>
    </xsl:when>
    <xsl:when test="local-name()='decimal'">
      <xsl:text>decimal</xsl:text>
    </xsl:when>
    <xsl:when test="local-name()='string'">
      <xsl:text>std::string</xsl:text>
    </xsl:when>
    <xsl:when test="local-name()='sequence'">
      <xsl:text>std::vector&lt;</xsl:text>
      <xsl:value-of select="translate(@name, $upper, $lower)"/>
      <xsl:text>&gt;</xsl:text>
    </xsl:when>
  </xsl:choose>
</xsl:template>

<xsl:template name="parent_type_name">
  <xsl:choose>
    <xsl:when test="local-name(..)='uInt32'">
      <xsl:text>uint32_t</xsl:text>
    </xsl:when>
    <xsl:when test="local-name(..)='uInt64'">
      <xsl:text>uint64_t</xsl:text>
    </xsl:when>
    <xsl:when test="local-name(..)='int32'">
      <xsl:text>int32_t</xsl:text>
    </xsl:when>
    <xsl:when test="local-name(..)='int64'">
      <xsl:text>int64_t</xsl:text>
    </xsl:when>
    <xsl:when test="local-name(..)='decimal'">
      <xsl:text>decimal</xsl:text>
    </xsl:when>
    <xsl:when test="local-name(..)='string'">
      <xsl:text>std::string</xsl:text>
    </xsl:when>
    <xsl:when test="local-name(..)='sequence'">
      <xsl:text>std::vector&lt;</xsl:text>
      <xsl:value-of select="translate(@name, $upper, $lower)"/>
      <xsl:text>&gt;</xsl:text>
    </xsl:when>
  </xsl:choose>
</xsl:template>


<xsl:template name="fast_type_name">
  <xsl:choose>
    <xsl:when test="local-name()='uInt32'">
      <xsl:text>UINT32</xsl:text>
    </xsl:when>
    <xsl:when test="local-name()='uInt64'">
      <xsl:text>UINT64</xsl:text>
    </xsl:when>
    <xsl:when test="local-name()='int32'">
      <xsl:text>INT32</xsl:text>
    </xsl:when>
    <xsl:when test="local-name()='int64'">
      <xsl:text>INT64</xsl:text>
    </xsl:when>
    <xsl:when test="local-name()='decimal'">
      <xsl:text>DECIMAL</xsl:text>
    </xsl:when>
    <xsl:when test="local-name()='string'">
      <xsl:choose>
        <xsl:when test="@charset='unicode'">
          <xsl:text>UTF8</xsl:text>
        </xsl:when>

        <xsl:otherwise>
          <xsl:text>ASCII</xsl:text>
        </xsl:otherwise>
      </xsl:choose>
    </xsl:when>
  </xsl:choose>
</xsl:template>

<xsl:template name="fast_alt_type_name">
  <xsl:choose>
    <xsl:when test="@name='uInt32'">
      <xsl:text>UINT32</xsl:text>
    </xsl:when>
    <xsl:when test="@name='uInt64'">
      <xsl:text>UINT64</xsl:text>
    </xsl:when>
    <xsl:when test="@name='int32'">
      <xsl:text>INT32</xsl:text>
    </xsl:when>
    <xsl:when test="@name='int64'">
      <xsl:text>INT64</xsl:text>
    </xsl:when>
    <xsl:when test="@name='decimal'">
      <xsl:text>DECIMAL</xsl:text>
    </xsl:when>
    <xsl:when test="@name='string'">
      <xsl:choose>
        <xsl:when test="@charset='unicode'">
          <xsl:text>UTF8</xsl:text>
        </xsl:when>

        <xsl:otherwise>
          <xsl:text>ASCII</xsl:text>
        </xsl:otherwise>
      </xsl:choose>
    </xsl:when>
  </xsl:choose>
</xsl:template>

<xsl:template name="getter">
  <xsl:choose>
    <xsl:when test="local-name()='uInt32'">
      <xsl:text>toUInt32()</xsl:text>
    </xsl:when>
    <xsl:when test="local-name()='uInt64'">
      <xsl:text>toUInt64()</xsl:text>
    </xsl:when>
    <xsl:when test="local-name()='int32'">
      <xsl:text>toInt32()</xsl:text>
    </xsl:when>
    <xsl:when test="local-name()='int64'">
      <xsl:text>toInt64()</xsl:text>
    </xsl:when>
    <xsl:when test="local-name()='decimal'">
      <xsl:text>toDecimal()</xsl:text>
    </xsl:when>
    <xsl:when test="local-name()='string'">
      <xsl:text>toString()</xsl:text>
    </xsl:when>
  </xsl:choose>
</xsl:template>

<xsl:template name="alt_getter">
  <xsl:choose>
    <xsl:when test="@name='uInt32'">
      <xsl:text>toUInt32()</xsl:text>
    </xsl:when>
    <xsl:when test="@name='uInt64'">
      <xsl:text>toUInt64()</xsl:text>
    </xsl:when>
    <xsl:when test="@name='int32'">
      <xsl:text>toInt32()</xsl:text>
    </xsl:when>
    <xsl:when test="@name='int64'">
      <xsl:text>toInt64()</xsl:text>
    </xsl:when>
    <xsl:when test="@name='decimal'">
      <xsl:text>toDecimal()</xsl:text>
    </xsl:when>
    <xsl:when test="@name='string'">
      <xsl:text>toString()</xsl:text>
    </xsl:when>
  </xsl:choose>
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

<xsl:template name="field_hierarchy">
  <xsl:if test="parent::sequence">
    <xsl:apply-templates select="parent::sequence" mode="hierarchy"/>
  </xsl:if>
</xsl:template>

<xsl:template name="alt_field_hierarchy">
  <xsl:if test="ancestor::sequence">
    <xsl:apply-templates select="ancestor::sequence" mode="hierarchy"/>
  </xsl:if>
</xsl:template>

<xsl:template match="sequence" mode="builder_hierarchy">
  <xsl:apply-templates select="parent::sequence" mode="builder_hierarchy"/>

  <xsl:value-of select="translate(@name, $upper, $lower)"/>
  <xsl:text>_builder::</xsl:text>
</xsl:template>

<xsl:template name="sequence_builder_hierarchy">
  <xsl:if test="local-name()='sequence'">
    <xsl:text>_builder::</xsl:text>
    <xsl:apply-templates select="parent::sequence" mode="builder_hierarchy"/>
    <xsl:value-of select="translate(@name, $upper, $lower)"/>
    <xsl:text>_builder::</xsl:text>
  </xsl:if>
  <xsl:if test="local-name()='template'">
    <xsl:text>_builder::</xsl:text>
  </xsl:if>
</xsl:template>

<xsl:template name="sequence_builder_hierarchy_parent">
  <xsl:if test="local-name()='sequence'">
    <xsl:text>_builder::</xsl:text>
    <xsl:apply-templates select="parent::sequence" mode="builder_hierarchy"/>
  </xsl:if>
</xsl:template>

<xsl:template name="setter">
  <xsl:choose>
    <xsl:when test="local-name()='sequence'">
      <xsl:text>  static_cast&lt;</xsl:text>
      <xsl:value-of select="$message_name"/>
      <xsl:call-template name="sequence_builder_hierarchy_parent"/>
      <xsl:value-of select="translate(@name, $upper, $lower)"/>
      <xsl:text>_builder*</xsl:text>
      <xsl:text>&gt;&#xa;    (builders_[m::field_id::</xsl:text>
      <xsl:value-of select="length/@name"/>
      <xsl:text>])->register_on_message_callback( std::bind (&#xa;</xsl:text>
      <xsl:text>    &amp;</xsl:text>
      <xsl:choose>
        <xsl:when test="parent::template">
          <xsl:value-of select="$message_name"/>
        </xsl:when>
        <xsl:otherwise>
      <xsl:value-of select="translate(../@name, $upper, $lower)"/>
        </xsl:otherwise>
      </xsl:choose>
      <xsl:text>_builder::add_</xsl:text>
      <xsl:value-of select="@name"/>
      <xsl:text>, this, p::_1 ) );&#xa;</xsl:text>
    </xsl:when>
    <xsl:otherwise>
      <xsl:text>  add_setter( m::field_id::</xsl:text>
      <xsl:value-of select="@name"/>
      <xsl:text>, q::ValueType::</xsl:text>
      <xsl:call-template name="fast_type_name"/>
      <xsl:text>,&#xa;    std::make_shared&lt;setter&lt;</xsl:text>
      <xsl:call-template name="type_name"/>
      <xsl:text>&gt;&gt;(&#xa;    std::bind( &amp;m::</xsl:text>
      <xsl:value-of select="$message_name"/>
      <xsl:call-template name="field_hierarchy"/>
      <xsl:text>::set_</xsl:text>
      <xsl:value-of select="@name"/>
      <xsl:text>, &amp;message_, p::_1),&#xa;</xsl:text>
      <xsl:text>    std::bind( []( q::Messages::FieldCPtr field )&#xa;  {&#xa;</xsl:text>

      <xsl:choose>
        <xsl:when test="local-name()='decimal'">
          <xsl:text>    QuickFAST::Decimal qfd = field->toDecimal();&#xa;</xsl:text>
          <xsl:text>    return decimal( qfd.getMantissa(), qfd.getExponent());&#xa;</xsl:text>
        </xsl:when>

        <xsl:otherwise>
          <xsl:text>    return field-&gt;</xsl:text>
          <xsl:call-template name="getter"/>
        </xsl:otherwise>
      </xsl:choose>

      <xsl:text>;&#xa;  }, p::_1 ) ) );&#xa;</xsl:text>

      <xsl:for-each select="alttype">
        <xsl:text>&#xa;</xsl:text>
        <xsl:text>  add_setter( m::field_id::</xsl:text>
        <xsl:value-of select="../@name"/>
        <xsl:text>, q::ValueType::</xsl:text>
        <xsl:call-template name="fast_alt_type_name"/>
        <xsl:text>,&#xa;    std::make_shared&lt;setter&lt;</xsl:text>
        <xsl:call-template name="parent_type_name"/>
        <xsl:text>&gt;&gt;(&#xa;    std::bind( &amp;m::</xsl:text>
        <xsl:value-of select="$message_name"/>
        <xsl:call-template name="alt_field_hierarchy"/>
        <xsl:text>::set_</xsl:text>
        <xsl:value-of select="../@name"/>
        <xsl:text>, &amp;message_, p::_1),&#xa;</xsl:text>
        <xsl:text>    std::bind( []( q::Messages::FieldCPtr field )&#xa;  {&#xa;</xsl:text>

        <xsl:choose>
          <xsl:when test="@name='string'">
            <xsl:if test="local-name(..)='string'">
              <xsl:text>    return field-&gt;</xsl:text>
              <xsl:call-template name="alt_getter"/>
            </xsl:if>

            <xsl:if test="local-name(..)!='string'">
              <xsl:text>    return boost::lexical_cast&lt;</xsl:text>
              <xsl:call-template name="parent_type_name"/>
              <xsl:text>&gt;( field-&gt;toString() )</xsl:text>
            </xsl:if>
          </xsl:when>

          <xsl:otherwise>
            <xsl:text>    return field-&gt;</xsl:text>
            <xsl:call-template name="alt_getter"/>
          </xsl:otherwise>
        </xsl:choose>

        <xsl:text>;&#xa;  }, p::_1 ) ) );&#xa;</xsl:text>
      </xsl:for-each>
    </xsl:otherwise>
  </xsl:choose>

  <xsl:text>&#xa;</xsl:text>
</xsl:template>

<xsl:template name="startsequence">
  <xsl:text>qm::ValueMessageBuilder&amp;&#xa;</xsl:text>
  <xsl:value-of select="$message_name"/>
  <xsl:call-template name="sequence_builder_hierarchy"/>
  <xsl:text>startSequence( const qm::FieldIdentity&amp; identity,</xsl:text>
  <xsl:text>&#xa;  const std::string&amp; applicationType,</xsl:text>
  <xsl:text>&#xa;  const std::string&amp; applicationTypeNamespace,</xsl:text>
  <xsl:text>&#xa;  size_t fieldCount,</xsl:text>
  <xsl:text>&#xa;  const qm::FieldIdentity&amp; lengthIdentity,</xsl:text>
  <xsl:text>&#xa;  size_t length)&#xa;{&#xa;</xsl:text>

  <xsl:text>  auto builder = builders_.find( lengthIdentity.id() );&#xa;</xsl:text>
  <xsl:text>  if (builder != builders_.end())&#xa;  {    return </xsl:text>
  <xsl:text>*(builder->second);&#xa;  }&#xa;</xsl:text>
  <xsl:text>  else&#xa;  {&#xa;    std::stringstream ss;&#xa;</xsl:text>
  <xsl:text>    ss &lt;&lt; "Unsupported sequence " &lt;&lt; lengthIdentity</xsl:text>
  <xsl:text>.getLocalName() &lt;&lt; "[" &lt;&lt; lengthIdentity.id() </xsl:text>
  <xsl:text>&lt;&lt; "]";&#xa;    throw std::runtime_error( ss.str() );&#xa;</xsl:text>
  <xsl:text>  }&#xa;}&#xa;&#xa;</xsl:text>
</xsl:template>

<xsl:template name="endmessage">
  <xsl:text>bool&#xa;</xsl:text>
  <xsl:value-of select="$message_name"/>
  <xsl:call-template name="sequence_builder_hierarchy"/>
  <xsl:text>endMessage( qm::ValueMessageBuilder&amp;</xsl:text>
  <xsl:text> messageBuilder )&#xa;{&#xa;  if ( on_message_ )&#xa;  {&#xa;</xsl:text>
  <xsl:text>    on_message_( message_ );&#xa;  }&#xa;&#xa;  message_.reset();</xsl:text>
  <xsl:text>&#xa;&#xa;  return true;</xsl:text>
  <xsl:text>&#xa;}&#xa;&#xa;</xsl:text>
</xsl:template>

<xsl:template name="endsequenceentry">
  <xsl:text>void&#xa;</xsl:text>
  <xsl:value-of select="$message_name"/>
  <xsl:call-template name="sequence_builder_hierarchy"/>
  <xsl:text>endSequenceEntry( qm::ValueMessageBuilder&amp;</xsl:text>
  <xsl:text> entry )&#xa;{&#xa;  if ( on_message_ )&#xa;  {&#xa;</xsl:text>
  <xsl:text>    on_message_( message_ );&#xa;  }&#xa;&#xa;  message_.reset();</xsl:text>
  <xsl:text>&#xa;}&#xa;&#xa;</xsl:text>
</xsl:template>

<xsl:template name="class_body">
  <xsl:choose>
    <xsl:when test="local-name()='template'">
      <xsl:value-of select="$message_name"/>
      <xsl:text>_builder::</xsl:text>
      <xsl:value-of select="$message_name"/>
    </xsl:when>
    <xsl:otherwise>
      <xsl:value-of select="$message_name"/>
      <xsl:call-template name="sequence_builder_hierarchy"/>
      <xsl:value-of select="translate(@name, $upper, $lower)"/>
    </xsl:otherwise>
  </xsl:choose>
  <xsl:text>_builder()&#xa;{&#xa;</xsl:text>
  <xsl:text>  namespace m = messages;&#xa;</xsl:text>
  <xsl:text>  namespace q = QuickFAST;&#xa;</xsl:text>
  <xsl:text>  namespace p = std::placeholders;&#xa;</xsl:text>
  <xsl:text>&#xa;</xsl:text>

  <xsl:for-each select="*[(self::sequence)]">
    <xsl:text>  builders_[m::field_id::</xsl:text>
    <xsl:value-of select="length/@name"/>
    <xsl:text>] = &amp;</xsl:text>
    <xsl:value-of select="translate(@name, $upper, $lower)"/>
    <xsl:text>_builder_;</xsl:text>
  </xsl:for-each>
  <xsl:text>&#xa;</xsl:text>

  <xsl:for-each select="*[not(self::length)]">
    <xsl:call-template name="setter"/>
  </xsl:for-each>

  <xsl:text>}&#xa;&#xa;</xsl:text>

  <xsl:text>void&#xa;</xsl:text>
  <xsl:value-of select="$message_name"/>
  <xsl:call-template name="sequence_builder_hierarchy"/>
  <xsl:text>register_on_message_callback( on_message_t callback )</xsl:text>
  <xsl:text>&#xa;{&#xa;  on_message_ = callback;&#xa;}&#xa;&#xa;</xsl:text>

  <xsl:text>const messages::</xsl:text>
  <xsl:value-of select="$message_name"/>
  <xsl:call-template name="sequence_hierarchy"/>
  <xsl:text>&amp;&#xa;</xsl:text>
  <xsl:value-of select="$message_name"/>
  <xsl:call-template name="sequence_builder_hierarchy"/>
  <xsl:text>get_message() const&#xa;{&#xa;  return message_;&#xa;}</xsl:text>
  <xsl:text>&#xa;&#xa;</xsl:text>

  <xsl:if test="sequence">
    <xsl:call-template name="startsequence"/>
  </xsl:if>

  <xsl:choose>
    <xsl:when test="local-name()='template'">
      <xsl:call-template name="endmessage"/>
    </xsl:when>
    <xsl:when test="local-name()='sequence'">
      <xsl:call-template name="endsequenceentry"/>
    </xsl:when>
  </xsl:choose>

  <xsl:for-each select="*[(self::sequence)]">
    <xsl:text>void&#xa;</xsl:text>
    <xsl:value-of select="$message_name"/>
    <xsl:call-template name="sequence_builder_hierarchy_parent"/>
    <xsl:text>add_</xsl:text>
    <xsl:value-of select="@name"/>
    <xsl:text>( const messages::</xsl:text>
    <xsl:value-of select="$message_name"/>
    <xsl:call-template name="sequence_hierarchy"/>
    <xsl:text>&amp; entry )&#xa;{&#xa;  message_.add_</xsl:text>
    <xsl:value-of select="@name"/>
    <xsl:text>( entry );&#xa;}&#xa;&#xa;</xsl:text>

  </xsl:for-each>

</xsl:template>

<xsl:template match="template">
  <xsl:text>#include &lt;msi/umdf/decoder/quickfast/umdf_decoder_quickfast_pch.hpp&gt;
#include &lt;memory&gt;
#include &lt;Common/Types.h&gt;
#include &lt;Messages/Field.h&gt;
#include &lt;msi/umdf/common/typedefs.hpp&gt;
#include &lt;msi/decimal/decimal.hpp&gt;
#include &lt;msi/umdf/messages/field_id.hpp&gt;
#include &lt;msi/umdf/decoder/quickfast/setter_t.hpp&gt;
#include &lt;msi/umdf/decoder/quickfast/</xsl:text>
  <xsl:value-of select="$message_name"/>
  <xsl:text>_builder.hpp&gt;&#xa;&#xa;</xsl:text>

  <xsl:text>namespace apoena&#xa;{&#xa;</xsl:text>
  <xsl:text>namespace msi&#xa;{&#xa;</xsl:text>
  <xsl:text>namespace umdf&#xa;{&#xa;</xsl:text>
  <xsl:text>namespace decoder&#xa;{&#xa;</xsl:text>
  <xsl:text>namespace quickfast&#xa;{&#xa;&#xa;</xsl:text>

  <!--inner classes representing sequences --> 
  <xsl:apply-templates select="sequence" mode="main"/>

  <xsl:call-template name="class_body"/>

  <xsl:text>} //end of namespace&#xa;</xsl:text>
  <xsl:text>} //end of namespace&#xa;</xsl:text>
  <xsl:text>} //end of namespace&#xa;</xsl:text>
  <xsl:text>} //end of namespace&#xa;</xsl:text>
  <xsl:text>} //end of namespace&#xa;</xsl:text>
</xsl:template>

<xsl:template match="sequence" mode="main">
  <!-- nested sequence definitions -->
  <xsl:apply-templates select="sequence" mode="main"/>

  <xsl:call-template name="class_body"/>
</xsl:template>

</xsl:stylesheet>

