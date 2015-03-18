#ifndef UMDF_DECODER_QUICKFAST_EXPORT_H
#define UMDF_DECODER_QUICKFAST_EXPORT_H

#if !defined(UMDF_DECODER_QUICKFAST_HAS_DLL)
# if defined(UMDF_DECODER_QUICKFAST_AS_STATIC_LIBS)
#   define UMDF_DECODER_QUICKFAST_HAS_DLL 0
# else
#   define UMDF_DECODER_QUICKFAST_HAS_DLL 1
# endif
#endif

#if (UMDF_DECODER_QUICKFAST_HAS_DLL == 1)
#  if defined(__SUNPRO_CC) && (__SUNPRO_CC >= 0x550)
#    if defined(UMDF_DECODER_QUICKFAST_BUILD_DLL)
#      define UMDF_DECODER_QUICKFAST_Export __symbolic
#    else
#      define UMDF_DECODER_QUICKFAST_Export __global
#    endif
#  elif defined(WIN32) || defined(UNDER_CE) || defined(__CYGWIN__)
#    if defined(UMDF_DECODER_QUICKFAST_BUILD_DLL)
#      define UMDF_DECODER_QUICKFAST_Export __declspec(dllexport)
#    else
#      define UMDF_DECODER_QUICKFAST_Export __declspec(dllimport)
#    endif
#  elif (defined(__GNUC__) && (__GNUC__ >= 4))
#    if defined(UMDF_DECODER_QUICKFAST_BUILD_DLL)
#      define UMDF_DECODER_QUICKFAST_Export __attribute__((visibility("default")))
#    else
#      define UMDF_DECODER_QUICKFAST_Export
#    endif
#  else
#    define UMDF_DECODER_QUICKFAST_Export
#  endif
#else
#  define UMDF_DECODER_QUICKFAST_Export
#endif

#endif
