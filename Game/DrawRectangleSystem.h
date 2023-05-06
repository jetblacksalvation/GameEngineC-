#pragma once
#include "ISystem.h"
#include "GameInit.hpp"
#include "PositionComponent.h"
#include "PlayerInputComponent.h"
#include "RectangleComponent.h"
class DrawRectangleSystem :
    public ISystem
{
    virtual void Process(double x);
};

