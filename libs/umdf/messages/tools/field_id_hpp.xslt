<xsl:stylesheet version="1.0"
                xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:output method="text"/>
<xsl:strip-space elements="*"/>

<xsl:key name="key" match="//*" use="@name"/>

<xsl:template match="/">
  <xsl:text>//Generated with libs/umdf/messages/tools/generate_field_ids.[bat/sh]
#ifndef APOENA_MSI_UMDF_MESSAGES_FIELD_ID_HPP
#define APOENA_MSI_UMDF_MESSAGES_FIELD_ID_HPP

#include &lt;string&gt;
#include &lt;msi/umdf/messages/umdf_messages_export.hpp&gt;

namespace apoena
{
namespace msi
{
namespace umdf
{
namespace messages
{

typedef std::string field_id_t;

class UMDF_MESSAGES_Export field_id
{
public:
</xsl:text>

  <xsl:for-each select="//*[generate-id() = generate-id(key('key', @name)[1])]">
    <xsl:text>  static const field_id_t </xsl:text>
    <xsl:value-of select="@name"/>
    <xsl:text>;&#xa;</xsl:text>
  </xsl:for-each>

<xsl:text>};

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_UMDF_MESSAGES_FIELD_ID_HPP */

</xsl:text>

</xsl:template>

</xsl:stylesheet>
