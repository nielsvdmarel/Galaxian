#include "Player.h"

Player::Player(Collision* collision, GameObject gameobject): GameObject(gameobject) {
	playerMovement = 4;
	minXPos =  0;
	maxXpos = m_renderCanvas->GetWidth() - m_objectSprite->GetWidth();
	IsAbleToShoot = true;
	currentProjectile = new Projectile(GameObject(new Surface("assets/galaxian_assets/verticalline2.png"), 1, m_renderCanvas));
	collision->AddObjectToArray(currentProjectile, 1);
}

Player::~Player() {

}

void Player::onCollision(GameObject* other) {

}

void Player::Update() {
	currentProjectile->Render();
	if (!IsAbleToShoot) {
		currentProjectile->m_yPos-=currentProjectile->bulletSpeed;
		if (currentProjectile->m_yPos < 0) {
			IsAbleToShoot = true;
		}
	}
	if(IsAbleToShoot) {
		currentProjectile->m_xPos = m_xPos + m_objectSprite->GetWidth() / 2 - currentProjectile->width / 2;
		currentProjectile->m_yPos = m_yPos - currentProjectile->height;
	}
}

void Player::MoveXPos(int movement) {
	if (m_xPos < minXPos) {
		m_xPos += .7;
	}
	else if (m_xPos > maxXpos) {
		m_xPos -= .7;
	}
	else {
		m_xPos += movement;
	}
}

void Player::ShootProjectile() {
	if (IsAbleToShoot) {
		IsAbleToShoot = false;
	}
}

