#include <iostream>
#include <SDL2/SDL.h>
#include "constants.hpp"
#include "paddle.hpp"
#include "ball.hpp"

SDL_Window* g_window;
SDL_Renderer* g_renderer;

bool init() {
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Failed to init SDL! " << SDL_GetError() << '\n';
        return false;
    }

    g_window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if(g_window == nullptr) {
        std::cerr << "Failed to create window! " << SDL_GetError() << '\n';
        return false;
    }

    g_renderer = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
    if(g_renderer == nullptr) {
        std::cerr << "Failed to create renderer! " << SDL_GetError() << '\n';
        return false;
    }

    return true;
}

int main(int argc, char* args[]) {
    if(!init()) {
        std::cerr << "Failed to initialize!\n";
        return -1;
    }

    Ball ball(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 400, 0);
    Paddle paddle1(35, ball);
    Paddle paddle2(WINDOW_WIDTH - Paddle::WIDTH - 35, ball);

    Uint64 last{ 0 };
    Uint64 now{ SDL_GetPerformanceCounter() };
    double deltaTime;

    bool quit{ false };

    SDL_Event event;
    while(!quit) {
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) quit = true;
            else if(event.type == SDL_KEYDOWN) {
                switch(event.key.keysym.sym) {
                    case SDLK_w:
                        paddle1.setYVel(-PADDLE_SPEED);
                        break;
                    case SDLK_s:
                        paddle1.setYVel(PADDLE_SPEED);
                        break;
                    case SDLK_UP:
                        paddle2.setYVel(-PADDLE_SPEED);
                        break;
                    case SDLK_DOWN:
                        paddle2.setYVel(PADDLE_SPEED);
                        break;
                }
            } else if(event.type == SDL_KEYUP) {
                switch(event.key.keysym.sym) {
                    case SDLK_w:
                    case SDLK_s:
                        paddle1.setYVel(0);
                        break;
                    case SDLK_UP:
                    case SDLK_DOWN:
                        paddle2.setYVel(0);
                        break;
                }
            }
        }

        SDL_SetRenderDrawColor(g_renderer, 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderClear(g_renderer);

        SDL_SetRenderDrawColor(g_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_Rect frameRect{0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};
        SDL_RenderFillRect(g_renderer, &frameRect);

        SDL_SetRenderDrawColor(g_renderer, 0x00, 0x00, 0x00, 0xFF);
        frameRect = {BORDER_SIZE, BORDER_SIZE, WINDOW_WIDTH - 2 * BORDER_SIZE, WINDOW_HEIGHT - 2 * BORDER_SIZE};
        SDL_RenderFillRect(g_renderer, &frameRect);

        last = now;
        now = SDL_GetPerformanceCounter();

        deltaTime = (double) (now - last) / SDL_GetPerformanceFrequency();

        paddle1.update(deltaTime);
        paddle2.update(deltaTime);
        ball.update(deltaTime);

        paddle1.draw(g_renderer);
        paddle2.draw(g_renderer);
        ball.draw(g_renderer);

        SDL_RenderPresent(g_renderer);
    }
}