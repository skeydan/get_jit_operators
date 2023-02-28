#include <Rcpp.h>
#include <torch.h>
#include "lltm/lltm.h"

// [[Rcpp::export]]
torch::vector::string cpp_jit_get_all_operators_names () {
  return _jit_get_all_operators_names();
}

// [[Rcpp::export]]
torch::string cpp_jit_get_operator_from_name (torch::string x) {
  return _jit_FunctionSchema_name(_jit_get_operation_schema(x.get()));
}

// [[Rcpp::export]]
torch::jit::Operator cpp_jit_get_all_operators_for (torch::string x) {
  return _jit_get_all_operators_for(x.get());
}

