#include "TitleNumber.h"
#include "debug.h"

void CTitleNumber::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_TITLENUMBER)->Render(x, y);
	//RenderBoundingBox();
}
void CTitleNumber::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - TITLENUMBER_BBOX_WIDTH / 2;
	t = y - TITLENUMBER_BBOX_HEIGHT / 2;
	r = l + TITLENUMBER_BBOX_WIDTH;
	b = t + TITLENUMBER_BBOX_HEIGHT;
}