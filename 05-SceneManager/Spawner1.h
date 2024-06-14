#pragma once
#include "Spawner.h"

class CSpawner1 : public CSpawner {
public:
	CSpawner1(float x, float y) : CSpawner(x, y) {
		subObjects.clear();
		//Goomba
		subObjects.push_back(1);
	}
};