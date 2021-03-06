<?xml version="1.0" encoding="ISO-8859-1"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">

  <!-- FileName: STR102 -->
  <!-- Document: http://www.w3.org/TR/xpath -->
  <!-- DocVersion: 19991116 -->
  <!-- Section: 4.2 String Functions  -->
  <!-- Purpose: Test of concat() on entities and expressions -->

<xsl:template match="doc">
  <out>
    <xsl:value-of select="concat(&#34;bc&#34;, string(23))"/>
  </out>
</xsl:template>

</xsl:stylesheet>