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
	void GameObject::Update(){

	}

	void GameObject::Render() {
		m_objectSprite->Draw(m_renderCanvas, m_xPos, m_yPos);
		m_objectSprite->SetFrame(currentFrame);
	}

	void GameObject::onCollision(GameObject* other) {
		
	}

	void GameObject::Animate() {
		currentFrame++;
		if (currentFrame > maxFrame) {
			currentFrame = 0;
		}
	}
	
	void GameObject::SetMaxFrame(int maxFrameInt) {
		maxFrame = maxFrameInt;
	}
	std::string GameObject::GetTag() {
		return tag;
	}
