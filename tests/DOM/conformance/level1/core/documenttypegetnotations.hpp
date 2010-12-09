
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

#ifndef test_documenttypegetnotations
#define test_documenttypegetnotations

#include "dom_conf_test.hpp"

/**
 *     The "getNotations()" method creates a NamedNodeMap that   
 *    contains all the notations declared in the DTD.
 *    
 *    Retrieve the Document Type for this document and create
 *    a NamedNodeMap object of all the notations.  There
 *    should be two items in the list (notation1 and notation2).
* @author NIST
* @author Mary Brady
* @author Curt Arnold
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-D46829EF">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-D46829EF</a>
*/

template<class string_type, class string_adaptor>
class documenttypegetnotations : public DOMTestCase<string_type, string_adaptor> 
{
   public: 
     documenttypegetnotations(std::string name) : DOMTestCase(name)
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
      DocumentType docType;
      NamedNodeMap notationList;
      Node notation;
      String notationName;
      std::vector<string_type> actual;
      
      std::vector<string_type> expected;
      expected.push_back(SA::construct_from_utf8("notation1"));
      expected.push_back(SA::construct_from_utf8("notation2"));
      
      doc = (Document) load("staff", false);
      docType = doc.getDoctype();
      assertNotNull(docType);
      notationList = docType.getNotations();
      assertNotNull(notationList);
      for (int indexN65627 = 0; indexN65627 != notationList.getLength(); indexN65627++) {
          notation = (Node) notationList.item(indexN65627);
    notationName = notation.getNodeName();
      actual.push_back(notationName);
        }
      assertEquals(expected, actual);
  
   }
  
   /*
    *  Gets URI that identifies the test.
    */
   std::string getTargetURI() const
   {
      return "http://www.w3.org/2001/DOM-Test-Suite/level1/core/documenttypegetnotations";
   }
};

#endif
