#include "Game.h"

Game::Game() {
    renderingEngine = RenderingEngine::getInstance();
}

Game::~Game() {
    delete renderingEngine;
}

void Game::start() {
    initialize();
    run();
    conclude();
}

void Game::stop() {
    playing = false;
}

void Game::run() {
    renderingEngine->start();
    while (playing)
    {
        update();
        //draw(renderingEngine.getRenderingBuffer());
        renderingEngine->drawBufferOnScreen();
    }
    renderingEngine->stop();
}