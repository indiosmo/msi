<xsl:stylesheet version="1.0"
                xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:output method="text"/>
<xsl:strip-space elements="*"/>

<xsl:template match="/">
  <xsl:text>&lt;?xml version="1.0"?&gt;&#xa;</xsl:text>
  <xsl:text>&lt;fields&gt;&#xa;</xsl:text>
  <xsl:apply-templates/>
  <xsl:text>&lt;/fields&gt;&#xa;</xsl:text>
</xsl:template>

<xsl:template match="//*[@id and local-name()!='template']">
  <xsl:text>  &lt;</xsl:text>
  <xsl:value-of select="@name"/>
  <xsl:text> name="</xsl:text>
  <xsl:value-of select="@name"/>
  <xsl:text>" id="</xsl:text>
  <xsl:value-of select="@id"/>
  <xsl:text>"/&gt;&#xa;</xsl:text>

  <xsl:apply-templates/>
</xsl:template>

</xsl:stylesheet>
