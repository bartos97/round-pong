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
        printf("Event #%d %s: ", e.getType(), e.getName()); \
        printf(__VA_ARGS__); \
        putchar('\n'); \
    }

    #define GL_CALL(func) \
        GLerrorClear();\
        func;\
        RP_ASSERT(GLerrorCheck(), #func" failed.");
#else
    #define RP_LOG(...)
    #define RP_EVENT_LOG(...)
    #define GL_CALL(func) func
#endif // RP_ENABLE_LOG


#ifdef RP_ENABLE_ASSERT
    #ifdef RP_SYSTEM_WINDOWS
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
        #define RP_ASSERT(x, ...) \
		{ \
            if (!x) \
            {\
                printf("ASSERTION FAILED!:\n"); \
                RP_LOG(__VA_ARGS__) \
            } \
        }
    #endif
#else
    #define RP_ASSERT(...)
#endif // RP_ENABLE_ASSERT


void GLerrorClear();
bool GLerrorCheck();
