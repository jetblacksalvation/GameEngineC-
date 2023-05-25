#pragma once
#include "ISystem.h"
#include "Includes.h"
class PlayerInputSystem :
    public ISystem
{
    virtual void Process(double x);
};

