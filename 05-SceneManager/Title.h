#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_TITLE 51000
#define TITLE_WIDTH 256
#define TITLE_BBOX_WIDTH 256
#define TITLE_BBOX_HEIGHT 108

class CTitle : public CGameObject {
protected:
	bool createdSubObject = false;
public:
	CTitle(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt) {}
	int IsBlocking() { return 0; }
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};