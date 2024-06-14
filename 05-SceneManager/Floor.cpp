#include "Floor.h"
#include "debug.h"

void CFloor::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_FLOOR)->Render(x, y);
	//RenderBoundingBox();
}
void CFloor::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - FLOOR_BBOX_WIDTH / 2;
	t = y - FLOOR_BBOX_HEIGHT / 2;
	r = l + FLOOR_BBOX_WIDTH;
	b = t + FLOOR_BBOX_HEIGHT;
}