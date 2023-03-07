#pragma once

#ifdef _WIN32
#ifndef LLTM_HEADERS_ONLY
#define LLTM_API extern "C" __declspec(dllexport)
#else
#define LLTM_API extern "C" __declspec(dllimport)
#endif
#else
#define LLTM_API extern "C"
#endif

#ifndef LLTM_HANDLE_EXCEPTION
#define LLTM_HANDLE_EXCEPTION                                  \
catch(const std::exception& ex) {                                  \
  p_lltm_last_error = make_raw::string(ex.what());             \
} catch (std::string& ex) {                                        \
  p_lltm_last_error = make_raw::string(ex);                    \
} catch (...) {                                                    \
  p_lltm_last_error = make_raw::string("Unknown error. ");     \
}
#endif

void host_exception_handler ();
extern void* p_lltm_last_error;
LLTM_API void* lltm_last_error ();
LLTM_API void lltm_last_error_clear();

#ifdef RCPP_VERSION
#endif // RCPP_VERSION
