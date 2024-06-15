#pragma once
#include "Koopas.h"
#define ID_ANI_GREENKOOPAS_WALKING_LEFT 37003
#define ID_ANI_GREENKOOPAS_WALKING_RIGHT 37004
#define ID_ANI_GREENKOOPAS_IDLE 37300
#define ID_ANI_GREENKOOPAS_SPINNING 37400
class CGreenKoopas : public CKoopas {
public:
	CGreenKoopas(float x, float y) : CKoopas(x, y) {}
	void Render()
	{
		int aniId;
		if (vx < 0) aniId = ID_ANI_GREENKOOPAS_WALKING_LEFT;
		else aniId = ID_ANI_GREENKOOPAS_WALKING_RIGHT;
		if (state == KOOPAS_STATE_IDLE)
		{
			aniId = ID_ANI_GREENKOOPAS_IDLE;
		}
		else if (state == KOOPAS_STATE_SPINNING) {
			aniId = ID_ANI_GREENKOOPAS_SPINNING;
		}
		CAnimations::GetInstance()->Get(aniId)->Render(x, y);
		//RenderBoundingBox();
	}
};