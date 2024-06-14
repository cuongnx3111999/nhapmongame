#pragma once
#include "Spawner.h"

class CSpawner2 : public CSpawner {
public:
	CSpawner2(float x, float y) : CSpawner(x, y) {
		subObjects.clear();
		//WingKoopas + WingKoopas + WingKoopas
		subObjects.push_back(4);
		subObjects.push_back(4);
		subObjects.push_back(4);
	}
};