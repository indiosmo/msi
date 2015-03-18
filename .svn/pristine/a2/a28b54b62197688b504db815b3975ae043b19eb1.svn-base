#ifndef NETWORK_EXPORT_H
#define NETWORK_EXPORT_H

#if !defined(NETWORK_HAS_DLL)
# if defined(NETWORK_AS_STATIC_LIBS)
#   define NETWORK_HAS_DLL 0
# else
#   define NETWORK_HAS_DLL 1
# endif
#endif

#if (NETWORK_HAS_DLL == 1)
#  if defined(__SUNPRO_CC) && (__SUNPRO_CC >= 0x550)
#    if defined(NETWORK_BUILD_DLL)
#      define NETWORK_Export __symbolic
#    else
#      define NETWORK_Export __global
#    endif
#  elif defined(WIN32) || defined(UNDER_CE) || defined(__CYGWIN__)
#    if defined(NETWORK_BUILD_DLL)
#      define NETWORK_Export __declspec(dllexport)
#    else
#      define NETWORK_Export __declspec(dllimport)
#    endif
#  elif (defined(__GNUC__) && (__GNUC__ >= 4))
#    if defined(NETWORK_BUILD_DLL)
#      define NETWORK_Export __attribute__((visibility("default")))
#    else
#      define NETWORK_Export
#    endif
#  else
#    define NETWORK_Export
#  endif
#else
#  define NETWORK_Export
#endif

#endif
