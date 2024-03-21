#ifndef RENDERING_ENGINE_H
#define RENDERING_ENGINE_H

#include <string> 

class RenderingEngine
{
private:
    static RenderingEngine* instance;
    // QWindow window;
    int height = 600;
    int width = 800;
    std::string title = "-----New Game-----";
    RenderingEngine();
public:
    static RenderingEngine* getInstance();
    ~RenderingEngine();
    void start();
    void stop();
    void setTitle(std::string title);
    void setViewport(int width, int height);
    int getViewportWidth();
    int getViewportHeight();
    // Buffer getRenderingBuffer();
    void drawBufferOnScreen();
};
#endif