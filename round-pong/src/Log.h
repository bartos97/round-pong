#pragma once


#ifdef RP_ENABLE_LOG
    #define RP_LOG(...) \
    { \
        printf("%s at line %d: ", __FILE__, __LINE__); \
        printf(__VA_ARGS__); \
        putchar('\n'); \
    }

    #define RP_EVENT_LOG(e, ...) \
    { \
        printf("Event #%d %s:", e.getType(), e.getName()); \
        printf(__VA_ARGS__); \
        putchar('\n'); \
    }
#else
    #define RP_LOG(...)
    #define RP_EVENT_LOG(...)
#endif // RP_ENABLE_LOG


#ifdef RP_ENABLE_ASSERT
    #define RP_ASSERT(x, ...) \
    { \
        if (!x) \
        {\
            printf("ASSERTION FAILED!:\n"); \
            RP_LOG(__VA_ARGS__) \
            __debugbreak(); \
        } \
    }
#else
    #define RP_ASSERT(...)
#endif // RP_ENABLE_ASSERT