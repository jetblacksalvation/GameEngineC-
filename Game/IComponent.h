#pragma once
#include <iostream>
class IComponent
{
public:
	const virtual std::string GetName() {
		return "IComponent";
	};
	
};

