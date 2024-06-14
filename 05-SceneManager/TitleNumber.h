#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_TITLENUMBER 52000
#define TITLENUMBER_WIDTH 42
#define TITLENUMBER_BBOX_WIDTH 42
#define TITLENUMBER_BBOX_HEIGHT 41

class CTitleNumber : public CGameObject {
public:
	CTitleNumber(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt) {}
	int IsBlocking() { return 0; }
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};