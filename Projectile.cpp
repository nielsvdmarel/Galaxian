#include "Projectile.h"

Projectile::Projectile(GameObject gameobject) : GameObject(gameobject) {
	tag = "Projectile";
	bulletSpeed = 6;
	enabled = true;
	m_xPos = rand() % 500 + 20;
	m_yPos = rand() % 500 + 20;
	PlayerProjectile = false;
	currentYvel = 0;
}

Projectile::~Projectile() {

}

void Projectile::Update() {
	m_yPos += currentYvel;
	if (m_yPos > m_renderCanvas->GetHeight()) {
		currentYvel = 0;
		enabled = false;
	}
}

void Projectile::onCollision(GameObject* other) {
	if (PlayerProjectile) {
		if (other->GetTag() == "Enemy") {
			m_yPos = -100;
			//Destory enemy
		}
	}
	if (!PlayerProjectile) {
		if (other->GetTag() == "Player") {
			std::cout << "Enemy Hit Player" << std::endl;
		}
	}
}

