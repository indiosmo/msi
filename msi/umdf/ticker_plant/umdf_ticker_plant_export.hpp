#ifndef UMDF_TICKER_PLANT_EXPORT_H
#define UMDF_TICKER_PLANT_EXPORT_H

#if !defined(UMDF_TICKER_PLANT_HAS_DLL)
# if defined(UMDF_TICKER_PLANT_AS_STATIC_LIBS)
#   define UMDF_TICKER_PLANT_HAS_DLL 0
# else
#   define UMDF_TICKER_PLANT_HAS_DLL 1
# endif
#endif

#if (UMDF_TICKER_PLANT_HAS_DLL == 1)
#  if defined(__SUNPRO_CC) && (__SUNPRO_CC >= 0x550)
#    if defined(UMDF_TICKER_PLANT_BUILD_DLL)
#      define UMDF_TICKER_PLANT_Export __symbolic
#    else
#      define UMDF_TICKER_PLANT_Export __global
#    endif
#  elif defined(WIN32) || defined(UNDER_CE) || defined(__CYGWIN__)
#    if defined(UMDF_TICKER_PLANT_BUILD_DLL)
#      define UMDF_TICKER_PLANT_Export __declspec(dllexport)
#    else
#      define UMDF_TICKER_PLANT_Export __declspec(dllimport)
#    endif
#  elif (defined(__GNUC__) && (__GNUC__ >= 4))
#    if defined(UMDF_TICKER_PLANT_BUILD_DLL)
#      define UMDF_TICKER_PLANT_Export __attribute__((visibility("default")))
#    else
#      define UMDF_TICKER_PLANT_Export
#    endif
#  else
#    define UMDF_TICKER_PLANT_Export
#  endif
#else
#  define UMDF_TICKER_PLANT_Export
#endif

#endif
