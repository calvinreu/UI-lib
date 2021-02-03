#include <SDL2/SDL.h>
#include <sprite.hpp>
#pragma once

class instance
{
private:
    const sprite* parent;
public:
    SDL_FRect dRect;
    double angle;
    SDL_FPoint center;
    SDL_RendererFlip flip = SDL_FLIP_NONE;

    inline instance(const sprite &parent) : parent(&parent) {}
    //add texture to render target
    inline void render(SDL_Renderer *renderer) { SDL_RenderCopyExF(renderer, parent->texture, &(parent->get_sRect()), &dRect, angle, &center, flip);}
    //move texture
    inline void move(const float &x, const float &y) {dRect.x+=x; dRect.y+=y;}
    //set position on screen
    inline void operator()(const float &x, const float &y) {dRect.x = x; dRect.y = y;}
    //check if instance is selected NOTE: uses dRect as colision shape it will return true if the cursor is on a transparent pixel within the dRect
    bool is_selected(const int &cursor_x, const int &cursor_y){ return cursor_x > dRect.x && cursor_x < dRect.x + dRect.w && cursor_y > dRect.y && cursor_y < dRect.y + dRect.h; }
    ~instance();
};