#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "Mario.h"
#include "Goomba.h"
#include "WingGoomba.h"
#include "Koopas.h"	
#include "WingKoopas.h"
#include "Mario.h"

//#define ID_ANI_

#define ID_ANI_SPAWNER 45000

#define SPAWNER_WIDTH 8
#define SPAWNER_BBOX_WIDTH 8
#define SPAWNER_BBOX_HEIGHT 400

class CSpawner : public CGameObject {
public:
	//
	CSpawner(float x, float y);
	vector<int> subObjects; //1 = Goomba, 2 = Koopas, 3 = WingGooma, 4 = WingKoopas
protected:
	
	ULONGLONG timer = 0;
	int index = 0;
	bool start = false, end = false;

	virtual void Render();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual int IsBlocking() { return 0; }
};