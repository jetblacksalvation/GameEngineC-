#include "Includes.h"
std::shared_ptr<GameObject>SceneTree::SceneRoot = std::unique_ptr<GameObject>(new GameObject);
std::vector<GameObject*> LevelOrderTraversal();
std::vector<GameObject*> SceneTree::GetGameObjects(std::vector<std::string> ComponentNames) {
	std::vector<GameObject*> Obj_return; 
	for (auto it : LevelOrderTraversal()) {
		if ((*it)[ComponentNames].size() >0) {
			Obj_return.push_back(it);
		}
	}
	return Obj_return;
}
std::vector<GameObject*> LevelOrderTraversal() {
	std::vector<GameObject*> ret;
	if (&root)
		return{};
	std::queue<GameObject*> q;
	q.push(&root);
	while (!q.empty()) {
		int n = q.size();
		while (n > 0) {
			GameObject* p = q.front();
			ret.push_back(p);
			q.pop();
			for (size_t i = 0; i < p->GetChildren().size(); i++)
				q.push(p->GetChildren()[i].get());
			n--;
		}
	}
	return ret;

}