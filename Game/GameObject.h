#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include "IComponent.h"
class GameObject
{
public:
	GameObject* GetParent();
	IComponent* operator [](std::string key);
	void AddChild(GameObject child = {});
	void RemoveChild(GameObject *child);
	void AddComponent(std::unique_ptr<IComponent>& );
private:
	GameObject* _Parent = nullptr; 
	std::vector<std::unique_ptr<GameObject>> _Children;
	std::unordered_map<std::string, std::unique_ptr<IComponent>&> _Components;
};

