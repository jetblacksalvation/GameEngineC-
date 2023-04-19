// Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "GameObject.h"
int main()
{
	GameObject bruh;
	bruh.AddChild();
	bruh.AddComponent(new IComponent);	
	bruh.AddComponent(new IComponent);

}
