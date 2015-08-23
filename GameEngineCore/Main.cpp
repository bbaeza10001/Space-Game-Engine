#include <iostream>
#include <vector>
#include <string>
#include "src\graphics\Objects.h"
#include "src\graphics\Window.h"
#include "src\graphics\Movement.h"

int main(){

	using namespace spacey;
	using namespace graphics;
	using namespace std;

	//Window creation
	Window window("A Soon To Be Space Game", 800, 600);
	glClearColor(0.1f, 0.2f, 0.5f, 0.0f);

	object player("SHIP", 390, 290, 0.0005f);
	object planet("CIRCLE", 100, 100, 0.1f);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1, 1, -1, 1);
	glMatrixMode(GL_MODELVIEW);

	while (!window.closed()){
		window.clear();
		
		player.checkForMovement(&window); 
		player.Draw();
		planet.Draw();
		

		window.update();
	}

	return 0;
}
