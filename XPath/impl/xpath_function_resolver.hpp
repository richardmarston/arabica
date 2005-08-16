#ifndef ARABICA_XPATH_FUNCTION_RESOLVER_HPP
#define ARABICA_XPATH_FUNCTION_RESOLVER_HPP

namespace Arabica
{
namespace XPath
{

class XPathFunction;
template<class string_type> class XPathExpressionPtr;

class UndefinedFunctionException : public std::runtime_error
{
public:
  UndefinedFunctionException(const std::string& thing) : std::runtime_error("The function '" + thing + "' is undefined.") { }
}; // class UndefinedFunctionException

class FunctionResolver
{
public:
  virtual ~FunctionResolver() { }

  // TODO: should make this a QName
  virtual XPathFunction* resolveFunction(const std::string& name,
                                         const std::vector<XPathExpressionPtr<std::string> >& argExprs) const = 0; 
}; // class FunctionResolver

class FunctionResolverPtr : public boost::shared_ptr<FunctionResolver> 
{
public:
  explicit FunctionResolverPtr(FunctionResolver* fr) : boost::shared_ptr<FunctionResolver>(fr) { }
}; 

class NullFunctionResolver : public FunctionResolver
{
public:
  virtual XPathFunction* resolveFunction(const std::string& name,
                                         const std::vector<XPathExpressionPtr<std::string> >& argExprs) const 
  {
    throw UndefinedFunctionException(name);
  } // resolveVariable
}; // NullFunctionResolver

} // namespace XPath
} // namespace Arabica

#endif
