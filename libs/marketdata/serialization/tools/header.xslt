<xsl:stylesheet version='1.0'
              xmlns:xsl='http://www.w3.org/1999/XSL/Transform'>

  <xsl:output method="text"/>
  <xsl:strip-space elements="*"/>

  <xsl:variable name="lowercase" select="'abcdefghijklmnopqrstuvwxyz'" />
  <xsl:variable name="uppercase" select="'ABCDEFGHIJKLMNOPQRSTUVWXYZ'" />

  <xsl:param name="message_name" select="message_name"/>

  <xsl:variable name="sequence_type" select="'uint32_t'"/>
  <xsl:variable name="min_size" select="'500'"/>

  <xsl:template match="sequence" mode="hierarchy_entry">
    <xsl:apply-templates select="parent::sequence" mode="hierarchy_entry"/>

    <xsl:text>::</xsl:text>
    <xsl:value-of select="translate(@name, $uppercase, $lowercase)"/>
    <xsl:if test="local-name()='sequence'">
      <xsl:text>_entry</xsl:text>
    </xsl:if>
  </xsl:template>

  <xsl:template name="guard">
    <xsl:text>APOENA_MSI_MARKETDATA_SERIALIZATION_</xsl:text>
    <xsl:value-of select="translate(@name, $lowercase, $uppercase)"/>
    <xsl:text>_SERIALIZER_HPP</xsl:text>
  </xsl:template>

  <xsl:template name="classdef">
    <xsl:param name="class_name"/>
    <xsl:text>class MARKETDATA_SERIALIZATION_Export </xsl:text>
    <xsl:value-of select="$class_name"/>
    <xsl:text>_serializer &#xa;{&#xa;</xsl:text>
  </xsl:template>

  <xsl:template name="type_name">
    <xsl:param name="field_type"/>
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
        <xsl:text>uint32_t</xsl:text>
      </xsl:when>
      <xsl:when test="$field_type='multistring'">
        <xsl:text>uint32_t</xsl:text>
      </xsl:when>
      <xsl:when test="$field_type='ref'">
        <xsl:text>uint32_t</xsl:text>
      </xsl:when>
    </xsl:choose>
  </xsl:template>

  <xsl:template name="offsets">
    <xsl:text>  enum offset {&#xa;</xsl:text>
    <xsl:text>    offset_pmap = 0,&#xa;</xsl:text>

    <xsl:variable name="pmap_type">
      <xsl:choose>
        <xsl:when test="count(*) &gt; 32">
          <xsl:text>uint64_t</xsl:text>
        </xsl:when>
        <xsl:otherwise>
          <xsl:text>uint32_t</xsl:text>
        </xsl:otherwise>
      </xsl:choose>
    </xsl:variable>

    <xsl:for-each select="field">
      <xsl:variable name="field_name" select="@name"/>
      <xsl:variable name="field_type" select="//fields/field[@name=$field_name]/@type"/>

      <xsl:choose>
        <xsl:when test="$field_type='decimal'">
          <xsl:text>    offset_</xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>_mantissa = offset_</xsl:text>

          <xsl:if test="position()=1">
              <xsl:text>pmap + sizeof( </xsl:text>
              <xsl:value-of select="$pmap_type"/>
              <xsl:text> ),&#xa;</xsl:text>
          </xsl:if>

          <xsl:if test="position()!=1">
            <xsl:variable name="previous_name" select="./preceding-sibling::field[1]/@name"/>
            <xsl:variable name="previous_type">
              <xsl:choose>
                <xsl:when test="./preceding-sibling::field[1][@ref]">
                  <xsl:text>ref</xsl:text>
                </xsl:when>
                <xsl:otherwise>
                  <xsl:value-of select="//fields/field[@name=$previous_name]/@type"/>
                </xsl:otherwise>
              </xsl:choose>
            </xsl:variable>

            <xsl:value-of select="$previous_name"/>
              <xsl:if test="$previous_type='decimal'">
                <xsl:text>_exponent</xsl:text>
              </xsl:if>
              <xsl:text> + sizeof( </xsl:text>
              <xsl:choose>
                <xsl:when test="$previous_type='decimal'">
                  <xsl:text>decimal::exponent_t</xsl:text>
                </xsl:when>
                <xsl:otherwise>
                  <xsl:call-template name="type_name">
                    <xsl:with-param name="field_type" select="$previous_type"/>
                  </xsl:call-template>
                </xsl:otherwise>
              </xsl:choose>
              
              <xsl:text> ),&#xa;</xsl:text>
          </xsl:if>

          <xsl:text>    offset_</xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>_exponent = offset_</xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>_mantissa + sizeof (decimal::mantissa_t),&#xa;</xsl:text>
        </xsl:when>

        <xsl:otherwise>
          <xsl:text>    offset_</xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text> = offset_</xsl:text>

          <xsl:if test="position()=1">
            <xsl:text>pmap + sizeof( </xsl:text>
            <xsl:value-of select="$pmap_type"/>
            <xsl:text> ),&#xa;</xsl:text>
          </xsl:if>

          <xsl:if test="position()!=1">
            <xsl:variable name="previous_name" select="./preceding-sibling::field[1]/@name"/>

            <xsl:variable name="previous_type">
              <xsl:choose>
                <xsl:when test="./preceding-sibling::field[1][@ref]">
                  <xsl:text>ref</xsl:text>
                </xsl:when>
                <xsl:otherwise>
                  <xsl:value-of select="//fields/field[@name=$previous_name]/@type"/>
                </xsl:otherwise>
              </xsl:choose>
            </xsl:variable>

            <xsl:value-of select="$previous_name"/>
            <xsl:if test="$previous_type='decimal'">
              <xsl:text>_exponent</xsl:text>
            </xsl:if>
            <xsl:text> + sizeof( </xsl:text>
            <xsl:choose>
              <xsl:when test="$previous_type='decimal'">
                <xsl:text>decimal::exponent_t</xsl:text>
              </xsl:when>
              <xsl:otherwise>
                <xsl:call-template name="type_name">
                  <xsl:with-param name="field_type" select="$previous_type"/>
                </xsl:call-template>
              </xsl:otherwise>
            </xsl:choose>
              
            <xsl:text> ),&#xa;</xsl:text>
          </xsl:if>

        </xsl:otherwise>
      </xsl:choose>
    </xsl:for-each>

    <xsl:variable name="last_name" select="./field[last()]/@name"/>
    <xsl:variable name="last_type">
      <xsl:choose>
        <xsl:when test="./field[last()][@ref]">
          <xsl:text>ref</xsl:text>
        </xsl:when>
        <xsl:otherwise>
          <xsl:value-of select="//fields/field[@name=$last_name]/@type"/>
        </xsl:otherwise>
      </xsl:choose>
    </xsl:variable>

    <xsl:choose>
      <xsl:when test="sequence">
        <xsl:for-each select="sequence">
          <xsl:text>    offset_</xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text> = offset_</xsl:text>

          <xsl:choose>
            <xsl:when test="position()=1">

              <xsl:value-of select="$last_name"/>
              <xsl:if test="$last_type='decimal'">
                <xsl:text>_exponent</xsl:text>
              </xsl:if>
              <xsl:text> + sizeof( </xsl:text>
              <xsl:choose>
                <xsl:when test="$last_type='decimal'">
                  <xsl:text>decimal::exponent_t</xsl:text>
                </xsl:when>
                <xsl:otherwise>
                  <xsl:call-template name="type_name">
                    <xsl:with-param name="field_type" select="$last_type"/>
                  </xsl:call-template>
                </xsl:otherwise>
              </xsl:choose>
              <xsl:text> ),&#xa;</xsl:text>
            </xsl:when>

            <xsl:otherwise>
              <xsl:variable name="previous_name" select="./preceding-sibling::sequence[1]/@name"/>

              <xsl:value-of select="$previous_name"/>
              <xsl:text> + sizeof( </xsl:text>
              <xsl:value-of select="$sequence_type"/>
              <xsl:text> ),&#xa;</xsl:text>
            </xsl:otherwise>
          </xsl:choose>
        </xsl:for-each>

        <xsl:text>    offset_variable_fields = offset_</xsl:text>
        <xsl:value-of select="./sequence[last()]/@name"/>
        <xsl:text> + sizeof( </xsl:text>
        <xsl:value-of select="$sequence_type"/>
        <xsl:text> )&#xa;</xsl:text>
        <xsl:text>  };&#xa;&#xa;</xsl:text>
      </xsl:when>

      <xsl:otherwise>
        <xsl:text>    offset_variable_fields = offset_</xsl:text>
        <xsl:value-of select="$last_name"/>
        <xsl:if test="$last_type='decimal'">
          <xsl:text>_exponent</xsl:text>
        </xsl:if>
        <xsl:text> + sizeof( </xsl:text>
        <xsl:choose>
          <xsl:when test="$last_type='decimal'">
            <xsl:text>decimal::exponent_t</xsl:text>
          </xsl:when>
          <xsl:otherwise>
            <xsl:call-template name="type_name">
              <xsl:with-param name="field_type" select="$last_type"/>
            </xsl:call-template>
          </xsl:otherwise>
        </xsl:choose>
        <xsl:text> )&#xa;</xsl:text>
        <xsl:text>  };&#xa;&#xa;</xsl:text>
     </xsl:otherwise>
    </xsl:choose>



  </xsl:template>

  <xsl:template name="class_body">
    <xsl:text>public:&#xa;</xsl:text>

    <xsl:call-template name="offsets"/>

    <xsl:text>  </xsl:text>
    <xsl:value-of select="@name"/>
    <xsl:if test="local-name()='sequence'">
      <xsl:text>_entry</xsl:text>
    </xsl:if>
    <xsl:text>_serializer();&#xa;</xsl:text>

    <xsl:text>  std::pair&lt;const unsigned char*, std::size_t&gt; serialize( const </xsl:text>
    <xsl:text>messages::</xsl:text>

    <xsl:if test="local-name()='sequence'">
      <xsl:value-of select="ancestor::template/@name"/>
      <xsl:apply-templates select="parent::sequence" mode="hierarchy_entry"/>
      <xsl:text>::</xsl:text>
    </xsl:if>
    <xsl:value-of select="@name"/>
    <xsl:if test="local-name()='sequence'">
      <xsl:text>_entry</xsl:text>
    </xsl:if>
   
    <xsl:text>&amp; msg );&#xa;</xsl:text>

    <xsl:text>  std::size_t buffer_size() const;&#xa;</xsl:text>

    <xsl:text>  std::size_t deserialize( const unsigned char* data, </xsl:text>
    <xsl:text>messages::</xsl:text>
    <xsl:if test="local-name()='sequence'">
      <xsl:value-of select="ancestor::template/@name"/>
      <xsl:apply-templates select="parent::sequence" mode="hierarchy_entry"/>
      <xsl:text>::</xsl:text>
    </xsl:if>
    <xsl:value-of select="@name"/>
    <xsl:if test="local-name()='sequence'">
      <xsl:text>_entry</xsl:text>
    </xsl:if>
    <xsl:text>&amp; dst);&#xa;</xsl:text>

    <xsl:text>&#xa;</xsl:text>
    <xsl:text>private:&#xa;</xsl:text>
    <xsl:for-each select="sequence">
      <xsl:text>  </xsl:text>
      <xsl:value-of select="@name"/>
      <xsl:text>_entry_serializer </xsl:text>
      <xsl:value-of select="@name"/>
      <xsl:text>_entry_serializer_;&#xa;</xsl:text>
    </xsl:for-each>
    <xsl:for-each select="field[@ref]">
      <xsl:text>  </xsl:text>
      <xsl:value-of select="@name"/>
      <xsl:text>_serializer </xsl:text>
      <xsl:value-of select="@name"/>
      <xsl:text>_serializer_;&#xa;</xsl:text>
    </xsl:for-each>
    <xsl:text>&#xa;</xsl:text>

    <xsl:text>  std::vector&lt;unsigned char&gt; data_;&#xa;</xsl:text>
  </xsl:template>

  <xsl:template match="template">
    <xsl:if test="@name=$message_name">

      <xsl:text>#ifndef </xsl:text>
      <xsl:call-template name="guard"/>
      <xsl:text>&#xa;#define </xsl:text>
      <xsl:call-template name="guard"/>
      <xsl:text>&#xa;&#xa;</xsl:text>
      <xsl:text>#include &lt;msi/marketdata/messages/</xsl:text>
      <xsl:value-of select="@name"/>
      <xsl:text>.hpp&gt;&#xa;</xsl:text>
      <xsl:text>#include &lt;msi/marketdata/serialization/</xsl:text>
      <xsl:text>marketdata_serialization_export.hpp&gt;&#xa;</xsl:text>
      <xsl:text>&#xa;</xsl:text>

      <xsl:for-each select="field[@ref]">
        <xsl:text>#include &lt;msi/marketdata/serialization/</xsl:text>
        <xsl:value-of select="@name"/>
        <xsl:text>_serializer.hpp&gt;&#xa;</xsl:text>
      </xsl:for-each>

      <xsl:text>&#xa;</xsl:text>
      <xsl:text>namespace apoena&#xa;{&#xa;</xsl:text>
      <xsl:text>namespace msi&#xa;{&#xa;</xsl:text>
      <xsl:text>namespace marketdata&#xa;{&#xa;</xsl:text>
      <xsl:text>namespace serialization&#xa;{&#xa;&#xa;</xsl:text>

      <xsl:call-template name="classdef">
        <xsl:with-param name="class_name" select="@name"/>
      </xsl:call-template>

      <!--inner classes representing sequences --> 
      <xsl:apply-templates select="sequence"/>

      <xsl:call-template name="class_body"/>

      <xsl:text>&#xa;};&#xa;&#xa;</xsl:text>
      <xsl:text>} //end of namespace&#xa;</xsl:text>
      <xsl:text>} //end of namespace&#xa;</xsl:text>
      <xsl:text>} //end of namespace&#xa;</xsl:text>
      <xsl:text>} //end of namespace&#xa;</xsl:text>

      <xsl:text>&#xa;#endif /* </xsl:text>
      <xsl:call-template name="guard"/>
      <xsl:text> */&#xa;&#xa;</xsl:text> 

    </xsl:if>
  </xsl:template>

  <xsl:template match="sequence">
    <xsl:call-template name="classdef">
      <xsl:with-param name="class_name" select="concat(translate(@name, $uppercase, $lowercase), '_entry')"/>
    </xsl:call-template>

    <!-- nested sequence definitions -->
    <xsl:apply-templates select="sequence"/>

    <xsl:call-template name="class_body"/>

    <xsl:text>&#xa;};&#xa;&#xa;</xsl:text>
  </xsl:template>

</xsl:stylesheet>
