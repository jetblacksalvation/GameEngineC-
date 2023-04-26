#pragma once
#include "GameObject.h"
struct SceneTree
{
	static std::shared_ptr<GameObject> SceneRoot;
	static std::vector<GameObject*> GetGameObjects(std::vector<std::string>);



};

