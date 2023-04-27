#pragma once
#include "Includes.h"
struct SystemHandler
{
	void AddNewSystem(ISystem* system);
	void RunSystems(double delta);
private:
	std::vector<std::unique_ptr<ISystem>> systems;
};

