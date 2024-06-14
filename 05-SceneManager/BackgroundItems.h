#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_BACKGROUNDITEMS 56000
#define ID_ANI_BACKGROUNDITEMS_2 56100
#define BACKGROUNDITEMS_WIDTH 305
#define BACKGROUNDITEMS_BBOX_WIDTH 305
#define BACKGROUNDITEMS_BBOX_HEIGHT 187

class CBackgroundItems : public CGameObject {
protected:
	bool settimer = false;
	ULONGLONG timer = 0;
public:
	CBackgroundItems(float x, float y) : CGameObject(x, y) { settimer = true; }
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	int IsBlocking() { return 0; }
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};