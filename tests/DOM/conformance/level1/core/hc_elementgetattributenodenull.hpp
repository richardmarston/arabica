
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

#ifndef test_hc_elementgetattributenodenull
#define test_hc_elementgetattributenodenull

#include "dom_conf_test.hpp"

/**
 *     The "getAttributeNode(name)" method retrieves an
 *    attribute node by name.  It should return null if the
 *    "strong" attribute does not exist.
 *    
 *    Retrieve the last child of the first employee and attempt
 *    to retrieve a non-existing attribute.  The method should
 *    return "null".  The non-existing attribute to be used
 *    is "invalidAttribute".
* @author Curt Arnold
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-217A91B8">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-217A91B8</a>
*/

template<class string_type, class string_adaptor>
class hc_elementgetattributenodenull : public DOMTestCase<string_type, string_adaptor> 
{
   public: 
     hc_elementgetattributenodenull(std::string name) : DOMTestCase(name)
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
      Attr domesticAttr;
      doc = (Document) load("hc_staff", true);
      elementList = doc.getElementsByTagName(SA::construct_from_utf8("acronym"));
      testEmployee = (Element) elementList.item(0);
      domesticAttr = testEmployee.getAttributeNode(SA::construct_from_utf8("invalidAttribute"));
      assertNull(domesticAttr);
      
   }
  
   /*
    *  Gets URI that identifies the test.
    */
   std::string getTargetURI() const
   {
      return "http://www.w3.org/2001/DOM-Test-Suite/level1/core/hc_elementgetattributenodenull";
   }
};

#endif
