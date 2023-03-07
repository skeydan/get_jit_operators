#pragma once
#include <torch.h>
#include <torch_types.h>

class XPtrTorchOperator : public XPtrTorch {
public:
  XPtrTorchOperator(void* x) : XPtrTorch(x, delete_compilation_unit) {}
  XPtrTorchOperator(SEXP x);
  explicit XPtrTorchOperator(std::shared_ptr<void> x) : XPtrTorch(x){};
  XPtrTorchOperator(const XPtrTorchOperator& x)
    : XPtrTorch(x.get_shared()){};
  operator SEXP() const;
};

namespace torch {
  namespace vector {
    namespace jit {
    using Operator = XPtrTorchOperator;
    }
  }
  namespace jit {
    using Operator = XPtrTorchOperator;
  }
}






