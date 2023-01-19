
#include "lltm/jit.h"

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

