#pragma once
#include <iostream>
class IComponent
{
public:
<<<<<<< HEAD
	virtual std::string GetName() {
		return "IComponent";
	}
=======
	const virtual std::string GetName() {
		return "IComponent";
	};
	
>>>>>>> 3509bc447ddbe72a9c5a2f489f62d49212194a90
};

