#include "Enemy.h"

Enemy::Enemy(GameObject gameobject): GameObject(gameobject) {
	currentEnemyState = Formation;
	tag = "Enemy";
	enabled = true;
	for (unsigned int i = 0; i < 5; i++) {
		enemyProjectiles[i] = nullptr;
	}
	lastUsedBullet = 0;
}

Enemy::~Enemy() {

}

void Enemy::onCollision(GameObject* other) {
	if (other->GetTag() == "Player") {
		
		//Hit the player
		//kill player once
		//kill this enemy
	}

	if (other->GetTag() == "PlayerProjectile") {
		if (other->enabled) {
			ShootAtPlayer(0, 0);
		}
	}
}

void Enemy::AttackPlayer() {

}

void Enemy::Update() {
	for (unsigned int i = 0; i < 5; i++) {
		if (enemyProjectiles[i]->enabled == false) {
			enemyProjectiles[i]->m_xPos = m_xPos + height / 2 - 1;
			enemyProjectiles[i]->m_yPos = m_yPos + width / 2 - 1;
		}
	}
}

void Enemy::Render() {
	m_objectSprite->Draw(m_renderCanvas, m_xPos, m_yPos);
	m_objectSprite->SetFrame(currentFrame);
	for (unsigned int i = 0; i < 5; i++) {
		if (enemyProjectiles[i] != nullptr) {
			if (enemyProjectiles[i]->enabled) {
				enemyProjectiles[i]->Render();
				enemyProjectiles[i]->Update();
			}
		}
	}
}

void Enemy::DiveAttack(int playerxPos, int playerYpos) {
	//cos(angle) * r
	//sin(angle) * r
}

void Enemy::CreateEnemyBullets(GameObject* allGameObjects[]) {
	for (unsigned i = 0; i < 5; i++) {
		enemyProjectiles[i] = new Projectile(GameObject(new Surface("assets/galaxian_assets/verticalline2.png"), 1, m_renderCanvas));
		//collision add 
		enemyProjectiles[i]->enabled = false;
		allGameObjects[48 + ((currentEnemyNum * 5) + i)] = enemyProjectiles[i];
	}
}

  void Enemy::ShootAtPlayer(int playerPosX, int PlayerPosY) {
	enemyProjectiles[lastUsedBullet]->enabled = true;
	enemyProjectiles[lastUsedBullet]->currentYvel = enemyProjectiles[lastUsedBullet]->bulletSpeed;
	lastUsedBullet++;
	if (lastUsedBullet > 4) {
		lastUsedBullet = 0;
	}
}


