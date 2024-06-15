#pragma once
#include "GameObject.h"

#define ParaGoomba_GRAVITY 0.0006f
#define ParaGoomba_WALKING_SPEED 0.05f


#define ParaGoomba_BBOX_WIDTH 20
#define ParaGoomba_BBOX_HEIGHT 24

#define ParaGoomba_STATE_DIE 100
#define ParaGoomba_STATE_DIE_2 200

#define ID_ANI_ParaGoomba 38000

class CParaGoomba : public CGameObject
{
protected:
	float ax;
	float ay;

	ULONGLONG timer, jump_timer;

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	virtual int IsCollidable() { return !(state == ParaGoomba_STATE_DIE_2); }
	virtual int IsBlocking() { return 0; }
	virtual void OnNoCollision(DWORD dt);

	virtual void OnCollisionWith(LPCOLLISIONEVENT e);

public:
	CParaGoomba(float x, float y);
	virtual void SetState(int state);
};