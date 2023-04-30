#pragma once
#include "IComponent.h"
class PositionComponent :
    public IComponent
{
public:
    PositionComponent(float x, float y) {
        this->x = x;
        this->y = y;
    }
    std::string GetName() override {
        return "PositionComponent";
    }


    float x, y;
    inline static const char* name = "PositionComponent";

};

