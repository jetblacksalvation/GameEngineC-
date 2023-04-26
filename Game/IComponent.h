#pragma once
#include <iostream>
class IComponent
{
public:
	virtual std::string GetName() {
		return "IComponent";
	}

};

