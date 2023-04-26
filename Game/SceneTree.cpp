#include "Includes.h"
std::shared_ptr<GameObject>SceneTree::SceneRoot = std::unique_ptr<GameObject>(new GameObject);
std::vector<GameObject*> LevelOrderTraversal();
std::vector<GameObject*> SceneTree::GetGameObjects(std::vector<std::string> ComponentNames) {
	std::vector<GameObject*> Obj_return; 
	for (auto it : LevelOrderTraversal()) {
		if((*it)[ComponentNames])
	}
}