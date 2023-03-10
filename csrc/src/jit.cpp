/************************************************
 ******               Rationale              *****
 *
 * User-facing functions we want:
 *
 * 1. _jit_execute(opname, arg1, arg2, ...)
 *    This assumes the caller already knows how the operator is called and what arguments it takes.
 *    Steps:
 *      1. Get all operators for that name, and take the first. Throw an error if no operator with
 *         that name exists, or if there are more than one.
 *      2. Find out which types the arguments should have. If the respective casts fail, throw an error.
 *         Otherwise call the operator.
 *      3. Verify that the actual return type matches what we expect. Otherwise throw an error.
 *      4. Return the value as well as the type to the caller.
 *
 * 2. _jit_operator_info(opname)
 *    Let the user know about an operator's arguments and return type.
 *
 * 3. _jit_all_operators()
 *    Return a list of registered operators.
 *
 *
 *
 * Questions/comments - also see inline!
 *
 * 1. I'm assuming that we don't need everything in c10::FunctionSchema, so I'm creating a simplified struct ... (problems?)
 *
 *
 *
 *
 *************************************************/



#include "jit.h"


void * _jit_all_operators () {
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

void * _jit_operator_info (void* name) {
  try {
    auto op_name = c10::Symbol::fromQualString(from_raw::string(name));
    const auto& ops = torch::jit::getAllOperatorsFor(op_name);
    const auto& op = ops.front();
    LanternFunctionSchema schema;
    schema.name = op->schema().name();
    const auto& arguments = op->schema().arguments();
    std::vector<c10::Argument> arglist;
    for (const auto& arg : arguments) {
      arglist.push_back(arg);
    }
    schema.arguments = arguments;
    return make_raw::LanternFunctionSchema(schema);
  } LLTM_HANDLE_EXCEPTION
  return (void*) NULL;
}

// tbd _jit_execute


void _delete_torch_operator(void* x) {
  auto ptr = reinterpret_cast<std::vector<torch::jit::Operator>*>(x);
  delete ptr;
}




// these have become obsolete

/* replaced by _jit_all_operators () (with same functionality)*/
// void * _jit_get_all_operators_names () {
//   try {
//     auto ops = torch::jit::getAllOperators();
//     std::vector<std::string> names;
//     for (const auto& op : ops) {
//       names.push_back(op->schema().name());
//     }
//     return make_raw::vector::string(names);
//   } LLTM_HANDLE_EXCEPTION
//   return (void*) NULL;
// }

// should not be needed because working with simplified schema
// void * _jit_get_operation_schema (void* name) {
//   try {
//     auto name_ = from_raw::string(name);
//     auto op_name = c10::Symbol::fromQualString(name_);
//     auto op = torch::jit::getAllOperatorsFor(op_name);
//     return make_raw::FunctionSchema(op[0]->schema());
//   } LLTM_HANDLE_EXCEPTION
//   return (void*) NULL;
// }


// not needed
// void * _jit_FunctionSchema_name (void* schema) {
//   try {
//     auto schema_ = from_raw::FunctionSchema(schema);
//     return make_raw::string(schema_.name());
//   } LLTM_HANDLE_EXCEPTION
//   return (void*) NULL;
// }

// not needed because offering higher-level service now
// void * _jit_get_all_operators_for (void* name) {
//   try {
//
//     auto name_ = from_raw::string(name);
//     auto op_name = c10::Symbol::fromQualString(name_);
//     auto op_ptrs = torch::jit::getAllOperatorsFor(op_name);
//     std::vector<torch::jit::Operator> ops;
//     for (auto& op_ptr : op_ptrs) {
//       auto op = *op_ptr;
//       ops.push_back(op);
//     }
//     auto ptr = make_raw::vector::Operator(ops);
//     return ptr;
//   } LLTM_HANDLE_EXCEPTION
//   return (void*) NULL;
// }

// same here
// int _jit_length_vector_operator (void* x) {
//   auto operators = from_raw::vector::Operator(x);
//   return operators.size();
// }




