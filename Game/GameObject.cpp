#include "GameObject.h"
GameObject* GameObject::GetParent() {
	return _Parent;

};
IComponent* GameObject::operator [](std::string key) {
	if (_Components.find(key) == _Components.end()) {
		throw std::invalid_argument("key not in _Components");
	}
	std::cout << "got it \n";

	return _Components[key].get();

}
void GameObject::AddChild(GameObject child ) {

	_Children.emplace_back(std::make_unique<GameObject>());
	
}
void GameObject::RemoveChild(GameObject* child) 
{
	decltype(_Children)::iterator iter = _Children.begin();
	while (iter != _Children.end()) {
		if ((*iter).get()== child) {
			// if track is empty, remove it
			iter = _Children.erase(iter);
		}
		else {
			//if there are points, deque
			++iter;
		}
	}

};
//void GameObject::AddComponent(IComponent* component) {
//	std::make_unique<IComponent>();
//
//	_Components[component->ComponentName] = ptr;
//	
//}
	