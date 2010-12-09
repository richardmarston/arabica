
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

#ifndef test_elementremoveattributerestoredefaultvalue
#define test_elementremoveattributerestoredefaultvalue

#include "dom_conf_test.hpp"

/**
 *     The "removeAttributeNode(oldAttr)" method removes the
 *    specified attribute node and restores any default values. 
 *    
 *    Retrieve the last child of the third employeed and 
 *    remove its "street" Attr node.  Since this node has a
 *    default value defined in the DTD file, that default
 *    should immediately be the new value.
* @author NIST
* @author Mary Brady
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-D589198">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-D589198</a>
* @see <a href="http://lists.w3.org/Archives/Public/www-dom-ts/2002Mar/0002.html">http://lists.w3.org/Archives/Public/www-dom-ts/2002Mar/0002.html</a>
*/

template<class string_type, class string_adaptor>
class elementremoveattributerestoredefaultvalue : public DOMTestCase<string_type, string_adaptor> 
{
   public: 
     elementremoveattributerestoredefaultvalue(std::string name) : DOMTestCase(name)
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
      Element testEmployee;
      Attr streetAttr;
      String attribute;
      Attr removedAttr;
      doc = (Document) load("staff", true);
      elementList = doc.getElementsByTagName(SA::construct_from_utf8("address"));
      testEmployee = (Element) elementList.item(2);
      streetAttr = testEmployee.getAttributeNode(SA::construct_from_utf8("street"));
      removedAttr = testEmployee.removeAttributeNode(streetAttr);
      attribute = testEmployee.getAttribute(SA::construct_from_utf8("street"));
      assertEquals("Yes", attribute);
  
   }
  
   /*
    *  Gets URI that identifies the test.
    */
   std::string getTargetURI() const
   {
      return "http://www.w3.org/2001/DOM-Test-Suite/level1/core/elementremoveattributerestoredefaultvalue";
   }
};

#endif
