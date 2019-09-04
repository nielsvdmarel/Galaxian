#include "GameObject.h"

	GameObject::GameObject(Surface* surface, int frame, Surface* Rendercanvas) {
		renderCanvas = Rendercanvas;
		std::cout << surface << std::endl;
		objectSurface = surface;
		objectSprite = new Sprite(surface, frame);
		
	}
	GameObject::~GameObject()
	{
	}
	void GameObject::Update()
	{

	}
	void GameObject::Render() {
		objectSprite->Draw(renderCanvas, xPos, yPos);
		objectSprite->SetFrame(0);
	}
	std::string GameObject::GetTag()
	{
		return std::string();
	}
