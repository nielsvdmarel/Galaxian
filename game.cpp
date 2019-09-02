#include "game.h"

#include "surface.h"
#include <iostream>
#include <cstdio> //printf

namespace Tmpl8
{
	// -----------------------------------------------------------
	// Initialize the application
	// -----------------------------------------------------------
	void Game::Init()
	{
		playerMovement = 4;
		xpos = 375;
		ypos = 450;
	}
	
	// -----------------------------------------------------------
	// Close down application
	// -----------------------------------------------------------
	void Game::Shutdown()
	{

	}

	static Sprite rotatingGun(new Surface("assets/galaxian_assets/shooter.png"), 1);
	static int frame = 0;

	// -----------------------------------------------------------
	// Main application tick function
	// -----------------------------------------------------------
	void Game::Tick(float deltaTime)
	{
		// clear the graphics window
		screen->Clear(0);
		// print something in the graphics window
		//screen->Print("hello world", 2, 2, 0xffffff);
		// print something to the text window
		//printf("this goes to the console window.\n");
		// draw a sprite
		rotatingGun.SetFrame(frame);
		rotatingGun.Draw(screen, xpos, ypos);
	}
	void Game::KeyUp(int i) {

	}

	void Game::KeyDown(int i) {
		//std::cout << i << std::endl;
		switch (i) {
		case 4:
			std::cout << "A" << std::endl;
			xpos -= playerMovement;
			break;
		case 7:
			std::cout << "D" << std::endl;
			xpos += playerMovement;
			break;
		default:
			break;
		}
	}
};