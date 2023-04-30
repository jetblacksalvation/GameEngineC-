#pragma once
#include "Includes.h"
struct SystemHandler
{
	void AddNewSystem(ISystem* system);

	template<typename ...t>
	void AddManyNewSysems(t...args) {
		(this->AddNewSystem(args), ...);
	}
	void RunSystems(double delta);

private:
	std::vector<std::unique_ptr<ISystem>> systems;
};

