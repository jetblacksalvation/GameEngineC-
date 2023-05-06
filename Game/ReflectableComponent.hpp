#pragma once
#include "IComponent.h"

struct ReflectableComponent : public IComponent {
	std::string GetName() override {
		return name;
	}
	static inline const char* name = "ReflectableComponent";
};