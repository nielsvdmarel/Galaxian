#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "surface.h"
#include "GameObject.h"
#include "Enemy.h"
#include "Player.h"
#include "Physics.h"
class EnemyManager {
public:
	EnemyManager(Collision* collision, Surface* renderCanvas, GameObject* allGameObjects[]);
	~EnemyManager();
	void Update();
	void RenderAllEnemies();
	void InstantiateArmy();
	Surface* m_renderCanvas;
	Enemy* AllEnemys[50];
	int xFormationPos;
	int yFormationPos;
	int xstartPos;
	int ystartPos;
	Collision* Refcollision;
	int enemyMap[6][10] = {
	{0,0,0,1,0,0,1,0,0,0},
	{0,0,2,2,2,2,2,2,0,0},
	{0,3,3,3,3,3,3,3,3,0},
	{4,4,4,4,4,4,4,4,4,4},
	{4,4,4,4,4,4,4,4,4,4},
	{4,4,4,4,4,4,4,4,4,4}
	};
private:

};	

