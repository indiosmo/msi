<xsl:stylesheet version='1.0'
               xmlns:xsl='http://www.w3.org/1999/XSL/Transform'>

  <xsl:output method="text"/>
  <xsl:strip-space elements="*"/>

  <xsl:variable name="lowercase" select="'abcdefghijklmnopqrstuvwxyz'" />
  <xsl:variable name="uppercase" select="'ABCDEFGHIJKLMNOPQRSTUVWXYZ'" />

  <xsl:param name="message_name" select="message_name"/>

  <xsl:template match="sequence" mode="hierarchy">
    <xsl:apply-templates select="parent::sequence" mode="hierarchy"/>

    <xsl:text>::</xsl:text>
    <xsl:value-of select="translate(@name, $uppercase, $lowercase)"/>
    <xsl:if test="local-name()='sequence'">
      <xsl:text>_entry</xsl:text>
    </xsl:if>
  </xsl:template>

  <xsl:template name="reset">
    <xsl:text>void&#xa;</xsl:text>
    <xsl:choose>

      <xsl:when test="local-name()='sequence'">
        <xsl:value-of select="ancestor::template/@name"/>
        <xsl:apply-templates select="parent::sequence" mode="hierarchy"/>
        <xsl:text>::</xsl:text>
        <xsl:value-of select="translate(@name, $uppercase, $lowercase)"/>
        <xsl:text>_entry</xsl:text>
      </xsl:when>
      <xsl:otherwise>
        <xsl:value-of select="@name"/>
      </xsl:otherwise>

    </xsl:choose>

    <xsl:text>::reset()&#xa;{&#xa;  presence_map_.reset();&#xa;</xsl:text>
    <xsl:for-each select="sequence">
      <xsl:text>  </xsl:text>
      <xsl:value-of select="@name"/>
      <xsl:text>s_.clear();&#xa;</xsl:text>
    </xsl:for-each>
    <xsl:text>}&#xa;&#xa;</xsl:text>
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
    <xsl:call-template name="reset"/>

    <xsl:for-each select="*">
      <xsl:choose>

        <xsl:when test="local-name()='sequence'">
          <xsl:text>const std::vector&lt;</xsl:text>
          <xsl:value-of select="ancestor::template/@name"/>
          <xsl:apply-templates select="parent::sequence" mode="hierarchy"/>
          <xsl:text>::</xsl:text>
          <xsl:value-of select="translate(@name, $uppercase, $lowercase)"/>
          <xsl:text>_entry&gt;&amp;&#xa;</xsl:text>
          <xsl:value-of select="ancestor::template/@name"/>
          <xsl:apply-templates select="parent::sequence" mode="hierarchy"/>
          <xsl:text>::</xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>s() const&#xa;{&#xa;  return </xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>s_;&#xa;}&#xa;&#xa;</xsl:text>

          <xsl:text>void&#xa;</xsl:text>
          <xsl:value-of select="ancestor::template/@name"/>
          <xsl:apply-templates select="parent::sequence" mode="hierarchy"/>
          <xsl:text>::add_</xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>( const </xsl:text>
          <xsl:value-of select="translate(@name, $uppercase, $lowercase)"/>
          <xsl:text>_entry&amp; val )&#xa;{&#xa;  </xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>s_.push_back( val );&#xa;</xsl:text>
          <xsl:text>  presence_map_[ix_</xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>] = true;&#xa;</xsl:text>
          <xsl:text>}&#xa;&#xa;</xsl:text>
        </xsl:when>

        
        <xsl:otherwise>
          <xsl:choose>

            <xsl:when test="@ref='multiple'">
              <xsl:text>const std::vector&lt;</xsl:text>
              <xsl:value-of select="@name"/>
              <xsl:text>&gt;&amp;&#xa;</xsl:text>
              <xsl:value-of select="../@name"/>
              <xsl:text>::</xsl:text>
              <xsl:value-of select="@name"/>
              <xsl:text>s() const&#xa;{&#xa;</xsl:text>
              <xsl:text>  return </xsl:text>
              <xsl:value-of select="@name"/>
              <xsl:text>s_;&#xa;}&#xa;&#xa;</xsl:text>
    
              <xsl:text>void&#xa;</xsl:text>
              <xsl:value-of select="../@name"/>
              <xsl:text>::add_</xsl:text>
              <xsl:value-of select="@name"/>
              <xsl:text>( const </xsl:text>
              <xsl:value-of select="@name"/>
              <xsl:text>&amp; val )&#xa;{&#xa;  </xsl:text>
              <xsl:value-of select="@name"/>
              <xsl:text>s_.push_back( val );&#xa;</xsl:text>
              <xsl:text>  presence_map_[ix_</xsl:text>  
              <xsl:value-of select="@name"/>
              <xsl:text>] = true;&#xa;}&#xa;&#xa;</xsl:text>
            </xsl:when>
    
            <xsl:when test="@ref='single'">
              <xsl:text>std::pair&lt;bool, const </xsl:text>
              <xsl:value-of select="@name"/>
              <xsl:text>&amp;&gt;&#xa;</xsl:text>
              <xsl:value-of select="../@name"/>
              <xsl:text>::</xsl:text>
              <xsl:value-of select="@name"/>
              <xsl:text>() const&#xa;{&#xa;</xsl:text>
              <xsl:text>  return std::pair&lt;bool, const messages::</xsl:text>
              <xsl:value-of select="@name"/>
              <xsl:text>&amp;&gt;( presence_map_[ix_</xsl:text>
              <xsl:value-of select="@name"/>
              <xsl:text>], </xsl:text>
              <xsl:value-of select="@name"/>
              <xsl:text>_ );&#xa;}&#xa;&#xa;</xsl:text>
    
              <xsl:text>void&#xa;</xsl:text>
              <xsl:value-of select="../@name"/>
              <xsl:text>::set_</xsl:text>
              <xsl:value-of select="@name"/>
              <xsl:text>( const messages::</xsl:text>
              <xsl:value-of select="@name"/>
              <xsl:text>&amp; val )&#xa;{&#xa;  </xsl:text>
              <xsl:value-of select="@name"/>
              <xsl:text>_ = val;&#xa;  presence_map_[ix_</xsl:text>
              <xsl:value-of select="@name"/>
              <xsl:text>] = true;&#xa;}&#xa;&#xa;</xsl:text>
            </xsl:when>

            <xsl:otherwise>
              <xsl:variable name="parent_name" select="../@name"/>
              <xsl:variable name="field_name" select="@name"/>
              <xsl:variable name="field_type" select="//fields/field[@name=$field_name]/@type"/>
              <xsl:choose>
    
                <xsl:when test="$field_type='multistring'">
                  <xsl:for-each select="//fields/field[@name=$field_name]/value">
                    <xsl:text>bool&#xa;</xsl:text>
                    <xsl:value-of select="$parent_name"/>
                    <xsl:apply-templates select="parent::sequence" mode="hierarchy"/>
                    <xsl:if test="local-name(..)='sequence'">
                      <xsl:text>_entry</xsl:text>
                    </xsl:if>
                    <xsl:text>::</xsl:text>
                    <xsl:value-of select="../@name"/>
                    <xsl:text>_</xsl:text>
                    <xsl:value-of select="@name"/>
                    <xsl:text>() const&#xa;{&#xa;</xsl:text>
                    <xsl:text>  if ( presence_map_[ix_</xsl:text>
                    <xsl:value-of select="../@name"/>
                    <xsl:text>] &amp;&amp; </xsl:text>
                    <xsl:value-of select="../@name"/>
                    <xsl:text>_[ix_</xsl:text>
                    <xsl:value-of select="../@name"/>
                    <xsl:text>_</xsl:text>
                    <xsl:value-of select="@name"/>
                    <xsl:text>] )&#xa;  {&#xa;    return true;&#xa;  }&#xa;&#xa;</xsl:text>
                    <xsl:text>  return false;&#xa;}&#xa;&#xa;</xsl:text>
                  </xsl:for-each>
    
                  <xsl:text>std::pair&lt; bool, uint32_t&gt;&#xa;</xsl:text>
                  <xsl:value-of select="ancestor::template/@name"/>
                  <xsl:apply-templates select="parent::sequence" mode="hierarchy"/>
                  <xsl:if test="local-name(..)='sequence'">
                    <xsl:text>_entry</xsl:text>
                  </xsl:if>
                  <xsl:text>::</xsl:text>
                  <xsl:value-of select="@name"/>
                  <xsl:text>() const&#xa;{&#xa;</xsl:text>
                  <xsl:text>  return std::pair&lt;bool, uint32_t&gt;</xsl:text>
                  <xsl:text>( presence_map_[ix_</xsl:text>
                  <xsl:value-of select="@name"/>
                  <xsl:text>], </xsl:text>
                  <xsl:value-of select="@name"/>
                  <xsl:text>_.to_ulong() );&#xa;}&#xa;&#xa;</xsl:text>
    
                  <xsl:text>void&#xa;</xsl:text>
                  <xsl:value-of select="ancestor::template/@name"/>
                  <xsl:apply-templates select="parent::sequence" mode="hierarchy"/>
                  <xsl:if test="local-name(..)='sequence'">
                    <xsl:text>_entry</xsl:text>
                  </xsl:if>
                  <xsl:text>::set_</xsl:text>
                  <xsl:value-of select="@name"/>
                  <xsl:text>( const std::bitset&lt;</xsl:text>
                  <xsl:value-of select="@name"/>
                  <xsl:text>_field_count&gt;&amp; val )&#xa;{&#xa;  </xsl:text>
                  <xsl:value-of select="@name"/>
                  <xsl:text>_ = val;&#xa;  presence_map_[ix_</xsl:text>
                  <xsl:value-of select="@name"/>
                  <xsl:text>] = true;&#xa;}&#xa;&#xa;</xsl:text>
    
                  <xsl:text>void&#xa;</xsl:text>
                  <xsl:value-of select="ancestor::template/@name"/>
                  <xsl:apply-templates select="parent::sequence" mode="hierarchy"/>
                  <xsl:if test="local-name(..)='sequence'">
                    <xsl:text>_entry</xsl:text>
                  </xsl:if>
                  <xsl:text>::set_</xsl:text>
                  <xsl:value-of select="@name"/>
                  <xsl:text>( const std::string&amp; val )&#xa;{&#xa;</xsl:text>
    
                  <xsl:text>  boost::char_separator&lt;char&gt; separator(" ");&#xa;</xsl:text>
                  <xsl:text>  boost::tokenizer&lt;boost::char_separator&lt;char&gt;&gt;</xsl:text>
                  <xsl:text> tokenizer( val, separator );&#xa;&#xa;</xsl:text>
                  <xsl:text>  if( tokenizer.begin() != tokenizer.end() )&#xa;  {&#xa;</xsl:text>
                  <xsl:text>    presence_map_[ix_</xsl:text>
                  <xsl:value-of select="@name"/>
                  <xsl:text>] = true;&#xa;&#xa;</xsl:text>
                  <xsl:text>    for ( auto field : tokenizer )&#xa;    {&#xa;</xsl:text>
                  <xsl:text>      auto index = </xsl:text>
                  <xsl:value-of select="@name"/>
                  <xsl:text>_value_index_map.find( field.c_str() );&#xa;</xsl:text>
                  <xsl:text>      if ( index != </xsl:text>
                  <xsl:value-of select="@name"/>
                  <xsl:text>_value_index_map.end() )&#xa;      {&#xa;        </xsl:text>
                  <xsl:value-of select="@name"/>
                  <xsl:text>_.set(</xsl:text>
                  <xsl:text> index-&gt;second );&#xa;      }&#xa;</xsl:text>
                  <xsl:text>    }&#xa;  }&#xa;}&#xa;&#xa;</xsl:text>
                </xsl:when>
    
                <xsl:otherwise>
                  <xsl:text>std::pair&lt;bool, </xsl:text>
                  <xsl:if test="$field_type='string'">
                    <xsl:text>const </xsl:text>
                  </xsl:if>
                  <xsl:call-template name="type_name"/>
                  <xsl:if test="$field_type='string'">
                    <xsl:text>&amp;</xsl:text>
                  </xsl:if>
                  <xsl:text>&gt;&#xa;</xsl:text>
    
                  <xsl:value-of select="ancestor::template/@name"/>
                  <xsl:apply-templates select="parent::sequence" mode="hierarchy"/>
                  <xsl:text>::</xsl:text>
                  <xsl:value-of select="@name"/>
                  <xsl:text>() const&#xa;{&#xa;</xsl:text>
                  <xsl:text>  return std::pair&lt;bool, </xsl:text>
                  <xsl:if test="$field_type='string'">
                    <xsl:text>const </xsl:text>
                  </xsl:if>
                  <xsl:call-template name="type_name"/>
                  <xsl:if test="$field_type='string'">
                    <xsl:text>&amp;</xsl:text>
                  </xsl:if>
                  <xsl:text>&gt;( presence_map_[ix_</xsl:text>
                  <xsl:value-of select="@name"/>
                  <xsl:text>], </xsl:text>
                  <xsl:value-of select="@name"/>
                  <xsl:text>_ );&#xa;}&#xa;&#xa;</xsl:text>
    
                  <xsl:text>void&#xa;</xsl:text>
                  <xsl:value-of select="ancestor::template/@name"/>
                  <xsl:apply-templates select="parent::sequence" mode="hierarchy"/>
                  <xsl:text>::set_</xsl:text>
                  <xsl:value-of select="@name"/>
                  <xsl:text>( </xsl:text>
                  <xsl:if test="$field_type='string'">
                    <xsl:text>const </xsl:text>
                  </xsl:if>
                  <xsl:call-template name="type_name"/>
                  <xsl:if test="$field_type='string'">
                    <xsl:text>&amp;</xsl:text>
                  </xsl:if>
                  <xsl:text> val )&#xa;{&#xa;  </xsl:text>
                  <xsl:value-of select="@name"/>
                  <xsl:text>_ = val;&#xa;  presence_map_[ix_</xsl:text>
                  <xsl:value-of select="@name"/>
                  <xsl:text>] = true;&#xa;}&#xa;&#xa;</xsl:text>
                </xsl:otherwise>
              </xsl:choose>
            </xsl:otherwise>
          </xsl:choose>
        </xsl:otherwise>
      </xsl:choose>
    </xsl:for-each>

    <xsl:text>const std::bitset&lt;</xsl:text>
    <xsl:if test="local-name()='sequence'">
      <xsl:value-of select="ancestor::template/@name"/>
      <xsl:apply-templates select="parent::sequence" mode="hierarchy"/>
      <xsl:text>::</xsl:text>
      <xsl:value-of select="translate(@name, $uppercase, $lowercase)"/>
      <xsl:text>_entry</xsl:text>
    </xsl:if>

    <xsl:if test="local-name()!='sequence'">
      <xsl:value-of select="@name"/>
    </xsl:if>

    <xsl:text>::ix_field_count&gt;&amp;&#xa;</xsl:text>

    <xsl:if test="local-name()='sequence'">
      <xsl:value-of select="ancestor::template/@name"/>
      <xsl:apply-templates select="parent::sequence" mode="hierarchy"/>
      <xsl:text>::</xsl:text>
      <xsl:value-of select="translate(@name, $uppercase, $lowercase)"/>
      <xsl:text>_entry</xsl:text>
    </xsl:if>

    <xsl:if test="local-name()!='sequence'">
      <xsl:value-of select="@name"/>
    </xsl:if>

    <xsl:text>::presence_map() const&#xa;{&#xa;</xsl:text>
    <xsl:text>  return presence_map_;&#xa;}&#xa;&#xa;</xsl:text>

    <xsl:text>void </xsl:text>
    <xsl:if test="local-name()='sequence'">
      <xsl:value-of select="ancestor::template/@name"/>
      <xsl:apply-templates select="parent::sequence" mode="hierarchy"/>
      <xsl:text>::</xsl:text>
      <xsl:value-of select="translate(@name, $uppercase, $lowercase)"/>
      <xsl:text>_entry</xsl:text>
    </xsl:if>

    <xsl:if test="local-name()!='sequence'">
      <xsl:value-of select="@name"/>
    </xsl:if>

    <xsl:choose>
      <xsl:when test="count(*) &gt; 32">
        <xsl:text>::set_presence_map( uint64_t val )&#xa;{&#xa;</xsl:text>
      </xsl:when>
      <xsl:otherwise>
        <xsl:text>::set_presence_map( uint32_t val )&#xa;{&#xa;</xsl:text>
      </xsl:otherwise>
    </xsl:choose>
    <xsl:text>  presence_map_ = std::bitset&lt;ix_field_count&gt;( val );</xsl:text>
    <xsl:text>&#xa;}&#xa;&#xa;</xsl:text>

  </xsl:template>

  <xsl:template match="template">
    <xsl:if test="@name=$message_name">

      <xsl:text>#include &lt;msi/msi_pch.hpp&gt;&#xa;</xsl:text>
      <xsl:text>#include &lt;boost/tokenizer.hpp&gt;&#xa;</xsl:text>
      <xsl:text>#include &lt;msi/marketdata/messages/</xsl:text>
      <xsl:value-of select="@name"/>
      <xsl:text>.hpp&gt;&#xa;</xsl:text>

      <xsl:text>&#xa;</xsl:text>
      <xsl:text>namespace apoena&#xa;{&#xa;</xsl:text>
      <xsl:text>namespace msi&#xa;{&#xa;</xsl:text>
      <xsl:text>namespace marketdata&#xa;{&#xa;</xsl:text>
      <xsl:text>namespace messages&#xa;{&#xa;&#xa;</xsl:text>


      <!--inner classes representing sequences --> 
      <xsl:apply-templates select="sequence" mode="main"/>

      <xsl:call-template name="class_body"/>

      <xsl:text>&#xa;&#xa;</xsl:text>
      <xsl:text>} //end of namespace&#xa;</xsl:text>
      <xsl:text>} //end of namespace&#xa;</xsl:text>
      <xsl:text>} //end of namespace&#xa;</xsl:text>
      <xsl:text>} //end of namespace&#xa;&#xa;</xsl:text>

    </xsl:if>
  </xsl:template>

  <xsl:template match="sequence" mode="main">
    <!-- nested sequence definitions -->
    <xsl:apply-templates select="sequence" mode="main"/>

    <xsl:call-template name="class_body"/>
  </xsl:template>

</xsl:stylesheet>
