#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "ColorBoxesID.h"


class CColorBox : public CGameObject {
protected: 
	int type;
public:
	CColorBox(float x, float y, int type) : CGameObject(x, y) { this->type = type; }
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual int IsBlocking() { return 0; }
	virtual int IsStair() { return 1; }
};