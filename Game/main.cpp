// Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "includes.h"
#include "GameInit.hpp"
void AddNewBlock(float, float,float ,float);
void AddNewBall(float, float, float, float);
void AddScreenBounderies();

int main()
{
	SystemHandler systems;
	systems.AddNewSystem(new DrawRectangleSystem);
	systems.AddNewSystem(new ReflectSystem);
	systems.AddNewSystem(new PlayerInputSystem);
	//paddles 
	AddNewBlock(600,400, 10, 60);
	AddNewBlock(200, 400, 10, 60);

	AddNewBall(400, 400, 100, 100);
	AddScreenBounderies();
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

	//ReflectorComponent::name, PositionComponent::name, RectangleComponent::name, VelocityComponent::name
	root.AddChild();
	root.GetChildren()[root.GetChildren().size() - 1]->AddComponents(new PositionComponent(x, y), new ReflectorComponent, new RectangleComponent(w,h), new PlayerInputComponent);
}
void AddNewBall(float x, float y, float w, float h) {

	//ReflectorComponent::name, PositionComponent::name, RectangleComponent::name, VelocityComponent::name
	root.AddChild();
	root.GetChildren()[root.GetChildren().size() - 1]->AddComponents(new PositionComponent(x, y), new RectangleComponent(w, h), new VelocityComponent, new ReflectableComponent );
}
void AddScreenBounderies() {
	
	root.AddChild();
	root.GetChildren()[root.GetChildren().size() - 1]->AddComponents(new PositionComponent(0,0), new RectangleComponent(1200, 1200), new ReflectorComponent(ReflectorComponent::ReflectOutside));

}
