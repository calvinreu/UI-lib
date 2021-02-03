#include <SDL2/SDL.h>
#include <vector>
#include <list>
#include <iostream>
#include "sprite.hpp"
#include "instance.hpp"
#pragma once

using std::string;
using std::cout;

class output
{
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
public:
    std::vector<sprite> sprites;
    std::list<instance> instances;

    //only call if there won't be any add_sprite() calls for this object otherwise there should be a seg fault or bugs
    void add_instance();

    void add_sprite();
    void new_frame();

    //load output object from json file
    output(const string &window_name, const string &output_config);
    output(const output &other) { cout << "copy of output instance is not allowed\n";}
    void operator=(const output &other) { cout << "copy of output instance is not allowed\n";}
    ~output();
};