#pragma once
#include "IComponent.h"

struct ReflectorComponent :public IComponent {
	std::string GetName() override {
		return name;
	}
	static inline const char* name = "ReflectorComponent";
};