#include "Spawner.h"


CSpawner::CSpawner(float x, float y) {
}

void CSpawner::Render() {
	int aniId = ID_ANI_SPAWNER;
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(aniId)->Render(x, y);
	//RenderBoundingBox();
}

void CSpawner::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) 
{
	//mario trigger spawner and spawner start 
	if (end) return;
	if (!start && CGame::GetInstance()->GetCurrentScene()->xMario + 180 >= this->x)
	{
		start = true;
	}
	if (start) {
		if (index >= subObjects.size()) {
			end = true; return;
		}
		if (timer == 0) 
			this->timer = GetTickCount64() - 1000;
		
		subObject = NULL;
		switch (subObjects[index]) {
		case 1:
			subObject = new CGoomba(x, y); break;
		case 2:
			subObject = new CKoopas(x, y); break;
		case 3:
			subObject = new CWingGoomba(x, y); break;
		case 4:
			subObject = new CWingKoopas(x, y); break;
		default:
			subObject = new CGoomba(x, y); break;
		}
		subObject->SetPosition(x, y);
		if (GetTickCount64() - timer > 1000)
		{
			CreateSubObject = true;
				this->index++;
			this->timer = GetTickCount64();
		}
	}
	
}

void CSpawner::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - SPAWNER_BBOX_WIDTH / 2;
	t = y - SPAWNER_BBOX_HEIGHT / 2;
	r = l + SPAWNER_BBOX_WIDTH;
	b = t + SPAWNER_BBOX_HEIGHT;
}


