#include "EnemyManager.h"

EnemyManager::EnemyManager(Collision* collision, Surface* renderCanvas, GameObject* allGameObjects[]) {
	Refcollision = collision;
	m_renderCanvas = renderCanvas;
	yFormationPos = 10;
	xFormationPos = 10;
	xstartPos = 10;
	ystartPos = 10;
}

EnemyManager::~EnemyManager() {

}

void EnemyManager::Update() {
	for (unsigned int i = 0; i < 41; i++) {
		AllEnemys[i]->Update();
	}
}

void EnemyManager::RenderAllEnemies() {
	for (unsigned int i = 0; i < 41; i++) {
		AllEnemys[i]->Render();	
	}
}

void EnemyManager::InstantiateArmy() {
	for (unsigned int i = 0; i < 41; i++) {
		AllEnemys[i] = new Enemy(GameObject(new Surface("assets/galaxian_assets/galaxianA-2.png"), 1, m_renderCanvas));
		AllEnemys[i]->m_xPos = rand() % 400 + 20;
		AllEnemys[i]->m_yPos = rand() % 300 + 20;
		Refcollision->AddObjectToArray(AllEnemys[i], i + 2);
		
	}
}
