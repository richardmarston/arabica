
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

#ifndef test_hc_nodeappendchilddocfragment
#define test_hc_nodeappendchilddocfragment

#include "dom_conf_test.hpp"

/**
 *     If the "newChild" is a DocumentFragment object then
 *     all its content is added to the child list of this node.
 *     
 *     Create and populate a new DocumentFragment object and
 *     append it to the second employee.   After the 
 *     "appendChild(newChild)" method is invoked retrieve the
 *     new nodes at the end of the list, they should be the
 *     two Element nodes from the DocumentFragment.
* @author Curt Arnold
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-184E7107">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-184E7107</a>
* @see <a href="http://www.w3.org/Bugs/Public/show_bug.cgi?id=246">http://www.w3.org/Bugs/Public/show_bug.cgi?id=246</a>
* @see <a href="http://www.w3.org/Bugs/Public/show_bug.cgi?id=247">http://www.w3.org/Bugs/Public/show_bug.cgi?id=247</a>
*/

template<class string_type, class string_adaptor>
class hc_nodeappendchilddocfragment : public DOMTestCase<string_type, string_adaptor> 
{
   public: 
     hc_nodeappendchilddocfragment(std::string name) : DOMTestCase(name)
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
      Node employeeNode;
      NodeList childList;
      DocumentFragment newdocFragment;
      Node newChild1;
      Node newChild2;
      Node child;
      String childName;
      std::vector<string_type> result;
      
      Node appendedChild;
      int nodeType;
      std::vector<string_type> expected;
      expected.push_back(SA::construct_from_utf8("em"));
      expected.push_back(SA::construct_from_utf8("strong"));
      expected.push_back(SA::construct_from_utf8("code"));
      expected.push_back(SA::construct_from_utf8("sup"));
      expected.push_back(SA::construct_from_utf8("var"));
      expected.push_back(SA::construct_from_utf8("acronym"));
      expected.push_back(SA::construct_from_utf8("br"));
      expected.push_back(SA::construct_from_utf8("b"));
      
      doc = (Document) load("hc_staff", true);
      elementList = doc.getElementsByTagName(SA::construct_from_utf8("p"));
      employeeNode = elementList.item(1);
      childList = employeeNode.getChildNodes();
      newdocFragment = doc.createDocumentFragment();
      newChild1 = doc.createElement(SA::construct_from_utf8("br"));
      newChild2 = doc.createElement(SA::construct_from_utf8("b"));
      appendedChild = newdocFragment.appendChild(newChild1);
      appendedChild = newdocFragment.appendChild(newChild2);
      appendedChild = employeeNode.appendChild(newdocFragment);
      for (int indexN65698 = 0; indexN65698 != childList.getLength(); indexN65698++) {
          child = (Node) childList.item(indexN65698);
    nodeType = (int) child.getNodeType();
      
      if (equals(1, nodeType)) {
          childName = child.getNodeName();
      result.push_back(childName);
      }
      }
      assertEquals(expected, result);
  
   }
  
   /*
    *  Gets URI that identifies the test.
    */
   std::string getTargetURI() const
   {
      return "http://www.w3.org/2001/DOM-Test-Suite/level1/core/hc_nodeappendchilddocfragment";
   }
};

#endif
