#ifndef GAME_H
#define GAME_H

#include "RenderingEngine.h"

class Game {
private:
    RenderingEngine* renderingEngine;
    bool playing = true;
    void run();
public:
    Game();
    ~Game();
    virtual void initialize() = 0;
    virtual void update() = 0;
    // virtual void draw(Buffer buffer);
    virtual void conclude() = 0;
    void start();
    void stop();
};

#endif