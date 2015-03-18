<xsl:stylesheet version='1.0'
              xmlns:xsl='http://www.w3.org/1999/XSL/Transform'>

  <xsl:output method="text"/>
  <xsl:strip-space elements="*"/>

  <xsl:variable name="lowercase" select="'abcdefghijklmnopqrstuvwxyz'" />
  <xsl:variable name="uppercase" select="'ABCDEFGHIJKLMNOPQRSTUVWXYZ'" />

  <xsl:template match="sequence" mode="hierarchy">
    <xsl:apply-templates select="parent::sequence" mode="hierarchy"/>

    <xsl:text>::</xsl:text>
    <xsl:value-of select="translate(@name, $uppercase, $lowercase)"/>
    <xsl:if test="local-name()='sequence'">
      <xsl:text>_entry</xsl:text>
    </xsl:if>
  </xsl:template>

  <xsl:template match="templates">
    <xsl:text>#include &lt;msi/msi_pch.hpp&gt;&#xa;</xsl:text>
    <xsl:text>#define BOOST_TEST_NO_MAIN marketdata_serialization_test&#xa;</xsl:text>
    <xsl:text>#include &lt;boost/test/unit_test.hpp&gt;&#xa;</xsl:text>
    <xsl:text>&#xa;</xsl:text>

    <xsl:text>#include &lt;msi/decimal/decimal.hpp&gt;&#xa;</xsl:text>

    <xsl:for-each select="template">
      <xsl:text>#include &lt;msi/marketdata/serialization/</xsl:text>
      <xsl:value-of select="@name"/>
      <xsl:text>_serializer.hpp&gt;&#xa;</xsl:text>
    </xsl:for-each>

    <xsl:text>&#xa;</xsl:text>
    <xsl:text>namespace&#xa;{&#xa;</xsl:text>
    <xsl:text>using namespace apoena::msi;&#xa;</xsl:text>
    <xsl:text>using namespace apoena::msi::marketdata::messages;&#xa;</xsl:text>
    <xsl:text>using namespace apoena::msi::marketdata::serialization;&#xa;</xsl:text>
    <xsl:text>}&#xa;&#xa;</xsl:text>

    <xsl:text>BOOST_AUTO_TEST_SUITE( suite_marketdata_serialization )</xsl:text>
    <xsl:text>&#xa;&#xa;</xsl:text>

    <xsl:apply-templates select="template" mode="main"/>

    <xsl:text>BOOST_AUTO_TEST_SUITE_END()&#xa;&#xa;</xsl:text>
  </xsl:template>

  <xsl:template match="template" mode="nested_set_fields">
    <xsl:variable name="nested_name">
      <xsl:value-of select="@name"/>
      <xsl:text>_entry</xsl:text>
    </xsl:variable>
    <xsl:call-template name="set_fields">
      <xsl:with-param name="target" select="$nested_name"/>
    </xsl:call-template>
  </xsl:template>

  <xsl:template name="set_fields">
    <xsl:param name="target"/>

    <xsl:for-each select="field">
      <xsl:variable name="field_name" select="@name"/>
      <xsl:variable name="field_type" select="//fields/field[@name=$field_name]/@type"/>

      <xsl:if test="./@ref">
        <xsl:text>  </xsl:text>
        <xsl:value-of select="@name"/>
        <xsl:text> </xsl:text>
        <xsl:value-of select="@name"/>
        <xsl:text>_entry;&#xa;</xsl:text>
        <xsl:apply-templates select="//template[@name=$field_name]" mode="nested_set_fields"/>
      </xsl:if>

      <xsl:choose>
        <xsl:when test="@ref='multiple'">
          <xsl:text>  </xsl:text>
          <xsl:value-of select="$target"/>
          <xsl:text>.add_</xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>( </xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>_entry</xsl:text>
          <xsl:text> );&#xa;</xsl:text>

          <xsl:text>  </xsl:text>
          <xsl:value-of select="$target"/>
          <xsl:text>.add_</xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>( </xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>_entry</xsl:text>
          <xsl:text> );&#xa;&#xa;</xsl:text>
        </xsl:when>

        <xsl:otherwise>
          <xsl:text>  </xsl:text>
          <xsl:value-of select="$target"/>
          <xsl:text>.set_</xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>( </xsl:text>

          <xsl:choose>
            <xsl:when test="@ref='single'">
              <xsl:value-of select="@name"/>
              <xsl:text>_entry</xsl:text>
            </xsl:when>

            <xsl:when test="$field_type='string'">
              <xsl:text>"</xsl:text>
              <xsl:value-of select="position()"/>
              <xsl:text>"</xsl:text>
            </xsl:when>

            <xsl:when test="$field_type='multistring'">
              <xsl:text>"</xsl:text>

              <xsl:for-each select="//fields/field[@name=$field_name]/value">
                <xsl:value-of select="@value"/>
                <xsl:if test="position()!=last()">
                  <xsl:text> </xsl:text>
                </xsl:if>
              </xsl:for-each>

              <xsl:text>"</xsl:text>
            </xsl:when>

            <xsl:when test="$field_type='decimal'">
              <xsl:text>decimal( </xsl:text>
              <xsl:value-of select="position()"/>
              <xsl:text>, 0 )</xsl:text>
            </xsl:when>

            <xsl:otherwise>
              <xsl:value-of select="position()"/>
            </xsl:otherwise>
          </xsl:choose>
          
          <xsl:text> );&#xa;</xsl:text>

          <xsl:if test="@ref='single'">
            <xsl:text>&#xa;</xsl:text>
          </xsl:if>
        </xsl:otherwise>
      </xsl:choose>

    </xsl:for-each>

    <xsl:text>&#xa;</xsl:text>
  </xsl:template>

  <xsl:template match="template" mode="nested_test_fields">
    <xsl:variable name="nested_name">
      <xsl:value-of select="@name"/>
    </xsl:variable>
    <xsl:call-template name="test_fields">
      <xsl:with-param name="target" select="$nested_name"/>
    </xsl:call-template>
  </xsl:template>

  <xsl:template name="test_fields">
    <xsl:param name="target"/>

    <xsl:for-each select="field">
      <xsl:variable name="field_name" select="@name"/>
      <xsl:variable name="field_type" select="//fields/field[@name=$field_name]/@type"/>

      <xsl:choose>
        <xsl:when test="@ref='single'">
          <xsl:text>  BOOST_CHECK( d</xsl:text>
          <xsl:value-of select="$target"/>
          <xsl:text>.</xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>().first );&#xa;</xsl:text>

          <xsl:text>  auto </xsl:text>
          <xsl:text>d</xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text> = d</xsl:text>
          <xsl:value-of select="$target"/>
          <xsl:text>.</xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>().second;&#xa;</xsl:text>

          <xsl:apply-templates select="//template[@name=$field_name]" mode="nested_test_fields"/>
        </xsl:when>

        <xsl:when test="@ref='multiple'">
          <xsl:text>  BOOST_REQUIRE_EQUAL( d</xsl:text>
          <xsl:value-of select="$target"/>
          <xsl:text>.</xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>s().size(), 2 );&#xa;</xsl:text>

          <xsl:text>  auto </xsl:text>
          <xsl:text>d</xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text> = d</xsl:text>
          <xsl:value-of select="$target"/>
          <xsl:text>.</xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>s()[0];&#xa;</xsl:text>
          <xsl:apply-templates select="//template[@name=$field_name]" mode="nested_test_fields"/>

          <xsl:text>  d</xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text> = d</xsl:text>
          <xsl:value-of select="$target"/>
          <xsl:text>.</xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>s()[1];&#xa;</xsl:text>
          <xsl:apply-templates select="//template[@name=$field_name]" mode="nested_test_fields"/>
        </xsl:when>

        <xsl:when test="$field_type='multistring'">
          <xsl:for-each select="//fields/field[@name=$field_name]/value">
            <xsl:text>  BOOST_CHECK( d</xsl:text>
            <xsl:value-of select="$target"/>
            <xsl:text>.</xsl:text>
            <xsl:value-of select="../@name"/>
            <xsl:text>_</xsl:text>
            <xsl:value-of select="@name"/>
            <xsl:text>() );&#xa;</xsl:text>
          </xsl:for-each>
        </xsl:when>

        <xsl:otherwise>
          <xsl:text>  BOOST_CHECK( d</xsl:text>
          <xsl:value-of select="$target"/>
          <xsl:text>.</xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>().first );&#xa;</xsl:text>

          <xsl:text>  BOOST_CHECK_EQUAL( d</xsl:text>
          <xsl:value-of select="$target"/>
          <xsl:text>.</xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>().second, </xsl:text>

          <xsl:choose>
            <xsl:when test="$field_type='string'">
              <xsl:text>"</xsl:text>
              <xsl:value-of select="position()"/>
              <xsl:text>"</xsl:text>
            </xsl:when>

            <xsl:when test="$field_type='decimal'">
              <xsl:text>decimal( </xsl:text>
              <xsl:value-of select="position()"/>
              <xsl:text>, 0 )</xsl:text>
            </xsl:when>

            <xsl:otherwise>
              <xsl:value-of select="position()"/>
            </xsl:otherwise>
          </xsl:choose>

          <xsl:text> );&#xa;</xsl:text>
        </xsl:otherwise>
      </xsl:choose>
    </xsl:for-each>

  </xsl:template>

  <xsl:template match="template" mode="main">
    <xsl:text>BOOST_AUTO_TEST_CASE( test_</xsl:text>
    <xsl:value-of select="@name"/>
    <xsl:text> )&#xa;{&#xa;  </xsl:text>

    <xsl:value-of select="@name"/>
    <xsl:text>_serializer serializer;&#xa;&#xa;  </xsl:text>

    <xsl:value-of select="@name"/>
    <xsl:text> msg;&#xa;&#xa;</xsl:text>

    <xsl:apply-templates select="sequence" mode="main"/>

    <xsl:call-template name="set_fields">
      <xsl:with-param name="target" select="'msg'"/>
    </xsl:call-template>

    <xsl:for-each select="sequence">
      <xsl:text>  msg.add_</xsl:text>
      <xsl:value-of select="@name"/>
      <xsl:text>( </xsl:text>
      <xsl:value-of select="@name"/>
      <xsl:text> );&#xa;</xsl:text>

      <xsl:text>  msg.add_</xsl:text>
      <xsl:value-of select="@name"/>
      <xsl:text>( </xsl:text>
      <xsl:value-of select="@name"/>
      <xsl:text>2 );&#xa;</xsl:text>
    </xsl:for-each>

    <xsl:text>  auto smsg = serializer.serialize( msg );&#xa;&#xa;  </xsl:text>
    <xsl:value-of select="@name"/>
    <xsl:text> dmsg;&#xa;  </xsl:text>
    <xsl:text>std::size_t msize = serializer.deserialize( smsg.first, dmsg );</xsl:text> 
    <xsl:text>&#xa;&#xa;</xsl:text>

    <xsl:text>  BOOST_CHECK_EQUAL( smsg.second, msize );&#xa;</xsl:text>

    <xsl:apply-templates select="sequence" mode="test"/>

    <xsl:call-template name="test_fields">
      <xsl:with-param name="target" select="'msg'"/>
    </xsl:call-template>

    
    <xsl:text>&#xa;};&#xa;&#xa;</xsl:text>

  </xsl:template>

  <xsl:template name="fqn">
    <xsl:value-of select="ancestor::template/@name"/>
    <xsl:apply-templates select="parent::sequence" mode="hierarchy"/>
    <xsl:text>::</xsl:text>
    <xsl:value-of select="@name"/>
    <xsl:text>_entry</xsl:text>
  </xsl:template>

  <xsl:template match="sequence" mode="main">
    <xsl:text>  </xsl:text>
    <xsl:call-template name="fqn"/>
    <xsl:text> </xsl:text>
    <xsl:value-of select="@name"/>
    <xsl:text>;&#xa;&#xa;</xsl:text>

    <xsl:text>  </xsl:text>
    <xsl:call-template name="fqn"/>
    <xsl:text> </xsl:text>
    <xsl:value-of select="@name"/>
    <xsl:text>2;&#xa;&#xa;</xsl:text>

    <xsl:apply-templates select="sequence" mode="main"/>

    <xsl:for-each select="sequence">
      <xsl:text>  </xsl:text>
      <xsl:value-of select="../@name"/>
      <xsl:text>.add_</xsl:text>
      <xsl:value-of select="@name"/>
      <xsl:text>( </xsl:text>
      <xsl:value-of select="@name"/>
      <xsl:text> );&#xa;</xsl:text>

      <xsl:text>  </xsl:text>
      <xsl:value-of select="../@name"/>
      <xsl:text>.add_</xsl:text>
      <xsl:value-of select="@name"/>
      <xsl:text>( </xsl:text>
      <xsl:value-of select="@name"/>
      <xsl:text>2 );&#xa;</xsl:text>
    </xsl:for-each>

    <xsl:for-each select="sequence">
      <xsl:text>  </xsl:text>
      <xsl:value-of select="../@name"/>
      <xsl:text>2.add_</xsl:text>
      <xsl:value-of select="@name"/>
      <xsl:text>( </xsl:text>
      <xsl:value-of select="@name"/>
      <xsl:text> );&#xa;</xsl:text>

      <xsl:text>  </xsl:text>
      <xsl:value-of select="../@name"/>
      <xsl:text>2.add_</xsl:text>
      <xsl:value-of select="@name"/>
      <xsl:text>( </xsl:text>
      <xsl:value-of select="@name"/>
      <xsl:text>2 );&#xa;</xsl:text>
    </xsl:for-each>

    <xsl:call-template name="set_fields">
      <xsl:with-param name="target" select="@name"/>
    </xsl:call-template>

    <xsl:call-template name="set_fields">
      <xsl:with-param name="target">
        <xsl:value-of select="@name"/>
        <xsl:text>2</xsl:text>
      </xsl:with-param>
    </xsl:call-template>
  </xsl:template>

  <xsl:template name="parent_name">
    <xsl:if test="local-name(..)='template'">
      <xsl:text>dmsg</xsl:text>
    </xsl:if>

    <xsl:if test="local-name(..)='sequence'">
      <xsl:text>d</xsl:text>
      <xsl:value-of select="../@name"/>
    </xsl:if>
  </xsl:template>

  <xsl:template match="sequence" mode="test">
    <xsl:text>  BOOST_REQUIRE_EQUAL( </xsl:text>
    <xsl:call-template name="parent_name"/>
    <xsl:text>.</xsl:text>
    <xsl:value-of select="@name"/>
    <xsl:text>s().size(), 2 );&#xa;</xsl:text>

    <xsl:text>  auto d</xsl:text>
    <xsl:value-of select="@name"/>
    <xsl:text> = </xsl:text>
    <xsl:call-template name="parent_name"/>
    <xsl:text>.</xsl:text>
    <xsl:value-of select="@name"/>
    <xsl:text>s()[0];&#xa;</xsl:text>

    <xsl:text>  auto d</xsl:text>
    <xsl:value-of select="@name"/>
    <xsl:text>2 = </xsl:text>
    <xsl:call-template name="parent_name"/>
    <xsl:text>.</xsl:text>
    <xsl:value-of select="@name"/>
    <xsl:text>s()[1];&#xa;</xsl:text>
    <xsl:apply-templates select="sequence" mode="test"/>

    <xsl:call-template name="test_fields">
      <xsl:with-param name="target" select="@name"/>
    </xsl:call-template>

    <xsl:call-template name="test_fields">
      <xsl:with-param name="target">
        <xsl:value-of select="@name"/>
        <xsl:text>2</xsl:text>
      </xsl:with-param>
    </xsl:call-template>
  </xsl:template>

</xsl:stylesheet>
