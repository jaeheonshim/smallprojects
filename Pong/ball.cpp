#include "ball.hpp"
#include "constants.hpp"

void Ball::draw(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    SDL_Rect drawRect{ static_cast<int>(xPos - WIDTH / 2), static_cast<int>(yPos - HEIGHT / 2), WIDTH, HEIGHT };
    SDL_RenderFillRect(renderer, &drawRect);
}

void Ball::update(double deltaTime) {
    xPos += deltaTime * xVel;
    yPos += deltaTime * yVel;

    if(yPos - WIDTH / 2.0 < BORDER_SIZE && yVel < 0) {
        yVel *= -1;
    }

    if(yPos + WIDTH / 2.0 > WINDOW_HEIGHT - BORDER_SIZE && yVel > 0) {
        yVel *= -1;
    }
}