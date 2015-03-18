<xsl:stylesheet version='1.0'
              xmlns:xsl='http://www.w3.org/1999/XSL/Transform'>

  <xsl:output method="text"/>
  <xsl:strip-space elements="*"/>

  <xsl:template match="templates">
    <xsl:text>#ifndef APOENA_MSI_MARKETDATA_MESSAGES_MESSAGE_TYPES_HPP&#xa;</xsl:text>
    <xsl:text>#define APOENA_MSI_MARKETDATA_MESSAGES_MESSAGE_TYPES_HPP&#xa;</xsl:text>
    <xsl:text>&#xa;</xsl:text>

    <xsl:text>namespace apoena&#xa;{&#xa;</xsl:text>
    <xsl:text>namespace msi&#xa;{&#xa;</xsl:text>
    <xsl:text>namespace marketdata&#xa;{&#xa;</xsl:text>
    <xsl:text>namespace messages&#xa;{&#xa;&#xa;</xsl:text>

    <xsl:text>enum message_type&#xa;{&#xa;</xsl:text>

    <xsl:for-each select="template">
      <xsl:text>  message_</xsl:text>
      <xsl:value-of select="@name"/>
      <xsl:if test="position()=1">
        <xsl:text> = 0</xsl:text>
      </xsl:if>
      <xsl:if test="position()!=last()">
        <xsl:text>,</xsl:text>
      </xsl:if>
      <xsl:text>&#xa;</xsl:text>
    </xsl:for-each>

    <xsl:text>};&#xa;&#xa;</xsl:text>

    <xsl:text>} //end of namespace&#xa;</xsl:text>
    <xsl:text>} //end of namespace&#xa;</xsl:text>
    <xsl:text>} //end of namespace&#xa;</xsl:text>
    <xsl:text>} //end of namespace&#xa;</xsl:text>

    <xsl:text>&#xa;</xsl:text>
    <xsl:text>#endif /* APOENA_MSI_MARKETDATA_MESSAGES_MESSAGE_TYPES_HPP */</xsl:text>
    <xsl:text>&#xa;&#xa;</xsl:text> 
  </xsl:template>

</xsl:stylesheet>
