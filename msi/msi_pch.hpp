#ifndef APOENA_MSI_MSI_PCH_H
#define APOENA_MSI_MSI_PCH_H

#ifdef _MSC_VER
#pragma warning(disable:4251)
#pragma warning(disable:4996)
#endif

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#define NOMINMAX
#include <windows.h>
#endif /* WIN32 */

#endif /* APOENA_MSI_MSI_PCH_H */

