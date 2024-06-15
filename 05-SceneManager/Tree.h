#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_TREE1 15000
#define ID_ANI_TREE2 16000
#define ID_ANI_TREE3 17000
#define ID_ANI_TREE4 18000

#define TREE1_WIDTH 128
#define TREE1_BBOX_WIDTH 128
#define TREE1_BBOX_HEIGHT 65

#define TREE2_WIDTH 127
#define TREE2_BBOX_WIDTH 127
#define TREE2_BBOX_HEIGHT 65

#define TREE3_WIDTH 64
#define TREE3_BBOX_WIDTH 64
#define TREE3_BBOX_HEIGHT 49

#define TREE4_WIDTH 96
#define TREE4_BBOX_WIDTH 96
#define TREE4_BBOX_HEIGHT 130

class CTree : public CGameObject {
protected:
	int type;
public:
	CTree(float x, float y, int type) : CGameObject(x, y) { this->type = type; }
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int IsBlocking() { return 0; }
};