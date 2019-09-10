#pragma once
#include "surface.h"
#include <iostream>
#include <string>

using namespace Tmpl8;
class GameObject {
public:
	GameObject(Surface* surface, int frame, Surface* rendercanvas);
	~GameObject();
	virtual void Update();
	virtual void Render();
	virtual void onCollision(GameObject* other);
	virtual void Animate();
	void SetMaxFrame(int maxFrameInt);
	std::string GetTag();
	std::string tag = "GameObject";
	float m_xPos;
	float m_yPos;
	Sprite* m_objectSprite;
	Surface* m_objectSurface;
	Surface* m_renderCanvas;
	int width;
	int height;
	int currentFrame = 0;
	int maxFrame;
	int midleposx, midleposy;
	bool enabled;
private:

};