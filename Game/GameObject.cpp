#include "GameObject.h"
GameObject* GameObject::GetParent() {
	return _Parent;

};
IComponent* GameObject::operator [](std::string key) {
	if (_Components.find(key) == _Components.end()) {
		//throw std::invalid_argument("key not in _Components");
		return 0;
	}
	else if (_Components.size() <= 0) {
		return 0;
	}
	else {

		return _Components[key].get();
	}
}
void GameObject::AddChild(GameObject* child ) {
	if (child == NULL) {
		_Children.push_back(std::move(std::make_unique<GameObject>()));

	}
	else {
		_Children.push_back(static_cast<std::unique_ptr<GameObject>&&>(std::unique_ptr<GameObject>(child)));
	}
	
}
static int count = 0; 
void GameObject::RemoveChild(GameObject* child) 
{
	decltype(_Children)::iterator iter = _Children.begin();
	while (iter != _Children.end()) {
		if ((*iter).get()== child) {
			// if track is empty, remove it
			iter = _Children.erase(iter);
			std::cout << "Number of children destroyed is =" << ++count << "\n";
			return;
		}
		else {
			//if there are points, deque
			++iter;
		}
	}

};
void GameObject::RemoveComponent(IComponent* component) {
	_Components.erase(component->GetName());
}
void GameObject::RemoveComponent(std::string name) {
	_Components.erase(name);
}
void GameObject::AddComponent(IComponent* component) {
	if (component != NULL) {
		if (_Components.find(component->GetName()) != _Components.end()) {
			throw std::invalid_argument("component already exists");
		}
		else {
			_Components.insert({ component->GetName(), std::unique_ptr<IComponent>(component) });

		}
	}
	if (component == NULL) {
		throw std::invalid_argument("A pointer ");
	}
}
std::vector<std::unique_ptr<GameObject>>& GameObject::GetChildren() {
	//you can only really use the more complex type of iterator to be able to iterate without any runtime bugs 
	//you need to store it as a reference
	return _Children;
}
void GameObject::RemoveAllChildren() {
	this->_Children.resize(0);
}
std::unordered_map<std::string, std::shared_ptr<IComponent>> GameObject::operator[](std::vector<std::string> comp_names) {
	std::unordered_map<std::string, std::shared_ptr<IComponent>> ret;
	for (auto comp_name : comp_names) {
		if (_Components.find(comp_name) != _Components.end()) {
			ret[comp_name] = _Components.find(comp_name)->second;
		}
	}
	return ret;
}
//void GameObject::AddComponent(IComponent* component) {
//	std::make_unique<IComponent>();
//
//	_Components[component->ComponentName] = ptr;
//	
//}
	