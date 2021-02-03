#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

using std::string;

class sprite
{
private:
    SDL_Rect sRect;
public:
    SDL_Texture* texture = NULL;
    inline const SDL_Rect& get_sRect() const {return sRect;}
    sprite(const string &filename, SDL_Renderer* renderer, const SDL_Rect &sRect);
    ~sprite(){SDL_DestroyTexture(texture);};
};
