#ifndef BALL_H
#define BALL_H

#include <SDL2/SDL.h>
#include "constants.hpp"

struct Ball {
public:
    static constexpr int WIDTH = 15;
    static constexpr int HEIGHT = 15;

    Ball(double xPos, double yPos, double xVel, double yVel) : xPos{ xPos }, yPos{ yPos }, xVel{ xVel }, yVel{ yVel } {

    }

    void update(double deltaTime);
    void draw(SDL_Renderer* renderer);

    double xPos{};
    double yPos{};
    double xVel{};
    double yVel{};
};

#endif