#pragma once


#ifdef RP_ENABLE_LOG
    #define RP_LOG(...) \
    { \
        printf("%s at line %d:\n\t", __FILE__, __LINE__); \
        printf(__VA_ARGS__); \
        putchar('\n'); \
    }
#else
    #define RP_LOG(...)
#endif // RP_ENABLE_LOG


#ifdef RP_ENABLE_ASSERT
    #define RP_ASSERT(x, ...) \
    { \
        if (!x) \
        {\
            printf("%s at line %d: \n\tASSERTION FAILED!: ", __FILE__, __LINE__); \
            printf(__VA_ARGS__); \
            putchar('\n'); \
            __debugbreak(); \
        } \
    }
#else
    #define RP_ASSERT(...)
#endif // RP_ENABLE_ASSERT