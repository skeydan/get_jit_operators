#include "lltm/lltm.h"
#include <lantern/types.h>

void * p_lltm_last_error = NULL;

LLTM_API void* lltm_last_error()
{
  return p_lltm_last_error;
}

LLTM_API void lltm_last_error_clear()
{
  p_lltm_last_error = NULL;
}
