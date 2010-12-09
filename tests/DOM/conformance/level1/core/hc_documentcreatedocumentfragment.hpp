
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

#ifndef test_hc_documentcreatedocumentfragment
#define test_hc_documentcreatedocumentfragment

#include "dom_conf_test.hpp"

/**
 *     The "createDocumentFragment()" method creates an empty 
 *    DocumentFragment object.
 *    Retrieve the entire DOM document and invoke its 
 *    "createDocumentFragment()" method.  The content, name, 
 *    type and value of the newly created object are output.
* @author Curt Arnold
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-35CB04B5">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-35CB04B5</a>
*/

template<class string_type, class string_adaptor>
class hc_documentcreatedocumentfragment : public DOMTestCase<string_type, string_adaptor> 
{
   public: 
     hc_documentcreatedocumentfragment(std::string name) : DOMTestCase(name)
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
      DocumentFragment newDocFragment;
      NodeList children;
      int length;
      String newDocFragmentName;
      int newDocFragmentType;
      String newDocFragmentValue;
      doc = (Document) load("hc_staff", true);
      newDocFragment = doc.createDocumentFragment();
      children = newDocFragment.getChildNodes();
      length = (int) children.getLength();
      assertEquals(0, length);
  newDocFragmentName = newDocFragment.getNodeName();
      assertEquals("#document-fragment", newDocFragmentName);
  newDocFragmentType = (int) newDocFragment.getNodeType();
      assertEquals(11, newDocFragmentType);
  newDocFragmentValue = newDocFragment.getNodeValue();
      assertNull(newDocFragmentValue);
      
   }
  
   /*
    *  Gets URI that identifies the test.
    */
   std::string getTargetURI() const
   {
      return "http://www.w3.org/2001/DOM-Test-Suite/level1/core/hc_documentcreatedocumentfragment";
   }
};

#endif
