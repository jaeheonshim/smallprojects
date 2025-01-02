#ifndef PADDLE_H
#define PADDLE_H

#include <SDL2/SDL.h>
#include "ball.hpp"
#include "constants.hpp"

struct Paddle {
    static constexpr int WIDTH = 15;
    static constexpr int HEIGHT = 200;

    Paddle(double xPos, Ball& ball) : xPos{ xPos }, ball{ ball } {

    }

    void update(double deltaTime);
    void draw(SDL_Renderer* renderer);

    void setYVel(double yVel) {
        this->yVel = yVel;
    }

    double xPos{};
    double yPos{ WINDOW_HEIGHT / 2 - HEIGHT / 2 };
    double yVel{ 0 };
    Ball& ball;
};

#endif