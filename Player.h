#pragma once
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

