#include <torch/torch.h>
#define LANTERN_TYPES_IMPL // Should be defined only in a single file.
#include <lantern/types.h>
#include <iostream>
#include <vector>
#include "lltm/lltm.h"

// [[torch::export]]
torch::Tensor contrarian(torch::Tensor z) {
 return -z;
}

LLTM_API int _raise_exception ()
{
  try {
    throw std::runtime_error("Error from LLTM");
  } LLTM_HANDLE_EXCEPTION
  return 1;
}


