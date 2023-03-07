#include <Rcpp.h>
#include "lltm_types.h"
#include "exports.h"


/*
void delete_compilation_unit(void* x);

void delete_compilation_unit(void* x) { lantern_CompilationUnit_delete(x); }

----------------

#include <R_ext/Rdynload.h>
#include <Rcpp.h>
#include <torch_api.h>

#define REGISTER_C_CALLABLE(f) R_RegisterCCallable("torch", #f, (DL_FUNC)&f);

// [[Rcpp::init]]
void register_callables(DllInfo *dll) {
  REGISTER_C_CALLABLE(delete_compilation_unit)
}

*/

// torch_imports.h
#define IMPORT_SEXP_OPERATOR(name, type)                         \
SEXP name(const type* self) {                                    \
  static SEXP (*fn)(const type*) = NULL;                         \
  if (fn == NULL) {                                              \
    fn = (SEXP(*)(const type*))R_GetCCallable("torch", #name);   \
  }                                                              \
  return fn(self);                                               \
}                                                                \

#define IMPORT_FROM_SEXP(name, type)                           \
type name(SEXP x) {                                            \
  static type (*fn)(SEXP) = NULL;                              \
  if (fn == NULL) {                                            \
    fn = (type(*)(SEXP))R_GetCCallable("torch", #name);        \
  }                                                            \
  return fn(x);                                                \
}                                                              \


// torch_api.h
SEXP operator_sexp_operator(const XPtrTorchOperator* self);
// torch_impl.h
XPtrTorchOperator::operator SEXP() const {
  return operator_sexp_operator(this);
}
IMPORT_SEXP_OPERATOR(operator_sexp_operator, XPtrTorchOperator)

// torch_api.h
XPtrTorchOperator from_sexp_operator(SEXP x);
// torch_impl.h
XPtrTorchOperator::XPtrTorchOperator(SEXP x)
  : XPtrTorchOperator{from_sexp_operator(x)} {}
IMPORT_FROM_SEXP(from_sexp_operator, XPtrTorchOperator)








