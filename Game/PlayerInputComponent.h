#pragma once
#include "IComponent.h"
class PlayerInputComponent :
    public IComponent
{
public:
    std::string GetGame() {
        return "PlayerInputComponent";
    }
    inline static const char* name = "PlayerInputComponent";
};

