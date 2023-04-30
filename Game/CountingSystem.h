#pragma once
#include "ISystem.h"
#include "GameInit.hpp"
class CountingSystem : public ISystem
{
public:
	int x = 0;
	virtual void Process(double x);
	
};

