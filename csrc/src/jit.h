#pragma once

#include <lantern/types.h>
#include "lltm/lltm.h"

#define FROM_RAW_DECL(name, type) type& name(void* x);
#define FROM_RAW(name, type) \
type& name(void* x) { return *reinterpret_cast<type*>(x); }

struct LanternFunctionSchema {
  std::string name;
  std::vector<c10::Argument> arguments;
  std::vector<c10::Argument> returns;
};

namespace make_raw {
  void* LanternFunctionSchema (const LanternFunctionSchema& x);
  void* LanternFunctionSchema (const struct LanternFunctionSchema& x) { return make_ptr(x); }
  //void* FunctionSchema (const c10::FunctionSchema& x);
  //void* FunctionSchema (const c10::FunctionSchema& x) { return make_ptr<c10::FunctionSchema>(x); }

  // probably not required anymore
  //void* Operator (const torch::jit::Operator& x);
  //void* Operator (const torch::jit::Operator& x) { return make_ptr<torch::jit::Operator>(x); }
  //namespace vector {
  //  void* Operator(const std::vector<torch::jit::Operator>& x) {
  //    return make_ptr<std::vector<torch::jit::Operator>>(x);
}

namespace from_raw {
  //FROM_RAW_DECL(FunctionSchema, c10::FunctionSchema)
  //FROM_RAW(FunctionSchema, c10::FunctionSchema)
  FROM_RAW_DECL(Schema, LanternFunctionSchema)
  FROM_RAW(Schema, LanternFunctionSchema)
  // probably not required anymore
  // FROM_RAW_DECL(Operator, torch::jit::Operator)
  // FROM_RAW(Operator, torch::jit::Operator)
  // namespace vector {
  //   std::vector<torch::jit::Operator>& Operator(void* x);
  //   std::vector<torch::jit::Operator>& Operator(void* x) { return *reinterpret_cast<std::vector<torch::jit::Operator>*>(x); }
  // }
}

