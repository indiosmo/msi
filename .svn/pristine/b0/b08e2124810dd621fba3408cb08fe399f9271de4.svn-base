#ifndef RECEIVER_EXPORT_H
#define RECEIVER_EXPORT_H

#if !defined(RECEIVER_HAS_DLL)
# if defined(RECEIVER_AS_STATIC_LIBS)
#   define RECEIVER_HAS_DLL 0
# else
#   define RECEIVER_HAS_DLL 1
# endif
#endif

#if (RECEIVER_HAS_DLL == 1)
#  if defined(__SUNPRO_CC) && (__SUNPRO_CC >= 0x550)
#    if defined(RECEIVER_BUILD_DLL)
#      define RECEIVER_Export __symbolic
#    else
#      define RECEIVER_Export __global
#    endif
#  elif defined(WIN32) || defined(UNDER_CE) || defined(__CYGWIN__)
#    if defined(RECEIVER_BUILD_DLL)
#      define RECEIVER_Export __declspec(dllexport)
#    else
#      define RECEIVER_Export __declspec(dllimport)
#    endif
#  elif (defined(__GNUC__) && (__GNUC__ >= 4))
#    if defined(RECEIVER_BUILD_DLL)
#      define RECEIVER_Export __attribute__((visibility("default")))
#    else
#      define RECEIVER_Export
#    endif
#  else
#    define RECEIVER_Export
#  endif
#else
#  define RECEIVER_Export
#endif

#endif
