
/*
This c++ source file was generated by for Arabica
and is a derived work from the source document.
The source document contained the following notice:


Copyright (c) 2001 World Wide Web Consortium,
(Massachusetts Institute of Technology, Institut National de
Recherche en Informatique et en Automatique, Keio University). All
Rights Reserved. This program is distributed under the W3C's Software
Intellectual Property License. This program is distributed in the
hope that it will be useful, but WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.
See W3C License http://www.w3.org/Consortium/Legal/ for more details.

*/

#ifndef test_characterdatareplacedatamiddle
#define test_characterdatareplacedatamiddle

#include "dom_conf_test.hpp"

/**
 *     The "replaceData(offset,count,arg)" method replaces the 
 *    characters starting at the specified offset with the
 *    specified string.  Test for replacement in the 
 *    middle of the data.
 *    
 *    Retrieve the character data from the last child of the
 *    first employee.  The "replaceData(offset,count,arg)"
 *    method is then called with offset=5 and count=5 and
 *    arg="South".  The method should replace characters five  
 *    thru 9 of the character data with "South".
* @author NIST
* @author Mary Brady
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-72AB8359">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-72AB8359</a>
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-E5CBA7FB">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-E5CBA7FB</a>
*/

template<class string_type, class string_adaptor>
class characterdatareplacedatamiddle : public DOMTestCase<string_type, string_adaptor> 
{
   public: 
     characterdatareplacedatamiddle(std::string name) : DOMTestCase(name)
     {

       //   check if loaded documents are supported for content type
       const std::string contentType = getContentType();
    preload(contentType, "staff", true);
    }

  typedef typename DOMTestCase<string_type, string_adaptor> baseT;
  using baseT::DOMImplementation;
  using baseT::Document; 
  using baseT::DocumentType;
  using baseT::DocumentFragment; 
  using baseT::Node;
  using baseT::Element;
  using baseT::Attr;
  using baseT::NodeList;
  using baseT::NamedNodeMap;
  using baseT::Entity;
  using baseT::EntityReference;
  using baseT::CharacterData;
  using baseT::CDATASection;
  using baseT::Text;
  using baseT::Comment;
  using baseT::ProcessingInstruction;
  using baseT::Notation;

  typedef typename Arabica::DOM::DOMException DOMException;
  typedef string_type String;
  typedef string_adaptor SA;
  typedef bool boolean;

   /*
    * Runs the test case.
    */
   void runTest()
   {
      Document doc;
      NodeList elementList;
      Node nameNode;
      CharacterData child;
      String childData;
      doc = (Document) load("staff", true);
      elementList = doc.getElementsByTagName(SA::construct_from_utf8("address"));
      nameNode = elementList.item(0);
      child = (CharacterData) nameNode.getFirstChild();
      child.replaceData(5, 5, SA::construct_from_utf8("South"));
      childData = child.getData();
      assertEquals("1230 South Ave. Dallas, Texas 98551", childData);
  
   }
  
   /*
    *  Gets URI that identifies the test.
    */
   std::string getTargetURI() const
   {
      return "http://www.w3.org/2001/DOM-Test-Suite/level1/core/characterdatareplacedatamiddle";
   }
};

#endif
