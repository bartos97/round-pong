#include "pch.h"
#include "Application.h"

int main()
{
    RP_LOG("Compiled at %s %s", __DATE__, __TIME__);
    auto app = Application::create();
    app->run();
    delete app;
    return 0;
}