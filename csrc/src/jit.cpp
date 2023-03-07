#include "jit.h"


void * _jit_get_all_operators_names () {
  try {
    auto ops = torch::jit::getAllOperators();
    std::vector<std::string> names;
    for (const auto& op : ops) {
      names.push_back(op->schema().name());
    }
    return make_raw::vector::string(names);
  } LLTM_HANDLE_EXCEPTION
  return (void*) NULL;
}

void * _jit_get_operation_schema (void* name) {
  try {
    auto name_ = from_raw::string(name);
    auto op_name = c10::Symbol::fromQualString(name_);
    auto op = torch::jit::getAllOperatorsFor(op_name);
    return make_raw::FunctionSchema(op[0]->schema());
  } LLTM_HANDLE_EXCEPTION
  return (void*) NULL;
}

void * _jit_FunctionSchema_name (void* schema) {
  try {
    auto schema_ = from_raw::FunctionSchema(schema);
    return make_raw::string(schema_.name());
  } LLTM_HANDLE_EXCEPTION
  return (void*) NULL;
}


void * _jit_get_all_operators_for (void* name) {
  try {

    auto name_ = from_raw::string(name);
    auto op_name = c10::Symbol::fromQualString(name_);
    // this returns const std::vector<std::shared_ptr<torch::jit::Operator>>& x
    auto op_ptrs = torch::jit::getAllOperatorsFor(op_name);
    std::vector<torch::jit::Operator> ops;
    for (const std::shared_ptr<torch::jit::Operator> op_ptr : op_ptrs) {
      // get rid of the shared_ptr, since the type pointed to will change anyway
      // get the Operator (as data, not reference, right?)
      auto op = *op_ptr;
      // and push on list
      ops.push_back(op);
    }
    // make whole vector raw
    auto ptr = make_raw::vector::Operator(ops);
    return ptr;
  } LLTM_HANDLE_EXCEPTION
  return (void*) NULL;
}

void _delete_torch_operator(void* x) {
  auto ptr = reinterpret_cast<std::vector<torch::jit::Operator>*>(x);
  delete ptr;
}

int _jit_length_vector_operator (void* x) {
  auto operators = from_raw::vector::Operator(x);
  return operators.size();
}


