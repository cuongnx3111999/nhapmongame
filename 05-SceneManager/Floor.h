#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_FLOOR 54000
#define FLOOR_WIDTH 305
#define FLOOR_BBOX_WIDTH 305
#define FLOOR_BBOX_HEIGHT 37

class CFloor : public CGameObject {
public:
	CFloor(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt) {}
	int IsBlocking() { return 1; }
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};