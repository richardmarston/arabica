
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

#ifndef test_namednodemapremovenameditemgetvalue
#define test_namednodemapremovenameditemgetvalue

#include "dom_conf_test.hpp"

/**
 *     If the node removed by the "removeNamedItem(name)" method 
 *    is an Attr node with a default value it is immediately
 *    replaced. 
 *    
 *    Retrieve the third employee and create a NamedNodeMap 
 *    object of the attributes of the last child.  Once the
 *    list is created invoke the "removeNamedItem(name)"
 *    method with name="street".  The "removeNamedItem(name)"
 *    method should remove the "street" attribute and since
 *    it has a default value of "Yes", that value should
 *    immediately be the attributes value.
* @author NIST
* @author Mary Brady
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-D58B193">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-D58B193</a>
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-349467F9">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-349467F9</a>
* @see <a href="http://lists.w3.org/Archives/Public/www-dom-ts/2002Mar/0002.html">http://lists.w3.org/Archives/Public/www-dom-ts/2002Mar/0002.html</a>
*/

template<class string_type, class string_adaptor>
class namednodemapremovenameditemgetvalue : public DOMTestCase<string_type, string_adaptor> 
{
   public: 
     namednodemapremovenameditemgetvalue(std::string name) : DOMTestCase(name)
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
      Node testEmployee;
      NamedNodeMap attributes;
      Attr streetAttr;
      String value;
      Node removedNode;
      doc = (Document) load("staff", true);
      elementList = doc.getElementsByTagName(SA::construct_from_utf8("address"));
      testEmployee = elementList.item(2);
      attributes = testEmployee.getAttributes();
      assertNotNull(attributes);
      removedNode = attributes.removeNamedItem(SA::construct_from_utf8("street"));
      streetAttr = (Attr) attributes.getNamedItem(SA::construct_from_utf8("street"));
      assertNotNull(streetAttr);
      value = streetAttr.getValue();
      assertEquals("Yes", value);
  
   }
  
   /*
    *  Gets URI that identifies the test.
    */
   std::string getTargetURI() const
   {
      return "http://www.w3.org/2001/DOM-Test-Suite/level1/core/namednodemapremovenameditemgetvalue";
   }
};

#endif
