#include "RenderingEngine.h"

RenderingEngine* RenderingEngine::instance;

RenderingEngine* RenderingEngine::getInstance() {
    if (instance == nullptr) instance = new RenderingEngine();
    return instance;
}

RenderingEngine::RenderingEngine() {

}

RenderingEngine::~RenderingEngine() {

}

void RenderingEngine::start() {
    //mettre visible la window
}

void RenderingEngine::stop() {
    //mettre invisble la window
    //flouer le buffer d'image
}

void RenderingEngine::setTitle(std::string title) {
    this->title = title;
}

void RenderingEngine::setViewport(int width, int heigth) {
    this->width = width;
    this->height = height;
}

int RenderingEngine::getViewportWidth() {
    return width;
}

int RenderingEngine::getViewportHeight() {
    return height;
}

void RenderingEngine::drawBufferOnScreen() {
    //maybe englober la function de Qt
}