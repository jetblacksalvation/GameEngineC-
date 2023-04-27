#pragma once
#include "ISystem.h"
class CountingSystem : public ISystem
{
public:
	int x = 0;
	virtual void Process();
};

