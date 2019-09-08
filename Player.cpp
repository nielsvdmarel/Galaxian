#include "Player.h"

Player::Player(GameObject gameobject): GameObject(gameobject) {
	playerMovement = 4;
	minXPos =  0;
	maxXpos = m_renderCanvas->GetWidth() - m_objectSprite->GetWidth();
	IsAbleToShoot = true;
	currentProjectile = new Projectile(GameObject(new Surface("assets/galaxian_assets/verticalline.png"), 1, m_renderCanvas));
}

Player::~Player() {

}

void Player::onCollision(GameObject* other) {

}

void Player::Update() {
	currentProjectile->m_xPos = 40;
	currentProjectile->m_yPos = 40;
	currentProjectile->Render();
	if (!IsAbleToShoot) {
		
	}
	if(IsAbleToShoot) {
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
		
	}
}

