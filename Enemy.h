#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "surface.h"
#include "GameObject.h"
using namespace Tmpl8;
class Enemy : public GameObject {
public:
	Enemy(GameObject gameobject);
	~Enemy();
	void onCollision(GameObject* other);
	void Update();
	void Render();
private:

};

