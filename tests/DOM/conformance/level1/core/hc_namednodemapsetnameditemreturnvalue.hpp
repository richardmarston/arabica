
/*
This c++ source file was generated by for Arabica
and is a derived work from the source document.
The source document contained the following notice:


Copyright (c) 2001-2004 World Wide Web Consortium,
(Massachusetts Institute of Technology, Institut National de
Recherche en Informatique et en Automatique, Keio University). All
Rights Reserved. This program is distributed under the W3C's Software
Intellectual Property License. This program is distributed in the
hope that it will be useful, but WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.
See W3C License http://www.w3.org/Consortium/Legal/ for more details.

*/

#ifndef test_hc_namednodemapsetnameditemreturnvalue
#define test_hc_namednodemapsetnameditemreturnvalue

#include "dom_conf_test.hpp"

/**
 *     If the "setNamedItem(arg)" method replaces an already 
 *    existing node with the same name then the already 
 *    existing node is returned.
 *    
 *    Retrieve the third employee and create a NamedNodeMap 
 *    object from the attributes of the last child by
 *    invoking the "getAttributes()" method.  Once the
 *    list is created an invocation of the "setNamedItem(arg)"
 *    method is done with arg=newAttr, where newAttr is a
 *    new Attr Node previously created and whose node name
 *    already exists in the map.  The "setNamedItem(arg)"
 *    method should replace the already existing node with
 *    the new one and return the existing node.   
 *    This test uses the "createAttribute(name)" method from
 *    the document interface.
* @author Curt Arnold
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-1025163788">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-1025163788</a>
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-349467F9">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-349467F9</a>
*/

template<class string_type, class string_adaptor>
class hc_namednodemapsetnameditemreturnvalue : public DOMTestCase<string_type, string_adaptor> 
{
   public: 
     hc_namednodemapsetnameditemreturnvalue(std::string name) : DOMTestCase(name)
     {

       //   check if loaded documents are supported for content type
       const std::string contentType = getContentType();
    preload(contentType, "hc_staff", true);
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
      Attr newAttribute;
      Node testAddress;
      NamedNodeMap attributes;
      Node newNode;
      String attrValue;
      doc = (Document) load("hc_staff", true);
      elementList = doc.getElementsByTagName(SA::construct_from_utf8("acronym"));
      testAddress = elementList.item(2);
      newAttribute = doc.createAttribute(SA::construct_from_utf8("class"));
      attributes = testAddress.getAttributes();
      newNode = attributes.setNamedItem(newAttribute);
      assertNotNull(newNode);
      attrValue = newNode.getNodeValue();
      assertEquals("No", attrValue);
  
   }
  
   /*
    *  Gets URI that identifies the test.
    */
   std::string getTargetURI() const
   {
      return "http://www.w3.org/2001/DOM-Test-Suite/level1/core/hc_namednodemapsetnameditemreturnvalue";
   }
};

#endif
