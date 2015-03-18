#ifndef MARKETDATA_COMMON_EXPORT_H
#define MARKETDATA_COMMON_EXPORT_H

#if !defined(MARKETDATA_COMMON_HAS_DLL)
# if defined(MARKETDATA_COMMON_AS_STATIC_LIBS)
#   define MARKETDATA_COMMON_HAS_DLL 0
# else
#   define MARKETDATA_COMMON_HAS_DLL 1
# endif
#endif

#if (MARKETDATA_COMMON_HAS_DLL == 1)
#  if defined(__SUNPRO_CC) && (__SUNPRO_CC >= 0x550)
#    if defined(MARKETDATA_COMMON_BUILD_DLL)
#      define MARKETDATA_COMMON_Export __symbolic
#    else
#      define MARKETDATA_COMMON_Export __global
#    endif
#  elif defined(WIN32) || defined(UNDER_CE) || defined(__CYGWIN__)
#    if defined(MARKETDATA_COMMON_BUILD_DLL)
#      define MARKETDATA_COMMON_Export __declspec(dllexport)
#    else
#      define MARKETDATA_COMMON_Export __declspec(dllimport)
#    endif
#  elif (defined(__GNUC__) && (__GNUC__ >= 4))
#    if defined(MARKETDATA_COMMON_BUILD_DLL)
#      define MARKETDATA_COMMON_Export __attribute__((visibility("default")))
#    else
#      define MARKETDATA_COMMON_Export
#    endif
#  else
#    define MARKETDATA_COMMON_Export
#  endif
#else
#  define MARKETDATA_COMMON_Export
#endif

#endif
