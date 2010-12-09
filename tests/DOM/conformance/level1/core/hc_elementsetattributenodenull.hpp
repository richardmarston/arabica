
/*
This c++ source file was generated by for Arabica
and is a derived work from the source document.
The source document contained the following notice:


Copyright (c) 2001-2003 World Wide Web Consortium,
(Massachusetts Institute of Technology, Institut National de
Recherche en Informatique et en Automatique, Keio University). All
Rights Reserved. This program is distributed under the W3C's Software
Intellectual Property License. This program is distributed in the
hope that it will be useful, but WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.
See W3C License http://www.w3.org/Consortium/Legal/ for more details.

*/

#ifndef test_hc_elementsetattributenodenull
#define test_hc_elementsetattributenodenull

#include "dom_conf_test.hpp"

/**
 *     The "setAttributeNode(newAttr)" method returns the
 *    null value if no previously existing Attr node with the
 *    same name was replaced.
 *    
 *    Retrieve the last child of the third employee and add a 
 *    new attribute to it.  The new attribute node added is 
 *    "lang", which is not part of this Element.  The   
 *    method should return the null value.   
 *    This test uses the "createAttribute(name)"
 *    method from the Document interface. 
* @author Curt Arnold
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-887236154">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-887236154</a>
* @see <a href="http://www.w3.org/Bugs/Public/show_bug.cgi?id=243">http://www.w3.org/Bugs/Public/show_bug.cgi?id=243</a>
*/

template<class string_type, class string_adaptor>
class hc_elementsetattributenodenull : public DOMTestCase<string_type, string_adaptor> 
{
   public: 
     hc_elementsetattributenodenull(std::string name) : DOMTestCase(name)
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
      Element testEmployee;
      Attr newAttribute;
      Attr districtAttr;
      doc = (Document) load("hc_staff", true);
      elementList = doc.getElementsByTagName(SA::construct_from_utf8("acronym"));
      testEmployee = (Element) elementList.item(2);
      newAttribute = doc.createAttribute(SA::construct_from_utf8("lang"));
      districtAttr = testEmployee.setAttributeNode(newAttribute);
      assertNull(districtAttr);
      
   }
  
   /*
    *  Gets URI that identifies the test.
    */
   std::string getTargetURI() const
   {
      return "http://www.w3.org/2001/DOM-Test-Suite/level1/core/hc_elementsetattributenodenull";
   }
};

#endif
