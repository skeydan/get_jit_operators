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

// torch_impl.h
XPtrTorchVectorOperator::operator SEXP() const {
  auto xptr = make_xptr<XPtrTorchVectorOperator>(*this);
  xptr.attr("class") =
    Rcpp::CharacterVector::create("torch_vector_jit_operator", "R7");
  return xptr;
}

XPtrTorchVectorOperator from_sexp_operator (SEXP x) {
  if (TYPEOF(x) == EXTPTRSXP && Rf_inherits(x, "torch_vector_jit_operator")) {
    auto out = Rcpp::as<Rcpp::XPtr<XPtrTorchVectorOperator>>(x);
    return XPtrTorchVectorOperator(out->get_shared());
  }
  Rcpp::stop("Unsupported type. Expected an external pointer.");
}

XPtrTorchVectorOperator::XPtrTorchVectorOperator(SEXP x)
  : XPtrTorchVectorOperator{from_sexp_operator(x)} {}








