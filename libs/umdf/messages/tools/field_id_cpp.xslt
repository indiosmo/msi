<xsl:stylesheet version="1.0"
                xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:output method="text"/>
<xsl:strip-space elements="*"/>

<xsl:key name="key" match="//*" use="@name"/>

<xsl:template match="/">
  <xsl:text>//Generated with libs/umdf/messages/tools/generate_field_ids.[bat/sh]
#include &lt;msi/msi_pch.hpp&gt;
#include &lt;msi/umdf/messages/field_id.hpp&gt;

namespace apoena
{
namespace msi
{
namespace umdf
{
namespace messages
{

</xsl:text>

  <xsl:for-each select="//*[generate-id() = generate-id(key('key', @name)[1])]">
    <xsl:text>const field_id_t field_id::</xsl:text>
    <xsl:value-of select="@name"/>
    <xsl:text> = "</xsl:text>
    <xsl:value-of select="@id"/>
    <xsl:text>";&#xa;</xsl:text>
  </xsl:for-each>

  <xsl:text>
} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

</xsl:text>

</xsl:template>

</xsl:stylesheet>
