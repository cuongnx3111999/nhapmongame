#include "BackgroundItems.h"

void CBackgroundItems::Render()
{
	int aniId = ID_ANI_BACKGROUNDITEMS_2;
	if (timer > 5300) aniId = ID_ANI_BACKGROUNDITEMS;
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(aniId)->Render(x, y);
	//RenderBoundingBox();
}
void CBackgroundItems::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - BACKGROUNDITEMS_BBOX_WIDTH / 2;
	t = y - BACKGROUNDITEMS_BBOX_HEIGHT / 2;
	r = l + BACKGROUNDITEMS_BBOX_WIDTH;
	b = t + BACKGROUNDITEMS_BBOX_HEIGHT;
}
void CBackgroundItems::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) 
{
	if (settimer) timer += dt;
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}