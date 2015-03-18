<xsl:stylesheet version='1.0'
              xmlns:xsl='http://www.w3.org/1999/XSL/Transform'>

  <xsl:output method="text"/>
  <xsl:strip-space elements="*"/>

  <xsl:variable name="lowercase" select="'abcdefghijklmnopqrstuvwxyz'" />
  <xsl:variable name="uppercase" select="'ABCDEFGHIJKLMNOPQRSTUVWXYZ'" />

  <xsl:param name="message_name" select="message_name"/>

  <xsl:variable name="sequence_type" select="'uint32_t'"/>
  <xsl:variable name="min_size" select="'500'"/>

  <xsl:template match="sequence" mode="hierarchy_serializer">
    <xsl:apply-templates select="parent::sequence" mode="hierarchy_serializer"/>

    <xsl:text>::</xsl:text>
    <xsl:value-of select="translate(@name, $uppercase, $lowercase)"/>
    <xsl:if test="local-name()='sequence'">
      <xsl:text>_entry_serializer</xsl:text>
    </xsl:if>
  </xsl:template>

  <xsl:template match="sequence" mode="hierarchy_entry">
    <xsl:apply-templates select="parent::sequence" mode="hierarchy_entry"/>

    <xsl:text>::</xsl:text>
    <xsl:value-of select="translate(@name, $uppercase, $lowercase)"/>
    <xsl:if test="local-name()='sequence'">
      <xsl:text>_entry</xsl:text>
    </xsl:if>
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
    </xsl:choose>
  </xsl:template>

  <xsl:template name="class_body">
    <xsl:if test="local-name()='sequence'">
      <xsl:value-of select="ancestor::template/@name"/>
      <xsl:text>_serializer</xsl:text>
      <xsl:apply-templates select="parent::sequence" mode="hierarchy_serializer"/>
      <xsl:text>::</xsl:text>
    </xsl:if>
    <xsl:value-of select="@name"/>
    <xsl:if test="local-name()='sequence'">
      <xsl:text>_entry</xsl:text>
    </xsl:if>
    <xsl:text>_serializer::</xsl:text>
    <xsl:value-of select="@name"/>
    <xsl:if test="local-name()='sequence'">
      <xsl:text>_entry</xsl:text>
    </xsl:if>
    <xsl:text>_serializer()&#xa;{&#xa;  </xsl:text>
    <xsl:text>data_.resize( </xsl:text>
    <xsl:value-of select="$min_size"/>
    <xsl:text> +&#xa;</xsl:text>
    <xsl:text>    offset_variable_fields</xsl:text>
    <xsl:for-each select="sequence">
      <xsl:text> +&#xa;    </xsl:text>
      <xsl:value-of select="@name"/>
      <xsl:text>_entry</xsl:text>
      <xsl:text>_serializer_.buffer_size()</xsl:text>
    </xsl:for-each>
    <xsl:for-each select="field[@ref]">
      <xsl:text> +&#xa;    </xsl:text>
      <xsl:value-of select="@name"/>
      <xsl:text>_serializer_.buffer_size()</xsl:text>
    </xsl:for-each>
    <xsl:text> );&#xa;</xsl:text>
    <xsl:text>}&#xa;&#xa;</xsl:text>

    <xsl:text>std::pair&lt;const unsigned char*, std::size_t&gt;&#xa;</xsl:text>
    <xsl:if test="local-name()='sequence'">
      <xsl:value-of select="ancestor::template/@name"/>
      <xsl:text>_serializer</xsl:text>
      <xsl:apply-templates select="parent::sequence" mode="hierarchy_serializer"/>
      <xsl:text>::</xsl:text>
    </xsl:if>
    <xsl:value-of select="@name"/>
    <xsl:if test="local-name()='sequence'">
      <xsl:text>_entry</xsl:text>
    </xsl:if>
    <xsl:text>_serializer::serialize( &#xa;  const messages::</xsl:text>
    <xsl:if test="local-name()='sequence'">
      <xsl:value-of select="ancestor::template/@name"/>
      <xsl:apply-templates select="parent::sequence" mode="hierarchy_entry"/>
      <xsl:text>::</xsl:text>
    </xsl:if>
    <xsl:value-of select="@name"/>
    <xsl:if test="local-name()='sequence'">
      <xsl:text>_entry</xsl:text>
    </xsl:if>
    <xsl:text>&amp; msg )&#xa;{&#xa;</xsl:text>
    <xsl:text>  std::size_t offset = offset_variable_fields;&#xa;&#xa;</xsl:text>

    <xsl:choose>
      <xsl:when test="count(*) &gt; 32">
        <xsl:text>  byte_conversion::uint64_to_be(data_.data(), msg.presence_map().to_ullong());&#xa;</xsl:text>
      </xsl:when>
      <xsl:otherwise>
        <xsl:text>  byte_conversion::uint32_to_be(data_.data(), msg.presence_map().to_ulong());&#xa;</xsl:text>
      </xsl:otherwise>
    </xsl:choose>

    <xsl:for-each select="field">
      <xsl:variable name="field_name" select="@name"/>
      <xsl:variable name="field_type" select="//fields/field[@name=$field_name]/@type"/>

      <xsl:choose>
        <xsl:when test="@ref='single'">
          <xsl:text>  offset += serialize_reference_field(msg.</xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>(), </xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>_serializer_, data_, offset_</xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>, offset);&#xa;</xsl:text>
        </xsl:when>
        <xsl:when test="@ref='multiple'">
          <xsl:text>  offset += serialize_sequence(msg.</xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>s(), </xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>_serializer_, data_, offset_</xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>, offset);&#xa;</xsl:text>
        </xsl:when>
        <xsl:when test="$field_type='decimal'">
          <xsl:text>  byte_conversion::uint64</xsl:text>
          <xsl:text>_to_be(data_.data() + offset_</xsl:text>
          <xsl:value-of select="$field_name"/>
          <xsl:text>_mantissa, msg.</xsl:text>
          <xsl:value-of select="$field_name"/>
          <xsl:text>().second.mantissa());&#xa;</xsl:text>

          <xsl:text>  byte_conversion::uint8</xsl:text>
          <xsl:text>_to_be(data_.data() + offset_</xsl:text>
          <xsl:value-of select="$field_name"/>
          <xsl:text>_exponent, msg.</xsl:text>
          <xsl:value-of select="$field_name"/>
          <xsl:text>().second.exponent());&#xa;</xsl:text>
        </xsl:when>
        <xsl:when test="$field_type='string'">
          <xsl:text>  offset += serialize_string_field(msg.</xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>(), data_, offset_</xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>, offset);&#xa;</xsl:text>
        </xsl:when>
        <xsl:when test="$field_type='multistring'">
          <xsl:text>  byte_conversion::uint32</xsl:text>
          <xsl:text>_to_be(data_.data() + offset_</xsl:text>
          <xsl:value-of select="$field_name"/>
          <xsl:text>, msg.</xsl:text>
          <xsl:value-of select="$field_name"/>
          <xsl:text>().second);&#xa;</xsl:text>
        </xsl:when>
        <xsl:otherwise>
          <xsl:text>  byte_conversion::</xsl:text>
          <xsl:value-of select="$field_type"/>
          <xsl:text>_to_be(data_.data() + offset_</xsl:text>
          <xsl:value-of select="$field_name"/>
          <xsl:text>, msg.</xsl:text>
          <xsl:value-of select="$field_name"/>
          <xsl:text>().second);&#xa;</xsl:text>
        </xsl:otherwise>
      </xsl:choose>
    </xsl:for-each>

    <xsl:for-each select="sequence">
      <xsl:text>  offset += serialize_sequence(msg.</xsl:text>
      <xsl:value-of select="@name"/>
      <xsl:text>s(), </xsl:text>
      <xsl:value-of select="@name"/>
      <xsl:text>_entry</xsl:text>
      <xsl:text>_serializer_, data_, offset_</xsl:text>
      <xsl:value-of select="@name"/>
      <xsl:text>, offset);&#xa;</xsl:text>
    </xsl:for-each>

    <xsl:text>&#xa;</xsl:text>
    <xsl:text>  return std::make_pair(data_.data(), offset);&#xa;}&#xa;&#xa;</xsl:text>

    <xsl:text>std::size_t&#xa;</xsl:text>
    <xsl:if test="local-name()='sequence'">
      <xsl:value-of select="ancestor::template/@name"/>
      <xsl:text>_serializer</xsl:text>
      <xsl:apply-templates select="parent::sequence" mode="hierarchy_serializer"/>
      <xsl:text>::</xsl:text>
    </xsl:if>
    <xsl:value-of select="@name"/>
    <xsl:if test="local-name()='sequence'">
      <xsl:text>_entry</xsl:text>
    </xsl:if>
    <xsl:text>_serializer::buffer_size() const&#xa;{&#xa;</xsl:text>
    <xsl:text>  return data_.size();&#xa;}&#xa;&#xa;</xsl:text>

    <xsl:text>std::size_t&#xa;</xsl:text>
    <xsl:if test="local-name()='sequence'">
      <xsl:value-of select="ancestor::template/@name"/>
      <xsl:text>_serializer</xsl:text>
      <xsl:apply-templates select="parent::sequence" mode="hierarchy_serializer"/>
      <xsl:text>::</xsl:text>
    </xsl:if>
    <xsl:value-of select="@name"/>
    <xsl:if test="local-name()='sequence'">
      <xsl:text>_entry</xsl:text>
    </xsl:if>
    <xsl:text>_serializer::deserialize( const unsigned char* data, &#xa;  messages::</xsl:text>
    <xsl:if test="local-name()='sequence'">
      <xsl:value-of select="ancestor::template/@name"/>
      <xsl:apply-templates select="parent::sequence" mode="hierarchy_entry"/>
      <xsl:text>::</xsl:text>
    </xsl:if>
    <xsl:value-of select="@name"/>
    <xsl:if test="local-name()='sequence'">
      <xsl:text>_entry</xsl:text>
    </xsl:if>
    <xsl:text>&amp; dst)&#xa;{&#xa;</xsl:text>
    <xsl:text>  decimal d;&#xa;</xsl:text>
    <xsl:text>  std::size_t offset = offset_variable_fields;&#xa;</xsl:text>
    <xsl:text>&#xa;</xsl:text>

    <xsl:choose>
      <xsl:when test="count(*) &gt; 32">
        <xsl:text>  dst.set_presence_map(byte_conversion::be_to_uint64(data + offset_pmap));&#xa;</xsl:text>
      </xsl:when>
      <xsl:otherwise>
        <xsl:text>  dst.set_presence_map(byte_conversion::be_to_uint32(data + offset_pmap));&#xa;</xsl:text>
      </xsl:otherwise>
    </xsl:choose>

    <xsl:for-each select="field">
      <xsl:variable name="field_name" select="@name"/>
      <xsl:variable name="field_type" select="//fields/field[@name=$field_name]/@type"/>

      <xsl:choose>
        <xsl:when test="@ref='single'">
          <xsl:text>&#xa;</xsl:text>
          <xsl:text>  if(dst.presence_map()[messages::</xsl:text>
           <xsl:value-of select="../@name"/>
           <xsl:text>::ix_</xsl:text>
           <xsl:value-of select="@name"/>
           <xsl:text>])&#xa;  {&#xa;</xsl:text>
           <xsl:text>    messages::</xsl:text>
           <xsl:value-of select="@name"/>
           <xsl:text> msg;&#xa;</xsl:text>
           <xsl:text>    offset += </xsl:text>
           <xsl:value-of select="@name"/>
           <xsl:text>_serializer_.deserialize( data + offset, msg );&#xa;</xsl:text>
           <xsl:text>    dst.set_</xsl:text>
           <xsl:value-of select="@name"/>
           <xsl:text>( msg );&#xa;  }&#xa;&#xa;</xsl:text>

        </xsl:when>

        <xsl:when test="@ref='multiple'">
          <xsl:text>&#xa;</xsl:text>
          <xsl:text>  if(dst.presence_map()[messages::</xsl:text>
          <xsl:value-of select="../@name"/>
          <xsl:text>::ix_</xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>])&#xa;  {&#xa;</xsl:text>
          <xsl:text>    std::size_t entries = byte_conversion::be_to_uint32(data + offset_</xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>);&#xa;    messages::</xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text> entry;&#xa;&#xa;</xsl:text>
          <xsl:text>    for (std::size_t i = 0; i &lt; entries; i++ )&#xa;    {&#xa;</xsl:text>
          <xsl:text>      offset += </xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>_serializer_.deserialize( data + offset, entry );&#xa;</xsl:text>
          <xsl:text>      dst.add_</xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>( entry );&#xa;      entry.reset();&#xa;    }&#xa;</xsl:text>
          <xsl:text>  }&#xa;</xsl:text>
        </xsl:when>
        <xsl:when test="$field_type='decimal'">
          <xsl:text>  d.set_mantissa(byte_conversion::be_to_uint64(data + offset_</xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>_mantissa));&#xa;</xsl:text>

          <xsl:text>  d.set_exponent(byte_conversion::be_to_uint8(data + offset_</xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>_exponent));&#xa;</xsl:text>

          <xsl:text>  dst.set_</xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>(d);&#xa;</xsl:text>
        </xsl:when>
        <xsl:when test="$field_type='string'">
          <xsl:text>&#xa;</xsl:text>
          <xsl:text>  if(dst.presence_map()[messages::</xsl:text>
          <xsl:if test="local-name(..)='sequence'">
            <xsl:value-of select="ancestor::template/@name"/>
            <xsl:apply-templates select="parent::sequence" mode="hierarchy_entry"/>
          </xsl:if>
          <xsl:if test="local-name(..)!='sequence'">
            <xsl:value-of select="../@name"/>
          </xsl:if>
          <xsl:text>::ix_</xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>])&#xa;  {&#xa;</xsl:text>
          <xsl:text>    dst.set_</xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>(deserialize_string_field(data, offset_</xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>, offset));&#xa;</xsl:text>
          <xsl:text>    offset += dst.</xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>().second.size();&#xa;</xsl:text>
          <xsl:text>  }&#xa;&#xa;</xsl:text>
        </xsl:when>
        <xsl:when test="$field_type='multistring'">
          <xsl:text>  dst.set_</xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>(byte_conversion::be_to_uint32</xsl:text>
          <xsl:text>(data + offset_</xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>));&#xa;</xsl:text>
        </xsl:when>
        <xsl:otherwise>
          <xsl:text>  dst.set_</xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>(byte_conversion::be_to_</xsl:text>
          <xsl:value-of select="$field_type"/>
          <xsl:text>(data + offset_</xsl:text>
          <xsl:value-of select="@name"/>
          <xsl:text>));&#xa;</xsl:text>
        </xsl:otherwise>
      </xsl:choose>
    </xsl:for-each>

    <xsl:for-each select="sequence">
      <xsl:text>&#xa;</xsl:text>
      <xsl:text>  if(dst.presence_map()[messages::</xsl:text>
      <xsl:value-of select="ancestor::template/@name"/>
      <xsl:apply-templates select="parent::sequence" mode="hierarchy_entry"/>
      <xsl:text>::ix_</xsl:text>
      <xsl:value-of select="@name"/>
      <xsl:text>])&#xa;  {&#xa;</xsl:text>
      <xsl:text>    std::size_t entries = byte_conversion::be_to_uint32(data + offset_</xsl:text>
      <xsl:value-of select="@name"/>
      <xsl:text>);&#xa;    messages::</xsl:text>
      <xsl:value-of select="ancestor::template/@name"/>
      <xsl:apply-templates select="parent::sequence" mode="hierarchy_entry"/>
      <xsl:text>::</xsl:text>
      <xsl:value-of select="@name"/>
      <xsl:text>_entry entry;&#xa;&#xa;</xsl:text>
      <xsl:text>    for (std::size_t i = 0; i &lt; entries; i++ )&#xa;    {&#xa;</xsl:text>
      <xsl:text>      offset += </xsl:text>
      <xsl:value-of select="@name"/>
      <xsl:if test="local-name()='sequence'">
        <xsl:text>_entry</xsl:text>
      </xsl:if>
      <xsl:text>_serializer_.deserialize( data + offset, entry );&#xa;</xsl:text>
      <xsl:text>      dst.add_</xsl:text>
      <xsl:value-of select="@name"/>
      <xsl:text>( entry );&#xa;      entry.reset();&#xa;    }&#xa;</xsl:text>
      <xsl:text>  }&#xa;</xsl:text>
    </xsl:for-each>

    <xsl:text>&#xa;</xsl:text>
    <xsl:text>  return offset;&#xa;</xsl:text>
    <xsl:text>}&#xa;&#xa;</xsl:text>
  </xsl:template>

  <xsl:template match="template">
    <xsl:if test="@name=$message_name">

      <xsl:text>#include &lt;msi/msi_pch.hpp&gt;&#xa;</xsl:text>
      <xsl:text>#include &lt;msi/byte_conversion.hpp&gt;&#xa;</xsl:text>
      <xsl:text>#include &lt;msi/marketdata/serialization/sequence_serializer.hpp&gt;&#xa;</xsl:text>
      <xsl:text>#include &lt;msi/marketdata/serialization/string_serializer.hpp&gt;&#xa;</xsl:text>
      <xsl:text>#include &lt;msi/marketdata/serialization/reference_field_serializer.hpp&gt;&#xa;</xsl:text>
      <xsl:text>#include &lt;msi/marketdata/serialization/</xsl:text>
      <xsl:value-of select="@name"/>
      <xsl:text>_serializer.hpp&gt;&#xa;&#xa;</xsl:text>
      <xsl:text>namespace apoena&#xa;{&#xa;</xsl:text>
      <xsl:text>namespace msi&#xa;{&#xa;</xsl:text>
      <xsl:text>namespace marketdata&#xa;{&#xa;</xsl:text>
      <xsl:text>namespace serialization&#xa;{&#xa;&#xa;</xsl:text>

      <!--inner classes representing sequences --> 
      <xsl:apply-templates select="sequence"/>

      <xsl:call-template name="class_body"/>

      <xsl:text>} //end of namespace&#xa;</xsl:text>
      <xsl:text>} //end of namespace&#xa;</xsl:text>
      <xsl:text>} //end of namespace&#xa;</xsl:text>
      <xsl:text>} //end of namespace&#xa;&#xa;</xsl:text>

    </xsl:if>
  </xsl:template>

  <xsl:template match="sequence">
    <!-- nested sequence definitions -->
    <xsl:apply-templates select="sequence"/>

    <xsl:call-template name="class_body"/>

    <xsl:text>&#xa;&#xa;</xsl:text>
  </xsl:template>

</xsl:stylesheet>
