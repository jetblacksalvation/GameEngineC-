#pragma once
#include <iostream>
class IComponent
{
public:
	virtual std::string GetName() {
		std::cout << "Icomponent, this is sus if you get this, you used the wrong name prob change func to GetName()\n";
		return "IComponent";
	}

};

