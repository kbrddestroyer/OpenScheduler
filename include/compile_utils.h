#ifndef COMPILE_UTILS_H
#define COMPILE_UTILS_H

#define _GETTER_P [[nodiscard]]
#define _GETTER_S const noexcept
#define GETTER(FUNC) _GETTER_P FUNC _GETTER_S

#if defined(WIN32)

    #if defined(DYNAMIC)
        #define DECLSPEC_AUTO __declspec(dllexport)
    #else
        #define DECLSPEC_AUTO __declspec(dllimport)
    #endif

#else
    #define DECLSPEC_AUTO
#endif

#endif //UTILITY_H
