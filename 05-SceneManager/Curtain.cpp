#include "Curtain.h"
#include "Title.h"
#include "debug.h"

void CCurtain::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_CURTAIN)->Render(x, y);
	settimer = true;
	//RenderBoundingBox();
}
void CCurtain::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - CURTAIN_BBOX_WIDTH / 2;
	t = y - CURTAIN_BBOX_HEIGHT / 2;
	r = l + CURTAIN_BBOX_WIDTH;
	b = t + CURTAIN_BBOX_HEIGHT;
}

void CCurtain::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) 
{
	if (settimer) timer += dt;
	if (timer > 1000) {
		if (y > -150) vy = -0.09f;
		else 
		{
			subObject = new CTitle(x, y);
			subObject->SetPosition(153, y);
			CreateSubObject = true;
			this->isDeleted = true;
		}
		y += vy * dt;
	}
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}