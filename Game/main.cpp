// Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Includes.h"
template<class T> T& unmove(T&& t) { return t; }

int main()
{
	root.AddComponent(new IComponent);

	for (int x = 0; x < 1000; x++) {
		root.AddChild();
	}
	auto& list = root.GetChildren();//need to grab by reference, can't not do that
	std::cout << list.size() << " is the size\n";
	{
		std::vector<std::unique_ptr<GameObject>>::iterator iter = list.begin();
		while (iter != list.end()) {

			// if track is empty, remove it
			iter = list.erase(iter);
		}
	}
	std::cout << list.size() << " is end size\n";
	return 0;
}
