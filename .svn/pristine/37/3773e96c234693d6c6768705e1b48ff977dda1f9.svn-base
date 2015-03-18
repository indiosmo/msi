#ifndef LOGGING_EXPORT_HPP
#define LOGGING_EXPORT_HPP

#if !defined(LOGGING_HAS_DLL)
# if defined(LOGGING_AS_STATIC_LIBS)
#   define LOGGING_HAS_DLL 0
# else
#   define LOGGING_HAS_DLL 1
# endif
#endif

#if (LOGGING_HAS_DLL == 1)
#  if defined(__SUNPRO_CC) && (__SUNPRO_CC >= 0x550)
#    if defined(LOGGING_BUILD_DLL)
#      define LOGGING_Export __symbolic
#    else
#      define LOGGING_Export __global
#    endif
#  elif defined(WIN32) || defined(UNDER_CE) || defined(__CYGWIN__)
#    if defined(LOGGING_BUILD_DLL)
#      define LOGGING_Export __declspec(dllexport)
#    else
#      define LOGGING_Export __declspec(dllimport)
#    endif
#  elif (defined(__GNUC__) && (__GNUC__ >= 4))
#    if defined(LOGGING_BUILD_DLL)
#      define LOGGING_Export __attribute__((visibility("default")))
#    else
#      define LOGGING_Export
#    endif
#  else
#    define LOGGING_Export
#  endif
#else
#  define LOGGING_Export
#endif

#endif
