
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

#ifndef test_nodegetownerdocument
#define test_nodegetownerdocument

#include "dom_conf_test.hpp"

/**
 *     The "getOwnerDocument()" method returns the Document
 *     object associated with this node.
 *     
 *     Retrieve the second employee and examine Document 
 *     returned by the "getOwnerDocument()" method.   Invoke
 *     the "getDocumentElement()" on the Document which will
 *     return an Element that is equal to "staff".
* @author NIST
* @author Mary Brady
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#node-ownerDoc">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#node-ownerDoc</a>
* @see <a href="http://www.w3.org/Bugs/Public/show_bug.cgi?id=251">http://www.w3.org/Bugs/Public/show_bug.cgi?id=251</a>
*/

template<class string_type, class string_adaptor>
class nodegetownerdocument : public DOMTestCase<string_type, string_adaptor> 
{
   public: 
     nodegetownerdocument(std::string name) : DOMTestCase(name)
     {

       //   check if loaded documents are supported for content type
       const std::string contentType = getContentType();
    preload(contentType, "staff", false);
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
      Node docNode;
      Document ownerDocument;
      Element docElement;
      String elementName;
      doc = (Document) load("staff", false);
      elementList = doc.getElementsByTagName(SA::construct_from_utf8("employee"));
      docNode = elementList.item(1);
      ownerDocument = docNode.getOwnerDocument();
      docElement = ownerDocument.getDocumentElement();
      elementName = docElement.getNodeName();
      
      if (("image/svg+xml" == getContentType())) {
          assertEquals("svg", elementName);
  } else {
          assertEquals("staff", elementName);
  }
        
    
   }
  
   /*
    *  Gets URI that identifies the test.
    */
   std::string getTargetURI() const
   {
      return "http://www.w3.org/2001/DOM-Test-Suite/level1/core/nodegetownerdocument";
   }
};

#endif
