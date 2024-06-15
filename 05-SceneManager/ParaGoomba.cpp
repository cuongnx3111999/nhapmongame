#include "ParaGoomba.h"
#include "Goomba.h"
#include "debug.h"

CParaGoomba::CParaGoomba(float x, float y) :CGameObject(x, y)
{
	this->ax = 0;
	this->ay = ParaGoomba_GRAVITY;
	vx = -ParaGoomba_WALKING_SPEED;
	jump_timer = 0;
}

void CParaGoomba::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x - ParaGoomba_BBOX_WIDTH / 2;
	top = y - ParaGoomba_BBOX_HEIGHT / 2;
	right = left + ParaGoomba_BBOX_WIDTH;
	bottom = top + ParaGoomba_BBOX_HEIGHT;
}

void CParaGoomba::OnNoCollision(DWORD dt)
{
	if (jump_timer > 1200) {
		vy -= 0.25f;
		jump_timer = 0;
	}
	else jump_timer += dt;
	x += vx * dt;
	y += vy * dt;
};

void CParaGoomba::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (e->ny < 0 && e->obj->IsStair())
	{
		vy = 0;
		//isOnPlatform = true;
	}
	if (!e->obj->IsBlocking()) return;
	if (dynamic_cast<CParaGoomba*>(e->obj)) return;

	if (e->ny != 0)
	{
		vy = 0;
	}
	else if (e->nx != 0)
	{
		vx = -vx;
	}
}

void CParaGoomba::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	vy += ay * dt;
	vx += ax * dt;
	if (state == ParaGoomba_STATE_DIE && GetTickCount64() - timer > 50) {
		this->Delete();
	}
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}


void CParaGoomba::Render()
{
	int aniId = ID_ANI_ParaGoomba;

	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
	//RenderBoundingBox();
}
void CParaGoomba::SetState(int state)
{
	CGameObject::SetState(state);
	if (state == ParaGoomba_STATE_DIE) 
	{
		subObject = new CGoomba(x, y);
		subObject->SetPosition(x, y + 4);
		CreateSubObject = true;
		timer = GetTickCount64();
	} 
	else if (state == ParaGoomba_STATE_DIE_2) 
	{
		y -= 10;
		vy = -0.05f;
		vx = 0;
		ax = 0;
	}
}

