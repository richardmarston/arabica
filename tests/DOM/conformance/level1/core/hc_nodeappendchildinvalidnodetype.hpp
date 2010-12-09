
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

#ifndef test_hc_nodeappendchildinvalidnodetype
#define test_hc_nodeappendchildinvalidnodetype

#include "dom_conf_test.hpp"

/**
 *     The "appendChild(newChild)" method raises a 
 *     HIERARCHY_REQUEST_ERR DOMException if this node is of
 *     a type that does not allow children of the type "newChild"
 *     to be inserted.
 *     
 *     Retrieve the root node and attempt to append a newly
 *     created Attr node.   An Element node cannot have children
 *     of the "Attr" type, therefore the desired exception
 *     should be raised.
* @author Curt Arnold
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#xpointer(id('ID-258A00AF')/constant[@name='HIERARCHY_REQUEST_ERR'])">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#xpointer(id('ID-258A00AF')/constant[@name='HIERARCHY_REQUEST_ERR'])</a>
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-184E7107">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-184E7107</a>
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#xpointer(id('ID-184E7107')/raises/exception[@name='DOMException']/descr/p[substring-before(.,':')='HIERARCHY_REQUEST_ERR'])">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#xpointer(id('ID-184E7107')/raises/exception[@name='DOMException']/descr/p[substring-before(.,':')='HIERARCHY_REQUEST_ERR'])</a>
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-184E7107">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-184E7107</a>
* @see <a href="http://www.w3.org/Bugs/Public/show_bug.cgi?id=249">http://www.w3.org/Bugs/Public/show_bug.cgi?id=249</a>
*/

template<class string_type, class string_adaptor>
class hc_nodeappendchildinvalidnodetype : public DOMTestCase<string_type, string_adaptor> 
{
   public: 
     hc_nodeappendchildinvalidnodetype(std::string name) : DOMTestCase(name)
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
      Element rootNode;
      Node newChild;
      Node appendedChild;
      doc = (Document) load("hc_staff", true);
      rootNode = doc.getDocumentElement();
      newChild = doc.createAttribute(SA::construct_from_utf8("newAttribute"));
      
      {
         boolean success = false;
         try {
            appendedChild = rootNode.appendChild(newChild);
          } catch (const DOMException& ex) {
            success = (ex.code() == DOMException::HIERARCHY_REQUEST_ERR);
         }
         assertTrue(success);
      }

   }
  
   /*
    *  Gets URI that identifies the test.
    */
   std::string getTargetURI() const
   {
      return "http://www.w3.org/2001/DOM-Test-Suite/level1/core/hc_nodeappendchildinvalidnodetype";
   }
};

#endif
