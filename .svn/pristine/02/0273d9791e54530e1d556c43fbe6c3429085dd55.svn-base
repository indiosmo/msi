#ifndef RECOVERY_EXPORT_H
#define RECOVERY_EXPORT_H

#if !defined(RECOVERY_HAS_DLL)
# if defined(RECOVERY_AS_STATIC_LIBS)
#   define RECOVERY_HAS_DLL 0
# else
#   define RECOVERY_HAS_DLL 1
# endif
#endif

#if (RECOVERY_HAS_DLL == 1)
#  if defined(__SUNPRO_CC) && (__SUNPRO_CC >= 0x550)
#    if defined(RECOVERY_BUILD_DLL)
#      define RECOVERY_Export __symbolic
#    else
#      define RECOVERY_Export __global
#    endif
#  elif defined(WIN32) || defined(UNDER_CE) || defined(__CYGWIN__)
#    if defined(RECOVERY_BUILD_DLL)
#      define RECOVERY_Export __declspec(dllexport)
#    else
#      define RECOVERY_Export __declspec(dllimport)
#    endif
#  elif (defined(__GNUC__) && (__GNUC__ >= 4))
#    if defined(RECOVERY_BUILD_DLL)
#      define RECOVERY_Export __attribute__((visibility("default")))
#    else
#      define RECOVERY_Export
#    endif
#  else
#    define RECOVERY_Export
#  endif
#else
#  define RECOVERY_Export
#endif

#endif
