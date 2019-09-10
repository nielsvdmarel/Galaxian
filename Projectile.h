#pragma once
#include <string>
#include "surface.h"
#include "GameObject.h"
using namespace Tmpl8;
class Projectile : public GameObject {
public:
	Projectile(GameObject gameobject);
	~Projectile();
	void onCollision(GameObject* other);
	int bulletSpeed;
	void Update();
	bool PlayerProjectile;
	int currentYvel;
private:
};

