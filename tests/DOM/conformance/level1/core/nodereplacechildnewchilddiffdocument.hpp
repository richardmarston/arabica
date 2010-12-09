
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

#ifndef test_nodereplacechildnewchilddiffdocument
#define test_nodereplacechildnewchilddiffdocument

#include "dom_conf_test.hpp"

/**
 *     The "replaceChild(newChild,oldChild)" method raises a 
 *     WRONG_DOCUMENT_ERR DOMException if the "newChild" was
 *     created from a different document than the one that 
 *     created this node.
 *     
 *     Retrieve the second employee and attempt to replace one   
 *     of its children with a node created from a different 
 *     document.   An attempt to make such a replacement 
 *     should raise the desired exception.
* @author NIST
* @author Mary Brady
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#xpointer(id('ID-258A00AF')/constant[@name='NOT_FOUND_ERR'])">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#xpointer(id('ID-258A00AF')/constant[@name='NOT_FOUND_ERR'])</a>
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-785887307">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-785887307</a>
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#xpointer(id('ID-785887307')/raises/exception[@name='DOMException']/descr/p[substring-before(.,':')='NOT_FOUND_ERR'])">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#xpointer(id('ID-785887307')/raises/exception[@name='DOMException']/descr/p[substring-before(.,':')='NOT_FOUND_ERR'])</a>
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-785887307">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-785887307</a>
*/

template<class string_type, class string_adaptor>
class nodereplacechildnewchilddiffdocument : public DOMTestCase<string_type, string_adaptor> 
{
   public: 
     nodereplacechildnewchilddiffdocument(std::string name) : DOMTestCase(name)
     {

       //   check if loaded documents are supported for content type
       const std::string contentType = getContentType();
    preload(contentType, "staff", false);
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
      Node oldChild;
      Node newChild;
      NodeList elementList;
      Node elementNode;
      Node replacedChild;
      doc1 = (Document) load("staff", false);
      doc2 = (Document) load("staff", true);
      newChild = doc1.createElement(SA::construct_from_utf8("newChild"));
      elementList = doc2.getElementsByTagName(SA::construct_from_utf8("employee"));
      elementNode = elementList.item(1);
      oldChild = elementNode.getFirstChild();
      
      {
         boolean success = false;
         try {
            replacedChild = elementNode.replaceChild(newChild, oldChild);
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
      return "http://www.w3.org/2001/DOM-Test-Suite/level1/core/nodereplacechildnewchilddiffdocument";
   }
};

#endif
