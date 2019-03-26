#pragma once
#include "Events/Event.h"
#include "Events/WindowEvents.h"
#include "Events/KeyEvents.h"


/**
 * Singleton class for creating OS native window
 * Available to create only from Application
 */
class Window
{
    friend class Application;
    
public:
    ~Window();

private:
    Window(int width = 720,
           int height = 720,
           const std::string& title = "Round Pong");

    /**
     * Object initialization function 
     * @return Pointer to (only) instance of this class
     */
    static Window* create();

    /**
     * Function to call every frame refresh
     */
    void onUpdate() noexcept;

    inline void initGLFW();
    inline void initGlad();
    inline void createWindow();
    inline void setCallbacks();    
  
    /** 
     * Basic informations about window and pointers to callback functions for events.
     * Used to associate data with actual GLFW window object.
     */
    struct WindowData
    {
        unsigned int width;
        unsigned int height;
        std::string  title;
        // these functions ought to be bind in Application
        std::function<void(WindowCloseEvent&)> callbackOnWindowClose;
        std::function<void(WindowResizeEvent&)> callbackOnWindowResize;
        std::function<void(KeyPressEvent&)> callbackOnKeyPress;
        std::function<void(KeyReleaseEvent&)> callbackOnKeyRelease;
    };

    WindowData      m_data;
    static Window*  m_instance;
    GLFWwindow*     m_window;
};

