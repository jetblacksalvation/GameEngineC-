#pragma once
#include "IComponent.h"

struct VelocityComponent : public IComponent {
	float x_vel = 1;
	float y_vel = 1;
	std::string GetName() override {
		return name;
	}
	static inline const char* name = "VelocityComponent";
}; 