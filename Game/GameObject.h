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
<<<<<<< HEAD
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
=======
	void AddChild(GameObject child = {});
	void RemoveChild(GameObject *child);
	void AddComponent(IComponent* component);
	void RemoveComponent(IComponent*);
private:
	GameObject* _Parent = nullptr; 
	std::vector<std::unique_ptr<GameObject>> _Children;
	std::unordered_map<std::string, std::unique_ptr<IComponent>> _Components;
>>>>>>> 3509bc447ddbe72a9c5a2f489f62d49212194a90
};

