#include "Prize.h"

void CPrize::Render()
{
	int aniId = ID_ANI_PRIZE_MUSHROOM;
	switch (state) {
	case PRIZE_STATE_MUSHROOM:
		aniId = ID_ANI_PRIZE_MUSHROOM; break;
	case PRIZE_STATE_FLOWER:
		aniId = ID_ANI_PRIZE_FLOWER; break;
	case PRIZE_STATE_STAR:
		aniId = ID_ANI_PRIZE_STAR; break;
	case PRIZE_STATE_MUSHROOM_FLYUP:
		aniId = ID_ANI_PRIZE_MUSHROOM_FLYUP; break;
	case PRIZE_STATE_FLOWER_FLYUP:
		aniId = ID_ANI_PRIZE_FLOWER_FLYUP; break;
	case PRIZE_STATE_STAR_FLYUP:
		aniId = ID_ANI_PRIZE_STAR_FLYUP; break;
	}
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(aniId)->Render(x, y);
	if (!settimer) {
		settimer = true;
		timer = 0;
	}
	//RenderBoundingBox();
}

void CPrize::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - PRIZE_BBOX_WIDTH / 2;
	t = y - PRIZE_BBOX_HEIGHT / 2;
	r = l + PRIZE_BBOX_WIDTH;
	b = t + PRIZE_BBOX_HEIGHT;
}

void CPrize::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	y += vy * dt;
	if (!activated) {
		 if (timer < 150) {
			SetState(PRIZE_STATE_MUSHROOM);
			timer += dt;
		}
		else if (timer < 300) {
			SetState(PRIZE_STATE_FLOWER);
			timer += dt;
		}
		else if (timer < 450) {
			SetState(PRIZE_STATE_STAR);
			timer += dt;
		}
	else if (timer != NULL) timer = 0;
	}
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CPrize::SetState(int state) 
{
	if (state == PRIZE_STATE_MUSHROOM_FLYUP || state == PRIZE_STATE_FLOWER_FLYUP || state == PRIZE_STATE_STAR_FLYUP) 
	{
		vy = -0.22f;
		activated = true;
	}
	CGameObject::SetState(state);
}
