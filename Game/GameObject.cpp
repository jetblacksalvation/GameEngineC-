#include "GameObject.h"
GameObject* GameObject::GetParent() {
	return _Parent;

};
IComponent* GameObject::operator [](std::string key) {
	if (_Components.find(key) == _Components.end()) {
		throw std::invalid_argument("key not in _Components");
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
		_Children.emplace_back(static_cast<std::unique_ptr<GameObject>&&>(std::make_unique<GameObject>()));

<<<<<<< HEAD
	}
	else {
		_Children.emplace_back(static_cast<std::unique_ptr<GameObject>&&>(std::unique_ptr<GameObject>(child)));

	}
=======
	//_Children.push_back(std::make_unique<GameObject>(child));
>>>>>>> 3509bc447ddbe72a9c5a2f489f62d49212194a90
	
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
<<<<<<< HEAD
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
=======
void GameObject::AddComponent(IComponent* component) {
	if (component != nullptr) {

		try
		{
			if (_Components.find(component->GetName()) != _Components.end()) {
				throw std::invalid_argument("component already exists");

			}
		}
		catch (const std::exception&)
		{
			//if error tracebacks to here, component already exists
			throw std::invalid_argument("component already exists");
		}

		//std::cout << "inserting\n"<<component->GetName();


		_Components.insert(std::pair<std::string, std::unique_ptr<IComponent>>(component->GetName(), component));

	}
	
	if (component == nullptr) {
		throw std::invalid_argument("A pointer to a component snt to AddComponent with no address/ is null ptr");
	}
	////_Components[component->ComponentName] = std::make_unique(*component);
	
}
>>>>>>> 3509bc447ddbe72a9c5a2f489f62d49212194a90
	