#include <lltm/exports.h>

LLTM_API void * _jit_get_all_operators_names ();
LLTM_API void * _jit_get_operation_schema (void* name);
LLTM_API void * _jit_FunctionSchema_name (void* schema);

LLTM_API int _raise_exception ();
inline int raise_exception () {
  _raise_exception();
  host_exception_handler();
  return 1;
}




