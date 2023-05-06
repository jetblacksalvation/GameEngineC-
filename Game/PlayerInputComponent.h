#pragma once
#include "IComponent.h"
class PlayerInputComponent :
    public IComponent
{
public:
    std::string GetGame() {
        return name;
    }
    inline static const char* name = "PlayerInputComponent";
};

