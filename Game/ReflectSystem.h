#pragma once
#include "ISystem.h"
#include "Includes.h"
struct ReflectSystem :
    public ISystem
{
    virtual void Process(double x); 
};

