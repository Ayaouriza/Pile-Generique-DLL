
#ifndef EXPORT_H
#define EXPORT_H

#ifdef BUILD_DLL
    #define PILE_API __declspec(dllexport)
#else
    #define PILE_API __declspec(dllimport)
#endif

#endif
