#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_CURTAIN 53000
#define CURTAIN_WIDTH 305
#define CURTAIN_BBOX_WIDTH 305
#define CURTAIN_BBOX_HEIGHT 187

class CCurtain : public CGameObject {
protected:
	bool initial = false, settimer = false;
	ULONGLONG timer = 0;
public:
	CCurtain(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	int IsBlocking() { return 0; }
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};