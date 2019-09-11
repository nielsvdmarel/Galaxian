#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "surface.h"
#include "GameObject.h"
#include "Player.h"

using namespace Tmpl8;
class Enemy : public GameObject {
public:
	Enemy(GameObject gameobject);
	~Enemy();
	void onCollision(GameObject* other);
	void AttackPlayer();
	void Update();
	void Render();
	void DiveAttack(int playerxPos, int playerYpos);
	enum EnemyState {Idle = 0, Formation, Attack, GroupAttack, Resseting, die};
	int currentEnemyNum;
	void CreateEnemyBullets(GameObject* allObjects[]);
	void ShootAtPlayer(int playerPosX, int PlayerPosY);
private:
	EnemyState currentEnemyState;
	Projectile* enemyProjectiles[5];
	int lastUsedBullet;
};

