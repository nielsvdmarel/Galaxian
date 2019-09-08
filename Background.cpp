#include "Background.h"

Background::Background(GameObject gameobject): GameObject(gameobject) {

}

Background::~Background() {

}

void Background::onCollision(GameObject* other) {

}

void Background::Update() {
	m_yPos++;
	if (m_yPos > 512) {
		m_yPos = -512;
	}
}

