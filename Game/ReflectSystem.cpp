#include "ReflectSystem.h"
void ReflectSystem::Process(double x) {
	auto Reflectors_lists = SceneTree::GetGameObjects({ReflectorComponent::name, PositionComponent::name, RectangleComponent::name});
	auto Reflectable_lists = SceneTree::GetGameObjects({ ReflectableComponent::name, PositionComponent::name,RectangleComponent::name,VelocityComponent::name });

	for (auto reflectable : Reflectable_lists) {
		auto& reflectable_x = ((PositionComponent*)(*reflectable)[PositionComponent::name])->x;
		auto& reflectable_y = ((PositionComponent*)(*reflectable)[PositionComponent::name])->y;
		auto& reflectable_w = ((RectangleComponent*)(*reflectable)[RectangleComponent::name])->width;
		auto& reflectable_h = ((RectangleComponent*)(*reflectable)[RectangleComponent::name])->hieght;

		reflectable_x += ((VelocityComponent*)(*reflectable)[VelocityComponent::name])->x_vel;
		reflectable_y += ((VelocityComponent*)(*reflectable)[VelocityComponent::name])->y_vel;

		for (auto reflector : Reflectors_lists) {
			auto& reflector_x = ((PositionComponent*)(*reflector)[PositionComponent::name])->x;
			auto& reflector_y = ((PositionComponent*)(*reflector)[PositionComponent::name])->y;

			auto& reflector_w = ((RectangleComponent*)(*reflector)[RectangleComponent::name])->width;
			auto& reflector_h = ((RectangleComponent*)(*reflector)[RectangleComponent::name])->hieght;

			if (((ReflectorComponent*)(*reflector)[ReflectorComponent::name])->ReflectMode == ReflectorComponent::ReflectInside) {
				if (reflector_x< reflectable_x + reflectable_w &&
					reflector_x + reflector_w > reflectable_x &&
					reflector_y < reflectable_y + reflectable_h &&
					reflector_h + reflector_y > reflectable_y
				) {
					((VelocityComponent*)(*reflectable)[VelocityComponent::name])->x_vel *= -1;
				}
				
			}
			else if (((ReflectorComponent*)(*reflector)[ReflectorComponent::name])->ReflectMode == ReflectorComponent::ReflectOutside) {
				if (
					reflectable_x < reflector_x or
					reflectable_x + reflectable_w > reflector_x + reflector_w
					) {
					((VelocityComponent*)(*reflectable)[VelocityComponent::name])->x_vel *= -1;


				}
				if (reflectable_y < reflector_y or reflectable_y + reflectable_h> reflector_y + reflector_h) {
					((VelocityComponent*)(*reflectable)[VelocityComponent::name])->y_vel *= -1;


				}
			}

		}

	}



}