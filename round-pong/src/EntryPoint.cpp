#include "pch.h"
#include "Application.h"

int main() {
    RP_LOG("Compiled at %s", __TIME__);
    auto app = Application::create();
    app->run();
    delete app;
    return 0;
}