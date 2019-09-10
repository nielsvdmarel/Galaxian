#include "GameObject.h"
#include <stdlib.h>

#pragma once
class Collision {
public:
	Collision();
	~Collision();
	void Update();
	GameObject* AllGameObjects[450];
	void AddObjectToArray(GameObject* gameObject, int place);
private:
	float minCheckDistance;
};

