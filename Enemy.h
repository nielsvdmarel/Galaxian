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
	void DiveAttack(int playerxPos, int playerYpos);
	enum EnemyState {Nothing = 0, FindFriends, ARC, Fly, Resseting};
private:
	EnemyState currentEnemyState;

};

