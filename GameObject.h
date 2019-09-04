#pragma once
#include "surface.h"
#include <iostream>
#include <vector>
#include <string>
using namespace Tmpl8;
	class GameObject {
	public:
	GameObject(Surface* surface, int frame, Surface* rendercanvas);
	~GameObject();
	void Update();
	void Render();
	void onCollision(GameObject* other);
	std::string GetTag();
	std::string tag = "GameObject";
	int m_xPos;
	int m_yPos;
	Sprite* m_objectSprite;
	Surface* m_objectSurface;
	Surface* m_renderCanvas;
	private:
	
}