#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include "IComponent.h"
class GameObject
{
public:
	GameObject() {};
	
	GameObject* GetParent();

	IComponent* operator [](std::string key);
	std::unordered_map<std::string, std::shared_ptr<IComponent>> operator [](std::vector<std::string>);

	void AddChild(GameObject* = {});
	void RemoveChild(GameObject *);
	void AddComponent(IComponent * );
	void RemoveComponent(std::string);
	void RemoveComponent(IComponent*);
	void RemoveAllChildren();
	std::vector<std::unique_ptr<GameObject>>& GetChildren();
private:
	GameObject* _Parent = nullptr; 
	std::vector<std::unique_ptr<GameObject>> _Children;
	std::unordered_map<std::string, std::shared_ptr<IComponent>> _Components;
};

