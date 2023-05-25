#include "Includes.h"
std::shared_ptr<GameObject>SceneTree::SceneRoot = std::make_shared<GameObject>();

std::vector<GameObject*> LevelOrderTraversal(std::vector<std::string> ComponentNames);
std::vector<GameObject*> SceneTree::GetGameObjects(std::vector<std::string> ComponentNames) {
	std::vector<GameObject*> output;
	for (auto GameObj : LevelOrderTraversal(ComponentNames)) {
		auto temp = (*GameObj)[ComponentNames];
		if (temp.size() >= ComponentNames.size()) {
			output.push_back(GameObj);
		}
	}
	return  output;
}
std::vector<GameObject*> LevelOrderTraversal(std::vector<std::string> ComponentNames) {
	std::vector<GameObject*> output({ &root });
	size_t current_index = 0;
	while (output.size() > current_index) {
		for (auto& iter : output[current_index]->GetChildren()) {
			if(iter.get() != nullptr)
			output.push_back(iter.get());
		}
		current_index++;
	}
	
	return output;
	//std::vector<GameObject*> ret;
	//if (&root == NULL)
	//	return{};
	//std::queue<GameObject*> q;

	//q.push(&root);
	//if (root.operator[](ComponentNames).size() != 0) {
	//	ret.push_back(&root);
	//}
	//while (!q.empty()) {
	//	size_t n = q.size();
	//	while (n > 0) {

	//		GameObject* p = q.front();

	//		q.pop();

	//		for (size_t i = 0; i < p->GetChildren().size(); i++) {
	//			q.push(p->GetChildren()[i].get());

	//			if ( (*p->GetChildren()[i])[ComponentNames].size() >= ComponentNames.size()) {
	//				ret.push_back(p->GetChildren()[i].get());
	//			}
	//		}
	//		n--;
	//	}
	//}

	//return ret;

}