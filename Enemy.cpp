#include "Enemy.h"

Enemy::Enemy(GameObject gameobject): GameObject(gameobject) {
	currentEnemyState = Nothing;
	tag = "Enemy";
}

Enemy::~Enemy() {

}

void Enemy::onCollision(GameObject* other) {
	if (other->GetTag() == "Projectile") {
		std::cout << " Hit by bullet" << std::endl;
	}
}

void Enemy::AttackPlayer() {

}

void Enemy::DiveAttack(int playerxPos, int playerYpos) {
	//cos(angle) * r
	//sin(angle) * r
}


