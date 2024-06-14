#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_BACKGROUND 55100
#define ID_ANI_BACKGROUND_BLACK 55200
#define ID_ANI_BACKGROUND_ORANGE 55300
#define ID_STATE_TURN 1
#define ID_STATE_BLACK 2
#define ID_STATE_ORANGE 3
#define BACKGROUND_WIDTH 305
#define BACKGROUND_BBOX_WIDTH 305
#define BACKGROUND_BBOX_HEIGHT 187

class CBackground : public CGameObject {
protected:
	bool settimer = false;
	ULONGLONG timer = 0;
public:
	CBackground(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	int IsBlocking() { return 0; }
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};