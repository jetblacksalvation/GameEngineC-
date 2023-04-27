// Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Includes.h"
int main()
{
	root.AddComponent(new IComponent);

	for (int x = 0; x < 1000; x++) {
		root.AddChild();
	}
	for (auto& child : root.GetChildren()) {
		root.RemoveChild(child.get());
	}
	return 0;
}
