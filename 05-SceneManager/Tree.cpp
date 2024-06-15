#include "Tree.h"

void CTree::Render()
{
	int aniId;
	switch (type) {
	case 1: aniId = ID_ANI_TREE1; break;
	case 2: aniId = ID_ANI_TREE2; break;
	case 3: aniId = ID_ANI_TREE3; break;
	case 4: aniId = ID_ANI_TREE4; break;
	}
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(aniId)->Render(x, y);
	//RenderBoundingBox();
}

void CTree::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	float width, height;
	switch (type) {
	case 1: width = TREE1_BBOX_WIDTH; height = TREE1_BBOX_HEIGHT; break;
	case 2: width = TREE2_BBOX_WIDTH; height = TREE2_BBOX_HEIGHT; break;
	case 3: width = TREE3_BBOX_WIDTH; height = TREE3_BBOX_HEIGHT; break;
	case 4: width = TREE4_BBOX_WIDTH; height = TREE4_BBOX_HEIGHT; break;
	}
	l = x - width / 2;
	t = y - height / 2;
	r = l + width;
	b = t + height;
}