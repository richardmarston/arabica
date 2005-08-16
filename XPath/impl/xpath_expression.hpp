#ifndef ARABICA_XPATHIC_XPATH_EXPRESSION_H
#define ARABICA_XPATHIC_XPATH_EXPRESSION_H

#include <string>
#include <DOM/Node.h>
#include "xpath_object.hpp"
#include "xpath_execution_context.hpp"

namespace Arabica
{
namespace XPath
{

template<class string_type>
class XPathExpression
{
protected:
  XPathExpression() { }

public:
  virtual ~XPathExpression() { }

  XPathValuePtr<string_type> evaluate(const DOM::Node<string_type>& context) const
  {
    ExecutionContext executionContext;
    return evaluate(context, executionContext);
  } // evaluate

  virtual bool evaluateAsBool(const DOM::Node<string_type>& context) const { return evaluate(context)->asBool(); }
  virtual double evaluateAsNumber(const DOM::Node<string_type>& context) const { return evaluate(context)->asNumber(); }
  virtual string_type evaluateAsString(const DOM::Node<string_type>& context) const { return evaluate(context)->asString(); }
  virtual NodeSet<string_type> evaluateAsNodeSet(const DOM::Node<string_type>& context) const { return evaluate(context)->asNodeSet(); }

  virtual XPathValuePtr<string_type> evaluate(const DOM::Node<string_type>& context, 
                                              const ExecutionContext& executionContext) const = 0;

private:
  XPathExpression(const XPathExpression&);
  bool operator==(const XPathExpression&);
  XPathExpression& operator=(const XPathExpression&);
}; // class XPathExpression

template<class string_type>
class XPathExpressionPtr : public boost::shared_ptr<XPathExpression<string_type> > 
{ 
public:
  explicit XPathExpressionPtr(XPathExpression<string_type>* xp) : boost::shared_ptr<XPathExpression<string_type> >(xp) { }
};

template<class string_type>
class UnaryExpression
{
public:
  UnaryExpression(XPathExpression<string_type>* expr) :
      expr_(expr) { }

protected:
  ~UnaryExpression() 
  {
    delete expr_;
  } // ~UnaryExpression

  XPathExpression<string_type>* expr() const { return expr_; }

private:
  XPathExpression<string_type>* expr_;
}; // class UnaryExpression

template<class string_type>
class BinaryExpression
{
public:
  BinaryExpression(XPathExpression<string_type>* lhs, 
                   XPathExpression<string_type>* rhs) :
      lhs_(lhs), 
       rhs_(rhs) 
  { 
  } // BinaryExpression

protected:
  ~BinaryExpression() 
  { 
    delete lhs_;
    delete rhs_;
  } // ~BinaryExpression

  XPathExpression<string_type>* lhs() const { return lhs_; }
  XPathExpression<string_type>* rhs() const { return rhs_; }

private:
  XPathExpression<string_type>* lhs_;
  XPathExpression<string_type>* rhs_;
}; // class BinaryExpression

} // namespace XPath
} // namespace Arabica

#endif
