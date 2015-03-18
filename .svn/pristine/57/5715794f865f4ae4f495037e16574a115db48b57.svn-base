<xsl:stylesheet version='1.0'
              xmlns:xsl='http://www.w3.org/1999/XSL/Transform'>

  <xsl:output method="text"/>
  <xsl:strip-space elements="*"/>

  <xsl:template name="type_name">
    <xsl:variable name="field_type" select="../@type"/>
    <xsl:choose>
      <xsl:when test="$field_type='uint32'">
        <xsl:text>uint32_t</xsl:text>
      </xsl:when>
      <xsl:when test="$field_type='uint64'">
        <xsl:text>uint64_t</xsl:text>
      </xsl:when>
      <xsl:when test="$field_type='int32'">
        <xsl:text>int32_t</xsl:text>
      </xsl:when>
      <xsl:when test="$field_type='int64'">
        <xsl:text>int64_t</xsl:text>
      </xsl:when>
      <xsl:when test="$field_type='decimal'">
        <xsl:text>decimal</xsl:text>
      </xsl:when>
      <xsl:when test="$field_type='string'">
        <xsl:text>char* const</xsl:text>
      </xsl:when>
    </xsl:choose>
  </xsl:template>


  <xsl:template match="fields">
    <xsl:text>#ifndef APOENA_MSI_MARKETDATA_MESSAGES_FIELD_VALUES_HPP&#xa;</xsl:text>
    <xsl:text>#define APOENA_MSI_MARKETDATA_MESSAGES_FIELD_VALUES_HPP&#xa;</xsl:text>
    <xsl:text>&#xa;</xsl:text>
    <xsl:text>#include &lt;cstdint&gt;&#xa;</xsl:text>
    <xsl:text>#include &lt;map&gt;&#xa;</xsl:text>
    <xsl:text>&#xa;</xsl:text>

    <xsl:text>namespace apoena&#xa;{&#xa;</xsl:text>
    <xsl:text>namespace msi&#xa;{&#xa;</xsl:text>
    <xsl:text>namespace marketdata&#xa;{&#xa;</xsl:text>
    <xsl:text>namespace messages&#xa;{&#xa;&#xa;</xsl:text>

    <xsl:for-each select="field[value]">
      <xsl:choose>
        <xsl:when test="@type='multistring'">
          <xsl:text>enum </xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>_value_index&#xa;{&#xa;</xsl:text>

          <xsl:for-each select="value">
            <xsl:text>  ix_</xsl:text>
            <xsl:value-of select="../@name"/>
            <xsl:text>_</xsl:text>
            <xsl:value-of select="@name"/>
            <xsl:if test="position()=1">
              <xsl:text> = 0</xsl:text>
            </xsl:if>

            <xsl:text>,&#xa;</xsl:text>
          </xsl:for-each>

          <xsl:text>  </xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>_field_count&#xa;};&#xa;&#xa;</xsl:text>

          <xsl:text>const std::map&lt;std::string, </xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>_value_index&gt; </xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>_value_index_map = {&#xa;</xsl:text>

          <xsl:for-each select="value">
            <xsl:text>  { "</xsl:text>
            <xsl:value-of select="@value"/>
            <xsl:text>", ix_</xsl:text>
            <xsl:value-of select="../@name"/>
            <xsl:text>_</xsl:text>
            <xsl:value-of select="@name"/>
            <xsl:text> }</xsl:text>
            <xsl:if test="position()!=last()">
              <xsl:text>,</xsl:text>
            </xsl:if>
            <xsl:text>&#xa;</xsl:text>
          </xsl:for-each>

          <xsl:text>};&#xa;&#xa;</xsl:text>
        </xsl:when>

        <xsl:otherwise>
          <xsl:for-each select="value">
            <xsl:text>const </xsl:text>
            <xsl:call-template name="type_name"/>
            <xsl:text> </xsl:text>
            <xsl:value-of select="../@name"/>
            <xsl:text>_</xsl:text>
            <xsl:value-of select="@name"/>
            <xsl:text> = </xsl:text>
            <xsl:if test="../@type='string'">
              <xsl:text>"</xsl:text>
            </xsl:if>
            <xsl:value-of select="@value"/>
            <xsl:if test="../@type='string'">
              <xsl:text>"</xsl:text>
            </xsl:if>
            <xsl:text>;&#xa;</xsl:text>
          </xsl:for-each>

          <xsl:text>&#xa;</xsl:text>
        </xsl:otherwise>
      </xsl:choose>
    </xsl:for-each>

    <xsl:text>} //end of namespace&#xa;</xsl:text>
    <xsl:text>} //end of namespace&#xa;</xsl:text>
    <xsl:text>} //end of namespace&#xa;</xsl:text>
    <xsl:text>} //end of namespace&#xa;</xsl:text>

    <xsl:text>&#xa;</xsl:text>
    <xsl:text>#endif /* APOENA_MSI_MARKETDATA_MESSAGES_FIELD_VALUES_HPP */</xsl:text>
    <xsl:text>&#xa;&#xa;</xsl:text> 
  </xsl:template>

</xsl:stylesheet>
