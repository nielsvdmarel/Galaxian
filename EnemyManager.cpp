#include "EnemyManager.h"

EnemyManager::EnemyManager(Collision* collision, Surface* renderCanvas, GameObject* allGameObjects[]) {
	Refcollision = collision;
	m_renderCanvas = renderCanvas;
	yFormationPos = 10;
	xFormationPos = 10;
	xstartPos = 10;
	ystartPos = 10;
	GroupMovementSpeed = 1.5f;
	currentGroupMovement = GroupMovementSpeed;
	for (unsigned int i = 0; i < 50; i++) {
		AllEnemys[i] = nullptr;
	}
}

EnemyManager::~EnemyManager() {

}

void EnemyManager::Update() {
	for (unsigned int i = 0; i < 50; i++) {
		if (AllEnemys[i] != nullptr) {
			if (AllEnemys[i]->m_xPos > (m_renderCanvas->GetWidth() - AllEnemys[i]->m_objectSprite->GetWidth())) {
				currentGroupMovement = -currentGroupMovement;
			}
			if (AllEnemys[i]->m_xPos < 0) {
				currentGroupMovement = GroupMovementSpeed;
			}
			AllEnemys[i]->Update();
		}
	}
}

void EnemyManager::RenderAllEnemies() {
	for (unsigned int i = 0; i < 50; i++) {
		if (AllEnemys[i] != nullptr) {
			AllEnemys[i]->Render();
			AllEnemys[i]->m_xPos += currentGroupMovement;
		}
	}
}

void EnemyManager::InstantiateArmy() {
	int enemyCount = 0;
	for (unsigned int y = 0; y < 6; y++) {
		for (unsigned int x = 0; x < 10; x++) {
			switch (enemyMap[y][x]) {
			case 0:
				AllEnemys[enemyCount] = nullptr;
				std::cout << "No ship" << std::endl;
				break;
			case 1:
				AllEnemys[enemyCount] = new Enemy(GameObject(new Surface("assets/galaxian_assets/Commander.png"), 1, m_renderCanvas));
				AllEnemys[enemyCount]->m_xPos = 75 + (45 * x);
				AllEnemys[enemyCount]->m_yPos = 30 + (33 * y);
				Refcollision->AddObjectToArray(AllEnemys[enemyCount], enemyCount + 2);
				AllEnemys[enemyCount]->currentEnemyNum = enemyCount;
				AllEnemys[enemyCount]->CreateEnemyBullets(Refcollision->AllGameObjects);
				std::cout << "main ship " << enemyCount << std::endl;
				enemyCount++;
				break;
			case 2:
				AllEnemys[enemyCount] = new Enemy(GameObject(new Surface("assets/galaxian_assets/galaxianB-1.png"), 1, m_renderCanvas));
				AllEnemys[enemyCount]->m_xPos = 75 + (45 * x);
				AllEnemys[enemyCount]->m_yPos = 30 + (33 * y);
				Refcollision->AddObjectToArray(AllEnemys[enemyCount], enemyCount + 2);
				AllEnemys[enemyCount]->currentEnemyNum = enemyCount;
				AllEnemys[enemyCount]->CreateEnemyBullets(Refcollision->AllGameObjects);
				std::cout << "Secondary ship " << enemyCount << std::endl;
				enemyCount++;
				break;
			case 3:
				AllEnemys[enemyCount] = new Enemy(GameObject(new Surface("assets/galaxian_assets/galaxianC-1.png"), 1, m_renderCanvas));
				AllEnemys[enemyCount]->m_xPos = 75 + (45 * x);
				AllEnemys[enemyCount]->m_yPos = 30 + (33 * y);
				Refcollision->AddObjectToArray(AllEnemys[enemyCount], enemyCount + 2);
				AllEnemys[enemyCount]->currentEnemyNum = enemyCount;
				AllEnemys[enemyCount]->CreateEnemyBullets(Refcollision->AllGameObjects);
				std::cout << "Third ship " << enemyCount << std::endl;
				enemyCount++;
				break;
			case 4:
				AllEnemys[enemyCount] = new Enemy(GameObject(new Surface("assets/galaxian_assets/galaxianA-2.png"), 1, m_renderCanvas));
				AllEnemys[enemyCount]->m_xPos = 75 + (45 * x);
				AllEnemys[enemyCount]->m_yPos = 30 + (33 * y);
				Refcollision->AddObjectToArray(AllEnemys[enemyCount], enemyCount + 2);
				AllEnemys[enemyCount]->currentEnemyNum = enemyCount;
				AllEnemys[enemyCount]->CreateEnemyBullets(Refcollision->AllGameObjects);
				std::cout << "4th ship " << enemyCount << std::endl;
				enemyCount++;
				break;
			default:
			break;
			}		
		}
	}
}
