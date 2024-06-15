#include "ColorBox.h"

void CColorBox::Render()
{
	int aniId;
	switch (type) {
	case 0: aniId = ID_ANI_COLOLRBOX0; break;
	case 1: aniId = ID_ANI_COLOLRBOX1; break;
	case 2: aniId = ID_ANI_COLOLRBOX2; break;
	case 3: aniId = ID_ANI_COLOLRBOX3; break;
	case 4: aniId = ID_ANI_COLOLRBOX4; break;
	case 5: aniId = ID_ANI_COLOLRBOX5; break;
	case 6: aniId = ID_ANI_COLOLRBOX6; break;
	case 7: aniId = ID_ANI_COLOLRBOX7; break;
	case 8: aniId = ID_ANI_COLOLRBOX8; break;
	case 9: aniId = ID_ANI_COLOLRBOX9; break;
	}
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(aniId)->Render(x + 4, y + 4);
	//RenderBoundingBox();
}

void CColorBox::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	int width, height;
	switch (type) {
	case 0: width = COLOLRBOX0_BBOX_WIDTH; height = COLOLRBOX0_BBOX_HEIGHT; break;
	case 1: width = COLOLRBOX1_BBOX_WIDTH; height = COLOLRBOX1_BBOX_HEIGHT; break;
	case 2: width = COLOLRBOX2_BBOX_WIDTH; height = COLOLRBOX2_BBOX_HEIGHT; break;
	case 3: width = COLOLRBOX3_BBOX_WIDTH; height = COLOLRBOX3_BBOX_HEIGHT; break;
	case 4: width = COLOLRBOX4_BBOX_WIDTH; height = COLOLRBOX4_BBOX_HEIGHT; break;
	case 5: width = COLOLRBOX5_BBOX_WIDTH; height = COLOLRBOX5_BBOX_HEIGHT; break;
	case 6: width = COLOLRBOX6_BBOX_WIDTH; height = COLOLRBOX6_BBOX_HEIGHT; break;
	case 7: width = COLOLRBOX7_BBOX_WIDTH; height = COLOLRBOX7_BBOX_HEIGHT; break;
	case 8: width = COLOLRBOX8_BBOX_WIDTH; height = COLOLRBOX8_BBOX_HEIGHT; break;
	case 9: width = COLOLRBOX9_BBOX_WIDTH; height = COLOLRBOX9_BBOX_HEIGHT; break;
	}
	l = x - width / 2;
	t = y - height / 2;
	r = l + width;
	b = t + height;
}