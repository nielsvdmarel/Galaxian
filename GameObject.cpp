#include "GameObject.h"

	GameObject::GameObject(Surface* surface, int frame, Surface* Rendercanvas) {
		m_renderCanvas = Rendercanvas;
		m_objectSurface = surface;
		m_objectSprite = new Sprite(surface, frame);
		width = surface->GetWidth();
		height = surface->GetHeight();
		
	}
	GameObject::~GameObject()
	{
	}
	void GameObject::Update()
	{

	}
	void GameObject::Render() {
		m_objectSprite->Draw(m_renderCanvas, m_xPos, m_yPos);
		m_objectSprite->SetFrame(0);
	}
	void GameObject::onCollision(GameObject* other)
	{
	}
	std::string GameObject::GetTag() {
		return tag;
	}
