#include <lantern/types.h>
#include "lltm/lltm.h"

#define FROM_RAW_DECL(name, type) type& name(void* x);
#define FROM_RAW(name, type) \
type& name(void* x) { return *reinterpret_cast<type*>(x); }


namespace make_raw {
  void* FunctionSchema (const c10::FunctionSchema& x);
  void* FunctionSchema (const c10::FunctionSchema& x) { return make_ptr<c10::FunctionSchema>(x); }
  void* Operator (const torch::jit::Operator& x);
  void* Operator (const torch::jit::Operator& x) { return make_ptr<torch::jit::Operator>(x); }
  namespace vector {
    void* Operator(const std::vector<torch::jit::Operator>& x) {
      return make_ptr<std::vector<torch::jit::Operator>>(x);
    }
  }
}

namespace from_raw {
  //FROM_RAW_DECL(FunctionSchema, c10::FunctionSchema)
  c10::FunctionSchema& FunctionSchema(void* x);
  //FROM_RAW(FunctionSchema, c10::FunctionSchema)
  c10::FunctionSchema& FunctionSchema(void* x) { return *reinterpret_cast<c10::FunctionSchema*>(x); }
  FROM_RAW_DECL(Operator, torch::jit::Operator)
  FROM_RAW(Operator, torch::jit::Operator)
  namespace vector {
    //FROM_RAW_DECL(Operator, std::vector<torch::jit::Operator>)
    std::vector<torch::jit::Operator>& Operator(void* x);
    FROM_RAW(Operator, std::vector<torch::jit::Operator>)
    //std::vector<torch::jit::Operator>& Operator(void* x) { return *reinterpret_cast<torch::jit::Operator*>(x); }
    /*
     *  jit.h:32:67: error: invalid initialization of reference of type ‘std::vector<torch::jit::Operator>&’ from expression
     *  of type ‘torch::jit::Operator’
     *  32 |     std::vector<torch::jit::Operator>& Operator(void* x) { return *reinterpret_cast<torch::jit::Operator*>(x); }
    */
    }
}

