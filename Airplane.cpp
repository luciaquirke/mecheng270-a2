#include "Airplane.hpp"

Airplane::Airplane(int capacity) {
	airplaneCapacity = capacity;
}

int Airplane::getCapacity() const {
	return airplaneCapacity;
}
