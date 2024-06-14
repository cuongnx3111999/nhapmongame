#pragma once
#include "Spawner.h"

class CSpawner3 : public CSpawner {
public:
	CSpawner3(float x, float y) : CSpawner(x, y) {
		subObjects.clear();
		//1 Koopas
		subObjects.push_back(2);
	}
};