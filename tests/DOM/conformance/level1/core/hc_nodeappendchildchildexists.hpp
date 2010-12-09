
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

#ifndef test_hc_nodeappendchildchildexists
#define test_hc_nodeappendchildchildexists

#include "dom_conf_test.hpp"

/**
 *     If the "newChild" is already in the tree, it is first
 *     removed before the new one is appended.
 *     
 *     Retrieve the "em" second employee and   
 *     append the first child to the end of the list.   After
 *     the "appendChild(newChild)" method is invoked the first 
 *     child should be the one that was second and the last
 *     child should be the one that was first.
* @author Curt Arnold
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-184E7107">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-184E7107</a>
* @see <a href="http://www.w3.org/Bugs/Public/show_bug.cgi?id=246">http://www.w3.org/Bugs/Public/show_bug.cgi?id=246</a>
*/

template<class string_type, class string_adaptor>
class hc_nodeappendchildchildexists : public DOMTestCase<string_type, string_adaptor> 
{
   public: 
     hc_nodeappendchildchildexists(std::string name) : DOMTestCase(name)
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
      NodeList childList;
      Node childNode;
      Node newChild;
      Node memberNode;
      String memberName;
      std::vector<string_type> refreshedActual;
      
      std::vector<string_type> actual;
      
      int nodeType;
      std::vector<string_type> expected;
      expected.push_back(SA::construct_from_utf8("strong"));
      expected.push_back(SA::construct_from_utf8("code"));
      expected.push_back(SA::construct_from_utf8("sup"));
      expected.push_back(SA::construct_from_utf8("var"));
      expected.push_back(SA::construct_from_utf8("acronym"));
      expected.push_back(SA::construct_from_utf8("em"));
      
      Node appendedChild;
      doc = (Document) load("hc_staff", true);
      elementList = doc.getElementsByTagName(SA::construct_from_utf8("p"));
      childNode = elementList.item(1);
      childList = ((Element) /*Node */childNode).getElementsByTagName(SA::construct_from_utf8("*"));
      newChild = childList.item(0);
      appendedChild = childNode.appendChild(newChild);
      for (int indexN65669 = 0; indexN65669 != childList.getLength(); indexN65669++) {
          memberNode = (Node) childList.item(indexN65669);
    memberName = memberNode.getNodeName();
      actual.push_back(memberName);
        }
      assertEquals(expected, actual);
  childList = childNode.getChildNodes();
      for (int indexN65692 = 0; indexN65692 != childList.getLength(); indexN65692++) {
          memberNode = (Node) childList.item(indexN65692);
    nodeType = (int) memberNode.getNodeType();
      
      if (equals(1, nodeType)) {
          memberName = memberNode.getNodeName();
      refreshedActual.push_back(memberName);
      }
      }
      assertEquals(expected, refreshedActual);
  
   }
  
   /*
    *  Gets URI that identifies the test.
    */
   std::string getTargetURI() const
   {
      return "http://www.w3.org/2001/DOM-Test-Suite/level1/core/hc_nodeappendchildchildexists";
   }
};

#endif
