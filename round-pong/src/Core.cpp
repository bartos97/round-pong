#include "pch.h"
#include "Core.h"


const std::string Core::SRC_PATH = Core::getSrcPath();

std::string Core::getSrcPath()
{
    std::string path = __FILE__;
    int counter = 0;
    auto i = path.end();
    i--;
    while (*i != '\\')
    {
        counter++;
        i--;
    }
    return std::string(path, 0, path.length() - counter);
}
