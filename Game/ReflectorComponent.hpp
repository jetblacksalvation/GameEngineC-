#pragma once
#include "IComponent.h"

struct ReflectorComponent :public IComponent {
	enum ReflectState{
		ReflectInside = 1,
		ReflectOutside = 2
	};
	ReflectorComponent() {

	}
	ReflectorComponent(ReflectState state) {
		ReflectMode = state;

	}
	inline std::string GetName() override {
		return name;
	}
	ReflectState ReflectMode = ReflectInside;
	static inline const char* name = "ReflectorComponent";
};