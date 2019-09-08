#pragma once

#include "surface.h"
#include <iostream>
#include <vector>
#include <cstdio> //printf
#include "GameObject.h"
#include "Background.h"

namespace Tmpl8 {

class Surface;
class Game
{
public:
	void SetTarget( Surface* surface ) { screen = surface; }

	void Init();
	void Shutdown();
	void Tick( float deltaTime );
	void MouseUp( int button ) { /* implement if you want to detect mouse button presses */ }
	void MouseDown( int button ) { /* implement if you want to detect mouse button presses */ }
	void MouseMove( int x, int y ) { /* implement if you want to detect mouse movement */ }
	void KeyUp(int key);
	void KeyDown(int key);
	void Draw();
	void Animate();
	void CreateBackground();
	void BackGroundManager();
	GameObject* player;
	GameObject* BackgroundsAll[4][4];
	int BackgroundX, BackgroundY;
	void Update();

private:
	float time;
	Surface* screen;
	float xpos;
	float ypos;
	float playerMovement;
	int BackgroundOffsetX;
	int BackgroundOffsetY;
	float backgroundFrame;

};

}; // namespace Tmpl8