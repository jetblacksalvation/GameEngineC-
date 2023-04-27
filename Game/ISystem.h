#pragma once
#include "GameObject.h"
#include "SceneTree.h"
#include <iostream>
struct ISystem
{
public:
	virtual void Process(double delta);
};

