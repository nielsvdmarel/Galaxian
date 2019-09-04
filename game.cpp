#include "game.h"

namespace Tmpl8
{
	// -----------------------------------------------------------
	// Initialize the application
	// -----------------------------------------------------------
	void Game::Init() {
		player = new GameObject(new Surface("assets/galaxian_assets/shooter.png"), 1, screen);
		playerMovement = 4;
		player->xPos = screen->GetWidth()/2;
		player->yPos = screen->GetHeight()/5 * 4.5;
	}
	
	// -----------------------------------------------------------
	// Close down application
	// -----------------------------------------------------------
	void Game::Shutdown()
	{
		
	}

	
	static Sprite Background(new Surface("assets/galaxian_assets/BackGroundSheet.png"), 15);
	static Sprite Player(new Surface("assets/galaxian_assets/shooter.png"), 1);
	Sprite life1(new Surface("assets/galaxian_assets/shooter.png"), 1);
	static int frame = 0;
	

	// -----------------------------------------------------------
	// Main application tick function
	// -----------------------------------------------------------
	void Game::Tick(float deltaTime) {
		time = deltaTime;
		// clear the graphics window
		screen->Clear(0);
		// print something in the graphics window
		screen->Print("hello world", 2, 2, 0xffffff);
		// print something to the text window
		//printf("this goes to the console window.\n");
		Draw();
		Animate();
	}

	void Game::Draw() {
		player->Render();
		Background.Draw(screen, 0,0); //TODO replace with normal width and height value
		Player.Draw(screen, (xpos - Player.GetWidth() / 2), (ypos - Player.GetHeight() / 2)); //TODO replace with normal width and height value
		for (unsigned int i = 0; i < allSprites.size(); i++) {
			//draw all objects
		}
	}

	void Game::Animate() {
		Player.SetFrame(0);
		Background.SetFrame(frame++);
		if (frame > 14) {
			frame = 0;
		}
		
	}

	void Game::KeyUp(int i) {

	}

	void Game::KeyDown(int i) {
		//std::cout << i << std::endl;
		switch (i) {
		case 4:
			std::cout << "A" << std::endl;
			//xpos -= playerMovement;
			player->xPos -= playerMovement;
			break;
		case 7:
			std::cout << "D" << std::endl;
			//xpos += playerMovement;
			player->xPos += playerMovement;
			break;
		default:
			break;
		}
	}
};