#include "Includes.h"
std::shared_ptr<GameObject>SceneTree::SceneRoot = std::make_shared<GameObject>();

std::vector<GameObject*> LevelOrderTraversal(std::vector<std::string> ComponentNames);
std::vector<GameObject*> SceneTree::GetGameObjects(std::vector<std::string> ComponentNames) {
	std::vector<GameObject*> Obj_return = LevelOrderTraversal(ComponentNames);

	return Obj_return;
}
std::vector<GameObject*> LevelOrderTraversal(std::vector<std::string> ComponentNames) {
	std::vector<GameObject*> ret;
	if (&root == NULL)
		return{};
	std::queue<GameObject*> q;

	q.push(&root);
	if (root.operator[](ComponentNames).size() != 0) {
		ret.push_back(&root);
	}
	while (!q.empty()) {
		int n = q.size();
		while (n > 0) {

			GameObject* p = q.front();

			q.pop();

			for (size_t i = 0; i < p->GetChildren().size(); i++) {
				q.push(p->GetChildren()[i].get());

				if ( (*p->GetChildren()[i])[ComponentNames].size() != 0) {
					ret.push_back(p->GetChildren()[i].get());
				}
			}
			n--;
		}
	}
	return ret;

}