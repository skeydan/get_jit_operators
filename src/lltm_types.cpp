#include <Rcpp.h>
#include "lltm_types.h"
#include "exports.h"

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








