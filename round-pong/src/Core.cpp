#include "pch.h"
#include "Core.h"
#include <filesystem>


const std::string Core::PROJECT_ABS_PATH = Core::getPath();

std::string Core::getPath()
{
    std::string path = std::filesystem::current_path().string();

    std::string::size_type pos;
    std::string::size_type tmpPos = 0;
    while ((tmpPos = path.find("bin", tmpPos)) != std::string::npos)
    {
        pos = tmpPos;
        tmpPos++;
    }

    path = path.substr(0, pos);
    //TODO: get project name from preproc define instead of typing by hand
    path += "round-pong/";
    RP_LOG("Project path: %s", path.c_str());
    return path;
}
