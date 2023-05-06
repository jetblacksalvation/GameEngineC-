// Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "includes.h"
#include "GameInit.hpp"
void AddNewBlock(float, float,float ,float);
int main()
{
	SystemHandler systems;
	systems.AddNewSystem(new DrawRectangleSystem);

	AddNewBlock(400,400, 100, 400);
	AddNewBlock(20, 20, 100, 400);

	m_setup();
	while (true)
	{
		al_clear_to_color({ 0,0,0,0 });
		systems.RunSystems(0);
		al_flush_event_queue(event_queue);

		al_flip_display();
	}
	//someting is leaking, plz fix :( 


	return 0;
}
void AddNewBlock(float x, float y, float w, float h) {
	root.AddChild();
	root.GetChildren()[root.GetChildren().size() - 1]->AddComponents(new PositionComponent(x, y), new PlayerInputComponent, new RectangleComponent(w,h));
}