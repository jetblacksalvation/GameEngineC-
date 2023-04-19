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

	//_Children.push_back(std::make_unique<GameObject>(child));
	
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
void GameObject::AddComponent(IComponent* component) {
	if (component != nullptr) {


		if (_Components.find(component->GetName()) == _Components.end()) {
			throw std::invalid_argument("component already exists");
		}
		_Components.insert(std::move(std::pair<std::string, std::unique_ptr<IComponent>>(component->GetName(), component)));
	}
	if (component == nullptr) {
		throw std::invalid_argument("A pointer to a component snt to AddComponent with no address/ is null ptr");
	}
	////_Components[component->ComponentName] = std::make_unique(*component);
	
}
	