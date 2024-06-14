#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_PRIZE_MUSHROOM 34000
#define ID_ANI_PRIZE_FLOWER 34001
#define ID_ANI_PRIZE_STAR 34002
#define ID_ANI_PRIZE_MUSHROOM_FLYUP 34003
#define ID_ANI_PRIZE_FLOWER_FLYUP 34004
#define ID_ANI_PRIZE_STAR_FLYUP 34005

#define PRIZE_WIDTH 26
#define PRIZE_BBOX_WIDTH 26
#define PRIZE_BBOX_HEIGHT 26

#define PRIZE_STATE_MUSHROOM 100
#define PRIZE_STATE_FLOWER 200
#define PRIZE_STATE_STAR 300
#define PRIZE_STATE_MUSHROOM_FLYUP 400
#define PRIZE_STATE_FLOWER_FLYUP 500
#define PRIZE_STATE_STAR_FLYUP 600

class CPrize : public CGameObject {
protected:
	ULONGLONG timer = 0;
	bool settimer = false, activated = false;
public:
	CPrize(float x, float y) : CGameObject(x, y) { state = PRIZE_STATE_MUSHROOM; }
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int IsBlocking() { return 0; }
	virtual void SetState(int state);
};