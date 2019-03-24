#pragma once

/**
 * Singleton class for creating OS native window
 */
class Window
{
public:
    /**
     * Object initialization function 
     * @return Pointer to (only) instance of this class
     */
    static Window* create();

    /**
     * Function to call every frame refresh
     */
    void onUpdate() noexcept;

    GLFWwindow* getWindow() const noexcept { return m_window; }
    ~Window();

private:
    Window(int width = 720,
           int height = 720,
           const std::string& title = "Round Pong");

    inline void initGLFW();
    inline void initGlad();
    inline void createWindow();
    inline void setCallbacks();

    static Window* m_instance;
    GLFWwindow*    m_window;
  
    /** 
     * Basic informations about window and pointer to callback function for all events.
     * Used to associate data with actual GLFW window object.
     */
    struct WindowData
    {
        unsigned int width;
        unsigned int height;
        std::string  title;
        // TODO: event callback function pointer
        // this function ought to be bind in Application
    };
    WindowData m_data;
};

