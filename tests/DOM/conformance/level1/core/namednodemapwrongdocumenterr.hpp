
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

#ifndef test_namednodemapwrongdocumenterr
#define test_namednodemapwrongdocumenterr

#include "dom_conf_test.hpp"

/**
 *     The "setNamedItem(arg)" method raises a 
 *    WRONG_DOCUMENT_ERR DOMException if "arg" was created
 *    from a different document than the one that created
 *    the NamedNodeMap. 
 *    
 *    Create a NamedNodeMap object from the attributes of the
 *    last child of the third employee and attempt to add
 *    another Attr node to it that was created from a 
 *    different DOM document.  This should raise the desired
 *    exception.  This method uses the "createAttribute(name)"
 *    method from the Document interface.
* @author NIST
* @author Mary Brady
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#xpointer(id('ID-258A00AF')/constant[@name='WRONG_DOCUMENT_ERR'])">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#xpointer(id('ID-258A00AF')/constant[@name='WRONG_DOCUMENT_ERR'])</a>
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-1025163788">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-1025163788</a>
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#xpointer(id('ID-1025163788')/raises/exception[@name='DOMException']/descr/p[substring-before(.,':')='WRONG_DOCUMENT_ERR'])">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#xpointer(id('ID-1025163788')/raises/exception[@name='DOMException']/descr/p[substring-before(.,':')='WRONG_DOCUMENT_ERR'])</a>
* @see <a href="http://www.w3.org/Bugs/Public/show_bug.cgi?id=249">http://www.w3.org/Bugs/Public/show_bug.cgi?id=249</a>
*/

template<class string_type, class string_adaptor>
class namednodemapwrongdocumenterr : public DOMTestCase<string_type, string_adaptor> 
{
   public: 
     namednodemapwrongdocumenterr(std::string name) : DOMTestCase(name)
     {

       //   check if loaded documents are supported for content type
       const std::string contentType = getContentType();
    preload(contentType, "staff", true);
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
      Document doc1;
      Document doc2;
      NodeList elementList;
      Node testAddress;
      NamedNodeMap attributes;
      Node newAttribute;
      Node setNode;
      doc1 = (Document) load("staff", true);
      doc2 = (Document) load("staff", true);
      elementList = doc1.getElementsByTagName(SA::construct_from_utf8("address"));
      testAddress = elementList.item(2);
      newAttribute = doc2.createAttribute(SA::construct_from_utf8("newAttribute"));
      attributes = testAddress.getAttributes();
      
      {
         boolean success = false;
         try {
            setNode = attributes.setNamedItem(newAttribute);
          } catch (const DOMException& ex) {
            success = (ex.code() == DOMException::WRONG_DOCUMENT_ERR);
         }
         assertTrue(success);
      }

   }
  
   /*
    *  Gets URI that identifies the test.
    */
   std::string getTargetURI() const
   {
      return "http://www.w3.org/2001/DOM-Test-Suite/level1/core/namednodemapwrongdocumenterr";
   }
};

#endif
