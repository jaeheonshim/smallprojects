#include <iostream>
#include "paddle.hpp"
#include "constants.hpp"
#include "util.hpp"

void Paddle::update(double deltaTime) {
    yPos = clamp(yPos + deltaTime * yVel, static_cast<double>(BORDER_SIZE), static_cast<double>(WINDOW_HEIGHT - Paddle::HEIGHT - BORDER_SIZE));

    if(!(
            ball.xPos - Ball::WIDTH / 2 > xPos + Paddle::WIDTH ||
            ball.xPos + Ball::WIDTH / 2 < xPos ||
            ball.yPos - Ball::HEIGHT / 2 > yPos + Paddle::HEIGHT ||
            ball.yPos + Ball::HEIGHT / 2 < yPos
        ) &&
        sgn(ball.xVel) == sgn(xPos + Paddle::WIDTH / 2 - ball.xPos)) {

        double normalizedCollisionPoint{ (ball.yPos - yPos) / Paddle::HEIGHT * 2.0 - 1.0 };
        double theta = normalizedCollisionPoint * 3.14159265 / 4.0;
        double velocityMag = std::sqrt(ball.xVel * ball.xVel + ball.yVel * ball.yVel);

        ball.xVel = velocityMag * std::cos(theta) * -sgn(ball.xVel);
        ball.yVel = velocityMag * std::sin(theta);
    }
}

void Paddle::draw(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    SDL_Rect drawRect = {static_cast<int>(xPos), static_cast<int>(yPos), WIDTH, HEIGHT};
    SDL_RenderFillRect(renderer, &drawRect);
}