
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

#ifndef test_documentcreateelementdefaultattr
#define test_documentcreateelementdefaultattr

#include "dom_conf_test.hpp"

/**
 *     The "createElement(tagName)" method creates an Element 
 *    of the type specified.  In addition, if there are known attributes
 *    with default values, Attr nodes representing them are automatically
 *    created and attached to the element.
 *    Retrieve the entire DOM document and invoke its 
 *    "createElement(tagName)" method with tagName="address".
 *    The method should create an instance of an Element node
 *    whose tagName is "address".  The tagName "address" has an 
 *    attribute with default values, therefore the newly created element
 *    will have them.  
* @author NIST
* @author Mary Brady
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-2141741547">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-2141741547</a>
* @see <a href="http://lists.w3.org/Archives/Public/www-dom-ts/2002Mar/0002.html">http://lists.w3.org/Archives/Public/www-dom-ts/2002Mar/0002.html</a>
*/

template<class string_type, class string_adaptor>
class documentcreateelementdefaultattr : public DOMTestCase<string_type, string_adaptor> 
{
   public: 
     documentcreateelementdefaultattr(std::string name) : DOMTestCase(name)
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
      Element newElement;
      NamedNodeMap defaultAttr;
      Node child;
      String name;
      String value;
      doc = (Document) load("staff", true);
      newElement = doc.createElement(SA::construct_from_utf8("address"));
      defaultAttr = newElement.getAttributes();
      child = defaultAttr.item(0);
      assertNotNull(child);
      name = child.getNodeName();
      assertEquals("street", name);
  value = child.getNodeValue();
      assertEquals("Yes", value);
  assertSize(1, defaultAttr);
      
   }
  
   /*
    *  Gets URI that identifies the test.
    */
   std::string getTargetURI() const
   {
      return "http://www.w3.org/2001/DOM-Test-Suite/level1/core/documentcreateelementdefaultattr";
   }
};

#endif
