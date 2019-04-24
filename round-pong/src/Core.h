#pragma once


#ifdef RP_DEBUG
    #define RP_ENABLE_LOG
    #define RP_ENABLE_ASSERT
#endif // RP_DEBUG


#ifdef RP_RELEASE
    //#define RP_FULLSCREEN
#endif // RP_RELEASE


class Core
{
public:
    static const std::string SRC_PATH;

private:
    static std::string getSrcPath();
};

