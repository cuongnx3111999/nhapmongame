#include "Title.h"
#include "TitleNumber.h"
#include "debug.h"

void CTitle::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_TITLE)->Render(x, y);
	//RenderBoundingBox();
}
void CTitle::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - TITLE_BBOX_WIDTH / 2;
	t = y - TITLE_BBOX_HEIGHT / 2;
	r = l + TITLE_BBOX_WIDTH;
	b = t + TITLE_BBOX_HEIGHT;
}

void CTitle::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (y < 70) y += 0.25f * dt;
	else if (!createdSubObject)
	{
		subObject = new CTitleNumber(x, y);
		subObject->SetPosition(x + 3, y + 54);
		CreateSubObject = true;
		createdSubObject = true;
	}
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}
