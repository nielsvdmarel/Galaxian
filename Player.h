#pragma once
#include "GameObject.h"
#include "Projectile.h"
using namespace Tmpl8;
class Player : public GameObject {
public:
	Player(GameObject gameobject);
	~Player();
	void onCollision(GameObject* other);
	void Update();
	//void Render();
	void MoveXPos(int movement);
	//void MoveYpos();
	float playerMovement;
	float minXPos, maxXpos;
	void ShootProjectile();
	bool IsAbleToShoot;
	Projectile* currentProjectile;
private:
};

