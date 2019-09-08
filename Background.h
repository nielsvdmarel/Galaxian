#pragma once
#include "GameObject.h"
using namespace Tmpl8;
class Background : public GameObject {
public:
	Background(GameObject gameobject);
	~Background();
	void onCollision(GameObject* other);
	void Update();
	
private:
};

