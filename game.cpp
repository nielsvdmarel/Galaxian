#include "game.h"1111111

namespace Tmpl8
{
	// -----------------------------------------------------------
	// Initialize the application
	// -----------------------------------------------------------
	void Game::Init() {
		collission = new Collision();
		allGameObjects == collission->AllGameObjects;
		CreateBackground();
		player = new Player(collission ,GameObject(new Surface("assets/galaxian_assets/shooter.png"), 1, screen));
		player->m_xPos = screen->GetWidth()/2 - player->width;
		player->m_yPos = screen->GetHeight()/5 * 4.5;
		collission->AddObjectToArray(player, 0);
		enemyManager = new EnemyManager(collission ,screen, allGameObjects);
		enemyManager->InstantiateArmy();
	}
	
	void Game::Shutdown() {
		
	}
	
	void Game::Tick(float deltaTime) {
		time = deltaTime;
		//std::cout << time << std::endl;
		// clear the graphics window
		screen->Clear(0);
		// print something in the graphics window
		//screen->Print("hello world", 2, 2, 0xffffff);
		// print something to the text window
		//printf("this goes to the console window.\n");
		Animate();
		Update();
		Draw();
	}

	void Game::Draw() {
		for (unsigned int x = 0; x < BackgroundX; x++) {
			for (unsigned int y = 0; y < BackgroundY; y++) {
				BackgroundsAll[x][y]->Render();
			}
		}
		player->Render();
		enemyManager->RenderAllEnemies();
	}

	void Game::Animate() {
		for (unsigned int x = 0; x < BackgroundX; x++) {
			for (unsigned int y = 0; y < BackgroundY; y++) {
				BackgroundsAll[x][y]->Animate();
			}
		}
	}

	void Game::CreateBackground() {
		float startPoint = -512;
		BackgroundX = 4;
		BackgroundY = 4;
		BackgroundOffsetX = 320;
		BackgroundOffsetY = 256;
		for (unsigned int x = 0; x < BackgroundX; x++) {
			for (unsigned int y = 0; y < BackgroundY; y++) {
				Background* background = new Background(GameObject(new Surface("assets/galaxian_assets/BackGroundSheet.png"), 15, screen));
				background->m_xPos = 0;
				background->m_yPos = startPoint;
				background->SetMaxFrame(14);
				background->m_xPos += BackgroundOffsetX * x;
				background->m_yPos += BackgroundOffsetY * y;
				BackgroundsAll[x][y] = background;	
			}
		}
	}

	void Game::Update() {
		for (unsigned int x = 0; x < BackgroundX; x++) {
			for (unsigned int y = 0; y < BackgroundY; y++) {
				BackgroundsAll[x][y]->Update();
		
			}
		}
		player->Update();
		enemyManager->Update();
		collission->Update();
	}

	void Game::KeyUp(int i) {

	}

	void Game::KeyDown(int i) {
		//std::cout << i << std::endl;
		switch (i) {
		case 4:
			std::cout << "A" << std::endl;
			player->MoveXPos(-player->playerMovement);
			break;
		case 7:
			std::cout << "D" << std::endl;
			player->MoveXPos(player->playerMovement);
			break;
		case 44:
			std::cout << "Sapce" << std::endl;
			player->ShootProjectile();
		default:
			break;
		}
	}
};