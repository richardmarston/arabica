
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

#ifndef test_elementsetattributenodenomodificationallowederr
#define test_elementsetattributenodenomodificationallowederr

#include "dom_conf_test.hpp"

/**
 *     The "setAttributeNode(newAttr)" method for an attribute causes the 
 *    DOMException NO_MODIFICATION_ALLOWED_ERR to be raised
 *    if the node is readonly.
 *    
 *    Obtain the children of the THIRD "gender" element.  The elements
 *    content is an entity reference.  Try to remove the "domestic" attribute
 *    from the entity reference by executing the "setAttributeNode(newAttr)" method.
 *    This causes a NO_MODIFICATION_ALLOWED_ERR DOMException to be thrown.
* @author NIST
* @author Mary Brady
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#xpointer(id('ID-258A00AF')/constant[@name='NO_MODIFICATION_ALLOWED_ERR'])">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#xpointer(id('ID-258A00AF')/constant[@name='NO_MODIFICATION_ALLOWED_ERR'])</a>
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-887236154">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-887236154</a>
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#xpointer(id('ID-887236154')/raises/exception[@name='DOMException']/descr/p[substring-before(.,':')='NO_MODIFICATION_ALLOWED_ERR'])">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#xpointer(id('ID-887236154')/raises/exception[@name='DOMException']/descr/p[substring-before(.,':')='NO_MODIFICATION_ALLOWED_ERR'])</a>
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-887236154">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-887236154</a>
*/

template<class string_type, class string_adaptor>
class elementsetattributenodenomodificationallowederr : public DOMTestCase<string_type, string_adaptor> 
{
   public: 
     elementsetattributenodenomodificationallowederr(std::string name) : DOMTestCase(name)
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
      NodeList genderList;
      Node gender;
      Node entRef;
      Element entElement;
      Attr newAttr;
      int nodeType;
      Attr badAttr;
      doc = (Document) load("staff", true);
      genderList = doc.getElementsByTagName(SA::construct_from_utf8("gender"));
      gender = genderList.item(2);
      entRef = gender.getFirstChild();
      assertNotNull(entRef);
      nodeType = (int) entRef.getNodeType();
      
      if (equals(1, nodeType)) {
          entRef = doc.createEntityReference(SA::construct_from_utf8("ent4"));
      assertNotNull(entRef);
      }
    entElement = (Element) entRef.getFirstChild();
      assertNotNull(entElement);
      newAttr = doc.createAttribute(SA::construct_from_utf8("newAttr"));
      
      {
         boolean success = false;
         try {
            badAttr = entElement.setAttributeNode(newAttr);
          } catch (const DOMException& ex) {
            success = (ex.code() == DOMException::NO_MODIFICATION_ALLOWED_ERR);
         }
         assertTrue(success);
      }

   }
  
   /*
    *  Gets URI that identifies the test.
    */
   std::string getTargetURI() const
   {
      return "http://www.w3.org/2001/DOM-Test-Suite/level1/core/elementsetattributenodenomodificationallowederr";
   }
};

#endif
