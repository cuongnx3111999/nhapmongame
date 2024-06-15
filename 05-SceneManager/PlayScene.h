#pragma once
#include "Game.h"
#include "Textures.h"
#include "Scene.h"
#include "GameObject.h"
#include "Brick.h"
#include "Mario.h"
#include "Goomba.h"
#include "MysteryBox.h"
#include "Bush.h"
#include "Tree.h"
#include "WarpPipe.h"
#include "Cloud.h"
#include "ColorBox.h"
#include "Wood.h"
#include "PipeBelow.h"
#include "PipeAbove.h"
#include "BlackBackground.h"
#include "Prize.h"
#include "CoinFromBox.h"
#include "MushRoom.h"
#include "Koopas.h"
#include "GreenKoopas.h"
#include "ParaGoomba.h"
#include "WingKoopas.h"
#include "Curtain.h"
#include "Floor.h"
#include "Title.h"
#include "TitleNumber.h"
#include "Background.h"
#include "BackgroundItems.h"
#include "PakkunFlower1.h"
#include "PakkunFlower2.h"
#include "PakkunFlower3.h"
#include "Spawner.h"
#include "Spawner1.h"
#include "Spawner2.h"
#include "Spawner3.h"	
#include "Spawner4.h"
//#include "PakkunFlower1.h"


class CPlayScene: public CScene
{
static CPlayScene* __instance;
protected: 
	// A play scene has to have player, right? 
	LPGAMEOBJECT player;					

	vector<LPGAMEOBJECT> objects;

	void _ParseSection_SPRITES(string line);
	void _ParseSection_ANIMATIONS(string line);

	void _ParseSection_ASSETS(string line);
	void _ParseSection_OBJECTS(string line);

	void LoadAssets(LPCWSTR assetFile);
	
public: 
	CPlayScene(int id, LPCWSTR filePath);

	virtual void Load();
	virtual void Update(DWORD dt);
	virtual void Render();
	virtual void Unload();

	LPGAMEOBJECT GetPlayer() { return player; }

	void Clear();
	void PurgeDeletedObjects();

	static bool IsGameObjectDeleted(const LPGAMEOBJECT& o);
	virtual void SpawnGameObject(CGameObject* obj, float x, float y);
};

typedef CPlayScene* LPPLAYSCENE;

