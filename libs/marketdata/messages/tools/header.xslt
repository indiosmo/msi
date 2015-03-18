<xsl:stylesheet version='1.0'
              xmlns:xsl='http://www.w3.org/1999/XSL/Transform'>

  <xsl:output method="text"/>
  <xsl:strip-space elements="*"/>

  <xsl:variable name="lowercase" select="'abcdefghijklmnopqrstuvwxyz'" />
  <xsl:variable name="uppercase" select="'ABCDEFGHIJKLMNOPQRSTUVWXYZ'" />

  <xsl:param name="message_name" select="message_name"/>

  <xsl:template name="guard">
    <xsl:text>APOENA_MSI_MARKETDATA_MESSAGES_</xsl:text>
    <xsl:value-of select="translate(@name, $lowercase, $uppercase)"/>
    <xsl:text>_HPP</xsl:text>
  </xsl:template>

  <xsl:template name="classdef">
    <xsl:param name="class_name"/>
    <xsl:text>class MARKETDATA_MESSAGES_Export </xsl:text>
    <xsl:value-of select="$class_name"/>
    <xsl:text>&#xa;{&#xa;</xsl:text>
    <xsl:text>public:&#xa;</xsl:text>
  </xsl:template>

  <xsl:template name="field_enum">
    <xsl:text>  enum field_index&#xa;  {&#xa;</xsl:text>
    <xsl:for-each select="*">
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
    <xsl:variable name="field_name" select="@name"/>
    <xsl:variable name="field_type" select="//fields/field[@name=$field_name]/@type"/>
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
        <xsl:text>std::string</xsl:text>
      </xsl:when>
      <xsl:when test="$field_type='multistring'">
        <xsl:text>std::bitset&lt;</xsl:text>
        <xsl:value-of select="@name"/>
        <xsl:text>_field_count&gt;</xsl:text>
      </xsl:when>
    </xsl:choose>
  </xsl:template>

  <xsl:template name="class_body">
    <xsl:for-each select="*">
      <xsl:choose>

        <xsl:when test="local-name()='sequence'">
          <xsl:text>  const std::vector&lt;</xsl:text>
          <xsl:value-of select="translate(@name, $uppercase, $lowercase)"/>
          <xsl:text>_entry&gt;&amp; </xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>s() const;&#xa;</xsl:text>

          <xsl:text>  void add_</xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>( const </xsl:text>
          <xsl:value-of select="translate(@name, $uppercase, $lowercase)"/>
          <xsl:text>_entry&amp; val );&#xa;&#xa;</xsl:text>
        </xsl:when>

        
        <xsl:otherwise> <!-- field -->
          <xsl:choose>
            <xsl:when test="@ref='single'">
              <xsl:text>  std::pair&lt;bool, const </xsl:text>
              <xsl:value-of select="@name"/>
              <xsl:text>&amp;&gt; </xsl:text>
              <xsl:value-of select="@name"/>
              <xsl:text>() const;&#xa;</xsl:text>
    
              <xsl:text>  void set_</xsl:text>
              <xsl:value-of select="@name"/>
              <xsl:text>( const messages::</xsl:text>
              <xsl:value-of select="@name"/>
              <xsl:text>&amp; val );&#xa;&#xa;</xsl:text>
            </xsl:when>
    
            <xsl:when test="@ref='multiple'">
              <xsl:text>  const std::vector&lt;</xsl:text> 
              <xsl:value-of select="@name"/>
              <xsl:text>&gt;&amp; </xsl:text>
              <xsl:value-of select="@name"/>
              <xsl:text>s() const;&#xa;</xsl:text>
    
              <xsl:text>  void add_</xsl:text>
              <xsl:value-of select="@name"/>
              <xsl:text>( const </xsl:text>
              <xsl:value-of select="@name"/>
              <xsl:text>&amp; val);&#xa;&#xa;</xsl:text>
            </xsl:when>

            <xsl:otherwise>
              <xsl:variable name="field_name" select="@name"/>
              <xsl:variable name="field_type" select="//fields/field[@name=$field_name]/@type"/>
              <xsl:choose>
  
                <xsl:when test="$field_type='multistring'">
                  <xsl:for-each select="//fields/field[@name=$field_name]/value">
                    <xsl:text>  bool </xsl:text>
                    <xsl:value-of select="../@name"/>
                    <xsl:text>_</xsl:text>
                    <xsl:value-of select="@name"/>
                    <xsl:text>() const;&#xa;</xsl:text>
                  </xsl:for-each>
    
                  <xsl:text>  std::pair&lt;bool, uint32_t&gt; </xsl:text>
                  <xsl:value-of select="@name"/>
                  <xsl:text>() const;&#xa;</xsl:text>
  
                  <xsl:text>  void set_</xsl:text>
                  <xsl:value-of select="@name"/>
                  <xsl:text>( const </xsl:text>
                  <xsl:call-template name="type_name"/>
                  <xsl:text>&amp; val );&#xa;</xsl:text>
  
                  <xsl:text>  void set_</xsl:text>
                  <xsl:value-of select="@name"/>
                  <xsl:text>( const std::string&amp; val );&#xa;</xsl:text>
                </xsl:when>
  
                <xsl:otherwise>
                  <xsl:text>  std::pair&lt;bool, </xsl:text>
                  <xsl:if test="$field_type='string'">
                    <xsl:text>const </xsl:text>
                  </xsl:if>
                  <xsl:call-template name="type_name"/>
                  <xsl:if test="$field_type='string'">
                    <xsl:text>&amp;</xsl:text>
                  </xsl:if>
                  <xsl:text>&gt; </xsl:text>
  
                  <xsl:value-of select="@name"/>
                  <xsl:text>() const;&#xa;</xsl:text>
                  <xsl:text>  void set_</xsl:text>
                  <xsl:value-of select="@name"/>
                  <xsl:text>( </xsl:text>
                  <xsl:if test="$field_type='string'">
                    <xsl:text>const </xsl:text>
                  </xsl:if>
                  <xsl:call-template name="type_name"/>
                  <xsl:if test="$field_type='string'">
                    <xsl:text>&amp;</xsl:text>
                  </xsl:if>
  
                  <xsl:text> val );&#xa;&#xa;</xsl:text>
                </xsl:otherwise>
              </xsl:choose>
            </xsl:otherwise>
          </xsl:choose>
        </xsl:otherwise>
      </xsl:choose>
    </xsl:for-each>

    <xsl:text>  const std::bitset&lt;ix_field_count&gt;&amp;</xsl:text>
    <xsl:text> presence_map() const;&#xa;</xsl:text>
    <xsl:choose>
      <xsl:when test="count(*) &gt; 32">
        <xsl:text>  void set_presence_map( uint64_t val );&#xa;&#xa;</xsl:text>
      </xsl:when>
      <xsl:otherwise>
        <xsl:text>  void set_presence_map( uint32_t val );&#xa;&#xa;</xsl:text>
      </xsl:otherwise>
    </xsl:choose>

    <xsl:text>private:&#xa;</xsl:text>

    <xsl:text>&#xa;</xsl:text>
    <xsl:text>  std::bitset&lt;ix_field_count&gt; presence_map_;&#xa;&#xa;</xsl:text>

    <xsl:for-each select="*">
      <xsl:choose>
        <xsl:when test="local-name()='sequence'">
          <xsl:text>  std::vector&lt;</xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>_entry&gt; </xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>s_;&#xa;</xsl:text>
        </xsl:when>

        <xsl:otherwise>
          <xsl:choose>
            <xsl:when test="@ref='multiple'">
              <xsl:text>  std::vector&lt;</xsl:text>
              <xsl:value-of select="@name"/>
              <xsl:text>&gt; </xsl:text>
              <xsl:value-of select="@name"/>
              <xsl:text>s_;&#xa;</xsl:text>
            </xsl:when>
            <xsl:when test="@ref='single'">
              <xsl:text>  messages::</xsl:text>
              <xsl:value-of select="@name"/>
              <xsl:text> </xsl:text>
              <xsl:value-of select="@name"/>
              <xsl:text>_;&#xa;</xsl:text>
            </xsl:when>
            <xsl:otherwise>
              <xsl:text>  </xsl:text>
              <xsl:call-template name="type_name"/>
              <xsl:text> </xsl:text>
              <xsl:value-of select="@name"/>
              <xsl:text>_;&#xa;</xsl:text>
            </xsl:otherwise>
          </xsl:choose>
        </xsl:otherwise>
      </xsl:choose>
    </xsl:for-each>
  </xsl:template>

  <xsl:template match="template">
    <xsl:if test="@name=$message_name">

      <xsl:text>#ifndef </xsl:text>
      <xsl:call-template name="guard"/>
      <xsl:text>&#xa;#define </xsl:text>
      <xsl:call-template name="guard"/>
      <xsl:text>&#xa;&#xa;</xsl:text>
      <xsl:text>#include &lt;bitset&gt;&#xa;</xsl:text>
      <xsl:text>#include &lt;utility&gt;&#xa;</xsl:text>
      <xsl:text>#include &lt;vector&gt;&#xa;</xsl:text>
      <xsl:text>#include &lt;map&gt;&#xa;</xsl:text>

      <xsl:text>#include &lt;msi/decimal/decimal.hpp&gt;&#xa;</xsl:text>
      <xsl:text>#include &lt;msi/marketdata/messages/</xsl:text>
      <xsl:text>marketdata_messages_export.hpp&gt;&#xa;</xsl:text>
      <xsl:text>#include &lt;msi/marketdata/messages/field_values.hpp&gt;&#xa;</xsl:text>
      <xsl:text>&#xa;</xsl:text>

      <xsl:for-each select="field[@ref='single']">
        <xsl:text>#include &lt;msi/marketdata/messages/</xsl:text>
        <xsl:value-of select="@name"/>
        <xsl:text>.hpp&gt;&#xa;</xsl:text>
      </xsl:for-each>

      <xsl:for-each select="field[@ref='multiple']">
        <xsl:text>#include &lt;msi/marketdata/messages/</xsl:text>
        <xsl:value-of select="@name"/>
        <xsl:text>.hpp&gt;&#xa;</xsl:text>
      </xsl:for-each>

      <xsl:text>&#xa;</xsl:text>
      <xsl:text>namespace apoena&#xa;{&#xa;</xsl:text>
      <xsl:text>namespace msi&#xa;{&#xa;</xsl:text>
      <xsl:text>namespace marketdata&#xa;{&#xa;</xsl:text>
      <xsl:text>namespace messages&#xa;{&#xa;&#xa;</xsl:text>

      <xsl:call-template name="classdef">
        <xsl:with-param name="class_name" select="@name"/>
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

    <xsl:call-template name="field_enum"/>
    <xsl:call-template name="reset"/>
    <xsl:call-template name="class_body"/>

    <xsl:text>&#xa;};&#xa;&#xa;</xsl:text>
  </xsl:template>

</xsl:stylesheet>
