#pragma once
#include "IComponent.h"
#include "GameInit.hpp"
struct RectangleComponent :
public IComponent
{
    static inline const char* name = "RectangleComponent";

    std::string GetName() {
        return name;
    }
    RectangleComponent(float width, float hieght) {
        this->width = width;
        this->hieght = hieght;
        fill_color = white;
        outline_color = white;
    }
    float width, hieght;


    ALLEGRO_COLOR fill_color = white;
    ALLEGRO_COLOR outline_color = white;

};

