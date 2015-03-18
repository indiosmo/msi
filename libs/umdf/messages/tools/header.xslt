<xsl:stylesheet version='1.0'
                xmlns:xsl='http://www.w3.org/1999/XSL/Transform'>

<xsl:output method="text"/>
<xsl:strip-space elements="*"/>

<xsl:variable name="lowercase" select="'abcdefghijklmnopqrstuvwxyz'" />
<xsl:variable name="uppercase" select="'ABCDEFGHIJKLMNOPQRSTUVWXYZ'" />

<xsl:param name="message_name" select="message_name"/>

<xsl:variable name="guard">
  <xsl:text>APOENA_MSI_UMDF_MESSAGES_</xsl:text>
  <xsl:value-of select="translate($message_name, $lowercase, $uppercase)"/>
  <xsl:text>_HPP</xsl:text>
</xsl:variable>

<xsl:template name="classdef">
  <xsl:param name="class_name"/>
  <xsl:text>class UMDF_MESSAGES_Export </xsl:text>
  <xsl:value-of select="$class_name"/>
  <xsl:text>&#xa;{&#xa;public:&#xa;&#xa;</xsl:text>
</xsl:template>

<xsl:template name="field_enum">
  <xsl:text>  enum field_index&#xa;  {&#xa;</xsl:text>
  <xsl:for-each select="*[not(self::length)]">
    <xsl:text>    ix_</xsl:text>
    <xsl:value-of select="@name"/>
    <xsl:if test="position()=1">
      <xsl:text> = 0</xsl:text>
    </xsl:if>

    <xsl:text>,&#xa;</xsl:text>
  </xsl:for-each>

  <xsl:text>    ix_field_count&#xa;</xsl:text>
  <xsl:text>  };&#xa;&#xa;</xsl:text>
</xsl:template>

<xsl:template name="reset">
  <xsl:text>  void reset();</xsl:text>
  <xsl:text>&#xa;</xsl:text>
  <xsl:text>&#xa;</xsl:text>
</xsl:template>

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
      <xsl:value-of select="translate(@name, $uppercase, $lowercase)"/>
      <xsl:text>&gt;</xsl:text>
    </xsl:when>
  </xsl:choose>
</xsl:template>

<xsl:template name="class_body">
  <xsl:for-each select="*[not(self::length)]">
    <xsl:choose>
      <xsl:when test="local-name()='sequence'">
        <xsl:text>  const std::vector&lt;</xsl:text>
        <xsl:value-of select="translate(@name, $uppercase, $lowercase)"/>
        <xsl:text>&gt;&amp; </xsl:text>
        <xsl:value-of select="@name"/>
        <xsl:text>() const;&#xa;</xsl:text>

        <xsl:text>  void add_</xsl:text>
        <xsl:value-of select="@name"/>
        <xsl:text>( const </xsl:text>
        <xsl:value-of select="translate(@name, $uppercase, $lowercase)"/>
        <xsl:text>&amp; val );&#xa;&#xa;</xsl:text>
      </xsl:when>
      <xsl:otherwise>
        <xsl:text>  std::pair&lt;bool, </xsl:text>

        <xsl:if test="local-name()='string'">
          <xsl:text>const </xsl:text>
        </xsl:if>
        <xsl:call-template name="type_name"/>
        <xsl:if test="local-name()='string'">
          <xsl:text>&amp;</xsl:text>
        </xsl:if>
        <xsl:text>&gt; </xsl:text>

        <xsl:value-of select="@name"/>
        <xsl:text>() const;&#xa;</xsl:text>
        <xsl:text>  void set_</xsl:text>
        <xsl:value-of select="@name"/>
        <xsl:text>( </xsl:text>
        <xsl:if test="local-name()='string'">
          <xsl:text>const </xsl:text>
        </xsl:if>
        <xsl:call-template name="type_name"/>
        <xsl:if test="local-name()='string'">
          <xsl:text>&amp;</xsl:text>
        </xsl:if>

        <xsl:text> val );&#xa;&#xa;</xsl:text>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:for-each>

  <xsl:text>private:&#xa;</xsl:text>
  <xsl:text>  std::bitset&lt;ix_field_count&gt; presence_map_;&#xa;&#xa;</xsl:text>

  <xsl:for-each select="*[not(self::length)]">
    <xsl:text>  </xsl:text>
    <xsl:call-template name="type_name"/>
    <xsl:text> </xsl:text>
    <xsl:value-of select="@name"/>
    <xsl:text>_;&#xa;</xsl:text>
  </xsl:for-each>
</xsl:template>

<xsl:template match="template">
  <xsl:text>#ifndef </xsl:text>
  <xsl:value-of select="$guard"/>
  <xsl:text>&#xa;#define </xsl:text>
  <xsl:value-of select="$guard"/>
  <xsl:text>&#xa;&#xa;</xsl:text>
  <xsl:text>#include &lt;bitset&gt;&#xa;</xsl:text>
  <xsl:text>#include &lt;utility&gt;&#xa;</xsl:text>
  <xsl:text>#include &lt;vector&gt;&#xa;</xsl:text>
  <xsl:text>#include &lt;msi/decimal/decimal.hpp&gt;&#xa;</xsl:text>
  <xsl:text>#include &lt;msi/umdf/messages/umdf_messages_export.hpp&gt;&#xa;</xsl:text>
  <xsl:text>#include &lt;msi/umdf/common/typedefs.hpp&gt;&#xa;</xsl:text>
  <xsl:text>&#xa;</xsl:text>
  <xsl:text>namespace apoena&#xa;{&#xa;</xsl:text>
  <xsl:text>namespace msi&#xa;{&#xa;</xsl:text>
  <xsl:text>namespace umdf&#xa;{&#xa;</xsl:text>
  <xsl:text>namespace messages&#xa;{&#xa;&#xa;</xsl:text>

  <xsl:call-template name="classdef">
    <xsl:with-param name="class_name" select="$message_name"/>
  </xsl:call-template>

  <!--inner classes representing sequences --> 
  <xsl:apply-templates select="sequence"/>

  <xsl:call-template name="field_enum"/>
  <xsl:call-template name="reset"/>
  <xsl:call-template name="class_body"/>

  <xsl:text>&#xa;};&#xa;&#xa;</xsl:text>
  <xsl:text>} //end of namespace&#xa;</xsl:text>
  <xsl:text>} //end of namespace&#xa;</xsl:text>
  <xsl:text>} //end of namespace&#xa;</xsl:text>
  <xsl:text>} //end of namespace&#xa;</xsl:text>

  <xsl:text>&#xa;#endif /* </xsl:text>
  <xsl:value-of select="$guard"/>
  <xsl:text> */&#xa;&#xa;</xsl:text> 
</xsl:template>

<xsl:template match="sequence">
  <xsl:call-template name="classdef">
    <xsl:with-param name="class_name" select="translate(@name, $uppercase, $lowercase)"/>
  </xsl:call-template>

  <!-- nested sequence definitions -->
  <xsl:apply-templates select="sequence"/>

  <xsl:call-template name="field_enum"/>
  <xsl:call-template name="reset"/>
  <xsl:call-template name="class_body"/>

  <xsl:text>&#xa;};&#xa;&#xa;</xsl:text>
</xsl:template>

</xsl:stylesheet>
