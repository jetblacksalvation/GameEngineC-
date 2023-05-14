#include "ReflectSystem.h"
void ReflectSystem::Process(double x) {
	auto Reflectors = SceneTree::GetGameObjects({ReflectorComponent::name, PositionComponent::name, RectangleComponent::name, VelocityComponent::name});
}