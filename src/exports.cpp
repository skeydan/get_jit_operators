// Generated by using torchexport::export() -> do not edit by hand
#include "exports.h"
#define LLTM_HEADERS_ONLY
#include <lltm/lltm.h>

// [[Rcpp::export]]
torch::Tensor rcpp_contrarian (torch::Tensor z) {
  return  contrarian(z.get());
}