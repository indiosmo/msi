<xsl:stylesheet version='1.0'
                xmlns:xsl='http://www.w3.org/1999/XSL/Transform'>

<xsl:output method="text"/>
<xsl:strip-space elements="*"/>

<xsl:variable name="lower" select="'abcdefghijklmnopqrstuvwxyz'" />
<xsl:variable name="upper" select="'ABCDEFGHIJKLMNOPQRSTUVWXYZ'" />

<xsl:param name="message_name" select="message_name"/>

<xsl:variable name="guard">
  <xsl:text>APOENA_MSI_UMDF_DECODER_QUICKFAST_</xsl:text>
  <xsl:value-of select="translate($message_name, $lower, $upper)"/>
  <xsl:text>_BUILDER_HPP</xsl:text>
</xsl:variable>

<xsl:template name="classdef">
  <xsl:param name="class_name"/>
  <xsl:text>class UMDF_DECODER_QUICKFAST_Export </xsl:text>
  <xsl:value-of select="$class_name"/>
  <xsl:text>_builder : public builder&#xa;{&#xa;public:&#xa;&#xa;  </xsl:text>
</xsl:template>

<xsl:variable name="startsequence">
  <xsl:text>  virtual qm::ValueMessageBuilder&amp; startSequence(
    const qm::FieldIdentity&amp; identity,
    const std::string&amp; applicationType,
    const std::string&amp; applicationTypeNamespace,
    size_t fieldCount,
    const qm::FieldIdentity&amp; lengthIdentity,
    size_t length );&#xa;&#xa;</xsl:text>
</xsl:variable>

<xsl:variable name="endmessage">
  <xsl:text>  virtual bool endMessage( qm::ValueMessageBuilder&amp;</xsl:text>
  <xsl:text> messageBuilder );&#xa;&#xa;</xsl:text>
</xsl:variable>

<xsl:variable name="endsequenceentry">
  <xsl:text>  virtual void endSequenceEntry( qm::ValueMessageBuilder&amp;</xsl:text>
  <xsl:text> entry );&#xa;&#xa;</xsl:text>
</xsl:variable>

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

<xsl:template name="class_body">
  <xsl:param name="class_name"/>
  <xsl:value-of select="$class_name"/>
  <xsl:text>_builder();&#xa;&#xa;</xsl:text>
  <xsl:text>  typedef std::function&lt;void( const messages::</xsl:text>
  <xsl:value-of select="$message_name"/>
  <xsl:call-template name="sequence_hierarchy"/>
  <xsl:text>&amp; )&gt; on_message_t;&#xa;&#xa;</xsl:text>
  <xsl:text>  void register_on_message_callback( on_message_t callback );</xsl:text>
  <xsl:text>&#xa;&#xa;</xsl:text>
  <xsl:text>  const messages::</xsl:text>
  <xsl:value-of select="$message_name"/>
  <xsl:call-template name="sequence_hierarchy"/>
  <xsl:text>&amp; get_message() const;&#xa;&#xa;</xsl:text>

  <xsl:if test="sequence">
    <xsl:value-of select="$startsequence"/>
  </xsl:if>

  <xsl:choose>
    <xsl:when test="local-name()='template'">
      <xsl:value-of select="$endmessage"/>
    </xsl:when>
    <xsl:when test="local-name()='sequence'">
      <xsl:value-of select="$endsequenceentry"/>
    </xsl:when>
  </xsl:choose>

  <xsl:text>private:&#xa;</xsl:text>
  <xsl:if test="sequence">
    <xsl:text>  boost::container::flat_map&lt;messages::field_id_t, </xsl:text>
    <xsl:text>builder*&gt; builders_;&#xa;</xsl:text>
  </xsl:if>
  <xsl:text>  on_message_t on_message_;&#xa;</xsl:text>
  <xsl:text>  messages::</xsl:text>
  <xsl:value-of select="$message_name"/>
  <xsl:call-template name="sequence_hierarchy"/>
  <xsl:text> message_;&#xa;  </xsl:text>

  <xsl:for-each select="sequence">
    <xsl:text>  </xsl:text>
    <xsl:value-of select="translate(@name, $upper, $lower)"/>
    <xsl:text>_builder </xsl:text>
    <xsl:value-of select="translate(@name, $upper, $lower)"/>
    <xsl:text>_builder_;&#xa;</xsl:text>
  </xsl:for-each>

  <xsl:text>&#xa;</xsl:text>

  <xsl:for-each select="sequence">
    <xsl:text>  void add_</xsl:text>
    <xsl:value-of select="@name"/>
    <xsl:text>( const messages::</xsl:text>
    <xsl:value-of select="$message_name"/>
    <xsl:call-template name="sequence_hierarchy"/>
    <xsl:text>&amp; entry );&#xa;</xsl:text>
  </xsl:for-each>
  
  <xsl:text>};&#xa;&#xa;</xsl:text>
</xsl:template>

<xsl:template match="template">
  <xsl:text>#ifndef </xsl:text>
  <xsl:value-of select="$guard"/>
  <xsl:text>&#xa;#define </xsl:text>
  <xsl:value-of select="$guard"/>
  <xsl:text>&#xa;&#xa;</xsl:text>
  <xsl:text>#include &lt;functional&gt;&#xa;</xsl:text>
  <xsl:if test="sequence">
    <xsl:text>#include &lt;boost/container/flat_map.hpp&gt;&#xa;</xsl:text>
  </xsl:if>
  <xsl:text>#include &lt;Messages/FieldIdentity.h&gt;&#xa;</xsl:text>
  <xsl:text>#include &lt;msi/umdf/messages/field_id.hpp&gt;&#xa;</xsl:text>
  <xsl:text>#include &lt;msi/umdf/messages/</xsl:text>
  <xsl:value-of select="$message_name"/>
  <xsl:text>.hpp&gt;&#xa;</xsl:text>
  <xsl:text>#include &lt;msi/umdf/decoder/quickfast/</xsl:text>
  <xsl:text>umdf_decoder_quickfast_export.hpp&gt;&#xa;</xsl:text>
  <xsl:text>#include &lt;msi/umdf/decoder/quickfast/builder.hpp&gt;&#xa;</xsl:text>
  <xsl:text>&#xa;</xsl:text>
  <xsl:text>namespace apoena&#xa;{&#xa;</xsl:text>
  <xsl:text>namespace msi&#xa;{&#xa;</xsl:text>
  <xsl:text>namespace umdf&#xa;{&#xa;</xsl:text>
  <xsl:text>namespace decoder&#xa;{&#xa;</xsl:text>
  <xsl:text>namespace quickfast&#xa;{&#xa;&#xa;</xsl:text>

  <xsl:call-template name="classdef">
    <xsl:with-param name="class_name" select="$message_name"/>
  </xsl:call-template>

  <!--inner classes representing sequences --> 
  <xsl:apply-templates select="sequence" mode="main"/>

  <xsl:call-template name="class_body">
    <xsl:with-param name="class_name" select="$message_name"/>
  </xsl:call-template>

  <xsl:text>} //end of namespace&#xa;</xsl:text>
  <xsl:text>} //end of namespace&#xa;</xsl:text>
  <xsl:text>} //end of namespace&#xa;</xsl:text>
  <xsl:text>} //end of namespace&#xa;</xsl:text>
  <xsl:text>} //end of namespace&#xa;</xsl:text>

  <xsl:text>&#xa;#endif /* </xsl:text>
  <xsl:value-of select="$guard"/>
  <xsl:text> */&#xa;&#xa;</xsl:text> 
</xsl:template>

<xsl:template match="sequence" mode="main">
  <xsl:call-template name="classdef">
    <xsl:with-param name="class_name" select="translate(@name,$upper, $lower)"/>
  </xsl:call-template>

  <!-- nested sequence definitions -->
  <xsl:apply-templates select="sequence" mode="main"/>
  <xsl:call-template name="class_body">
    <xsl:with-param name="class_name" select="translate(@name,$upper, $lower)"/>
  </xsl:call-template>
</xsl:template>

</xsl:stylesheet>

