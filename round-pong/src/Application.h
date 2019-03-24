#pragma once
#include "Window.h"


/**
 * Base class for whole application.
 * Implements Singleton design pattern.
 */
class Application
{
public:
    /**
     * Object initialization function
     * @return Pointer to (only) instance of this class
     */
    static Application* create();

    /** 
     * Application's "main" function
     */
    void run();

    ~Application();

private:
    Application();

    static Application* m_instance;
    std::unique_ptr<Window> m_window;

    bool m_isRunning = true;
};

