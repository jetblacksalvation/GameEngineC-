#include "SystemHandler.h"
void SystemHandler::AddNewSystem(ISystem* system) {
	systems.push_back(static_cast<std::unique_ptr<ISystem>&&>(std::unique_ptr<ISystem>(system)));
}
void SystemHandler::RunSystems(double x) {
	for (auto& _Sysem : systems) {
		_Sysem.get()->Process(0);
	}
}