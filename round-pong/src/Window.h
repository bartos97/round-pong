#pragma once

/**
 * Singleton class for creating OS window
 */
class Window {
public:
    static Window* create();
    ~Window();

private:
    static Window* instance;
    int m_width;
    int m_height;
    std::string m_title;

    void init();
    Window( int width = 1280,
            int height = 720,
            const std::string& title = "Round Pong");

    //Singleton protection stuff
public:
    Window(const Window&) = delete;
    void operator=(const Window&) = delete;
};

