#pragma once
#include "Window.h"
#include "Events/Event.h"
#include "Events/WindowEvents.h"


/**
 * Base class for whole application.
 * Implements Singleton design pattern.
 */
class Application
{
private:
    Application();
public:
    ~Application();

    /**
     * Object initialization function
     * @return Pointer to (only) instance of this class
     */
    static Application* create();

    /** 
     * Application's "main" function; contains game loop.
     */
    void run();

    void onWindowClose(WindowCloseEvent& e);
    void onWindowResize(WindowResizeEvent& e);

private:
    bool m_isRunning;
    static Application* m_instance;
    std::unique_ptr<Window> m_window;
};

