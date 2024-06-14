#include "Background.h"

void CBackground::Render()
{
	int aniId;
	switch (state) {
	case ID_STATE_TURN:
		aniId = ID_ANI_BACKGROUND; break;
	case ID_STATE_ORANGE:
		aniId = ID_ANI_BACKGROUND_ORANGE; break;
	default:
		aniId = ID_ANI_BACKGROUND_BLACK; break;
	}
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(aniId)->Render(x, y);
	settimer = true;
	//RenderBoundingBox();
}
void CBackground::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - BACKGROUND_BBOX_WIDTH / 2;
	t = y - BACKGROUND_BBOX_HEIGHT / 2;
	r = l + BACKGROUND_BBOX_WIDTH;
	b = t + BACKGROUND_BBOX_HEIGHT;
}
void CBackground::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) 
{
	if (settimer) timer += dt;
	if (timer > 5300) 
	{
		SetState(ID_STATE_ORANGE);
		return;
	}
	if (timer > 4500) SetState(ID_STATE_TURN);
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}
