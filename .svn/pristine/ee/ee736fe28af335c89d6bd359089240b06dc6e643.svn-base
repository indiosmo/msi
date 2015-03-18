<xsl:stylesheet version='1.0'
                xmlns:xsl='http://www.w3.org/1999/XSL/Transform'>

<xsl:output method="text"/>
<xsl:strip-space elements="*"/>

<xsl:variable name="lowercase" select="'abcdefghijklmnopqrstuvwxyz'" />
<xsl:variable name="uppercase" select="'ABCDEFGHIJKLMNOPQRSTUVWXYZ'" />

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
      <xsl:value-of select="translate(@name, $uppercase, $lowercase)"/>
      <xsl:text>&gt;</xsl:text>
    </xsl:when>
  </xsl:choose>
</xsl:template>

<xsl:template match="sequence" mode="hierarchy">
  <xsl:apply-templates select="parent::sequence" mode="hierarchy"/>

  <xsl:text>::</xsl:text>
  <xsl:value-of select="translate(@name, $uppercase, $lowercase)"/>
</xsl:template>

<xsl:template name="reset">
  <xsl:text>void&#xa;</xsl:text>
  <xsl:value-of select="$message_name"/>
  <xsl:if test="local-name()='sequence'">
    <xsl:apply-templates select="parent::sequence" mode="hierarchy"/>
    <xsl:text>::</xsl:text>
    <xsl:value-of select="translate(@name, $uppercase, $lowercase)"/>
  </xsl:if>
  <xsl:text>::reset()&#xa;{&#xa;  presence_map_.reset();&#xa;</xsl:text>
  <xsl:for-each select="sequence">
    <xsl:text>  </xsl:text>
    <xsl:value-of select="@name"/>
    <xsl:text>_.clear();&#xa;</xsl:text>
  </xsl:for-each>
  <xsl:text>}&#xa;&#xa;</xsl:text>
</xsl:template>

<xsl:template name="class_body">
  <xsl:call-template name="reset"/>

  <xsl:for-each select="*[not(self::length)]">
    <xsl:choose>
      <xsl:when test="local-name()='sequence'">
        <xsl:text>const std::vector&lt;</xsl:text>
        <xsl:value-of select="$message_name"/>
        <xsl:apply-templates select="parent::sequence" mode="hierarchy"/>
        <xsl:text>::</xsl:text>
        <xsl:value-of select="translate(@name, $uppercase, $lowercase)"/>
        <xsl:text>&gt;&amp;&#xa;</xsl:text>
        <xsl:value-of select="$message_name"/>
        <xsl:apply-templates select="parent::sequence" mode="hierarchy"/>
        <xsl:text>::</xsl:text>
        <xsl:value-of select="@name"/>
        <xsl:text>() const&#xa;{&#xa;  return </xsl:text>
        <xsl:value-of select="@name"/>
        <xsl:text>_;&#xa;}&#xa;&#xa;</xsl:text>

        <xsl:text>void&#xa;</xsl:text>
        <xsl:value-of select="$message_name"/>
        <xsl:apply-templates select="parent::sequence" mode="hierarchy"/>
        <xsl:text>::add_</xsl:text>
        <xsl:value-of select="@name"/>
        <xsl:text>( const </xsl:text>
        <xsl:value-of select="translate(@name, $uppercase, $lowercase)"/>
        <xsl:text>&amp; val )&#xa;{&#xa;  </xsl:text>
        <xsl:value-of select="@name"/>
        <xsl:text>_.push_back( val );&#xa;}&#xa;&#xa;</xsl:text>

      </xsl:when>
      <xsl:otherwise>
        <xsl:text>std::pair&lt;bool, </xsl:text>
        <xsl:if test="local-name()='string'">
          <xsl:text>const </xsl:text>
        </xsl:if>
        <xsl:call-template name="type_name"/>
        <xsl:if test="local-name()='string'">
          <xsl:text>&amp;</xsl:text>
        </xsl:if>
        <xsl:text>&gt;&#xa;</xsl:text>
        <xsl:value-of select="$message_name"/>
        <xsl:apply-templates select="parent::sequence" mode="hierarchy"/>
        <xsl:text>::</xsl:text>
        <xsl:value-of select="@name"/>
        <xsl:text>() const&#xa;{&#xa;</xsl:text>
        <xsl:text>  return std::pair&lt;bool, </xsl:text>
        <xsl:if test="local-name()='string'">
          <xsl:text>const </xsl:text>
        </xsl:if>
        <xsl:call-template name="type_name"/>
        <xsl:if test="local-name()='string'">
          <xsl:text>&amp;</xsl:text>
        </xsl:if>
        <xsl:text>&gt;( presence_map_[ix_</xsl:text>
        <xsl:value-of select="@name"/>
        <xsl:text>], </xsl:text>
        <xsl:value-of select="@name"/>
        <xsl:text>_ );&#xa;}&#xa;&#xa;</xsl:text>

        <xsl:text>void&#xa;</xsl:text>
        <xsl:value-of select="$message_name"/>
        <xsl:apply-templates select="parent::sequence" mode="hierarchy"/>
        <xsl:text>::set_</xsl:text>
        <xsl:value-of select="@name"/>
        <xsl:text>( </xsl:text>
        <xsl:if test="local-name()='string'">
          <xsl:text>const </xsl:text>
        </xsl:if>
        <xsl:call-template name="type_name"/>
        <xsl:if test="local-name()='string'">
          <xsl:text>&amp;</xsl:text>
        </xsl:if>
        <xsl:text> val )&#xa;{&#xa;  </xsl:text>
        <xsl:value-of select="@name"/>
        <xsl:text>_ = val;&#xa;  presence_map_[ix_</xsl:text>
        <xsl:value-of select="@name"/>
        <xsl:text>] = true;&#xa;}&#xa;&#xa;</xsl:text>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:for-each>
</xsl:template>

<xsl:template match="template">
  <xsl:text>#include &lt;msi/msi_pch.hpp&gt;&#xa;</xsl:text>
  <xsl:text>#include &lt;msi/umdf/messages/</xsl:text>
  <xsl:value-of select="$message_name"/>
  <xsl:text>.hpp&gt;&#xa;</xsl:text>
  <xsl:text>&#xa;</xsl:text>
  <xsl:text>namespace apoena&#xa;{&#xa;</xsl:text>
  <xsl:text>namespace msi&#xa;{&#xa;</xsl:text>
  <xsl:text>namespace umdf&#xa;{&#xa;</xsl:text>
  <xsl:text>namespace messages&#xa;{&#xa;&#xa;</xsl:text>


  <!--inner classes representing sequences --> 
  <xsl:apply-templates select="sequence" mode="main"/>

  <xsl:call-template name="class_body"/>

  <xsl:text>&#xa;&#xa;</xsl:text>
  <xsl:text>} //end of namespace&#xa;</xsl:text>
  <xsl:text>} //end of namespace&#xa;</xsl:text>
  <xsl:text>} //end of namespace&#xa;</xsl:text>
  <xsl:text>} //end of namespace&#xa;&#xa;</xsl:text>
</xsl:template>

<xsl:template match="sequence" mode="main">
  <!-- nested sequence definitions -->
  <xsl:apply-templates select="sequence" mode="main"/>

  <xsl:call-template name="class_body"/>
</xsl:template>

</xsl:stylesheet>
