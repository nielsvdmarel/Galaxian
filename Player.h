#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "surface.h"
#include "GameObject.h"
using namespace Tmpl8;
class Player : public GameObject {
public:
	Player(GameObject gameobject);
	~Player();
	void onCollision(GameObject* other);
	void Update();
	void Render();
private:
};

