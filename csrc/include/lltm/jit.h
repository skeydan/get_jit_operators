#include <lantern/types.h>
#include "lltm/lltm.h"

#define FROM_RAW_DECL(name, type) type& name(void* x);
#define FROM_RAW(name, type) \
type& name(void* x) { return *reinterpret_cast<type*>(x); }


namespace make_raw {
void* FunctionSchema (const c10::FunctionSchema& x);
void* FunctionSchema (const c10::FunctionSchema& x) { return make_ptr<c10::FunctionSchema>(x); }
}

namespace from_raw {
FROM_RAW_DECL(FunctionSchema, c10::FunctionSchema)
FROM_RAW(FunctionSchema, c10::FunctionSchema)
}

