<?xml version="1.0"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">

  <!-- FileName: select22 -->
  <!-- Document: http://www.w3.org/TR/xpath -->
  <!-- DocVersion: 19991116 -->
  <!-- Section: 3.7 -->
  <!-- Creator: David Marston -->
  <!-- Purpose: * as first item must not be treated as an operator -->

<xsl:template match="doc">
  <out>
    <xsl:value-of select="* +3"/>
  </out>
</xsl:template>

</xsl:stylesheet>
