#pragma once
#include <torch.h>
#include <torch_types.h>
#include <lltm/lltm.h>

class XPtrTorchVectorOperator : public XPtrTorch {
public:
  XPtrTorchVectorOperator(void* x) : XPtrTorch(x, _delete_torch_operator) {}
  explicit XPtrTorchVectorOperator(std::shared_ptr<void> x) : XPtrTorch(x){};
  XPtrTorchVectorOperator(const XPtrTorchVectorOperator& x)
    : XPtrTorch(x.get_shared()){};

  XPtrTorchVectorOperator(SEXP x);
  operator SEXP() const;
};

namespace torch {
  namespace vector {
    namespace jit {
    using Operator = XPtrTorchVectorOperator;
    }
  }
  // namespace jit {
  //   using Operator = XPtrTorchOperator;
  // }
}





