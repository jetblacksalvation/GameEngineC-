// Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Includes.h"
#include "GameInit.hpp"
int main()
{
	//SystemHandler systems;
	//systems.AddNewSystem(new DrawRectangleSystem);
	//root.AddComponents(new PositionComponent(400, 400), new PlayerInputComponent);
	m_setup();
	while (true)
	{
		al_clear_to_color({ 0,0,0,0 });


		al_flip_display();
	}
	//someting is leaking, plz fix :( 
	return 0;
}
