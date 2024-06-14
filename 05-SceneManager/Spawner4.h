#pragma once
#include "Spawner.h"

class CSpawner4 : public CSpawner {
public:
	CSpawner4(float x, float y) : CSpawner(x, y) {
		subObjects.clear();
		//WingGoomba
		subObjects.push_back(3);
	}
};