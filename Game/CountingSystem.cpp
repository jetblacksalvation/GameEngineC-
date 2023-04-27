#include "CountingSystem.h"
class CountingSystem;

void CountingSystem::Process() {
	std::cout << this->x;
	x++;
};