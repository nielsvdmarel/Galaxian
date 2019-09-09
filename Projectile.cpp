#include "Projectile.h"

Projectile::Projectile(GameObject gameobject) : GameObject(gameobject) {
	tag = "Projectile";
	bulletSpeed = 4;
}

Projectile::~Projectile() {

}

void Projectile::onCollision(GameObject* other) {
	if (other->GetTag() == "Enemy") {
		m_yPos = -100;

	}
}

