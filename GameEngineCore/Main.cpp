#include "src\include\Includes.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace spacey;
using namespace graphics;
using namespace objects;
using namespace motion;
using namespace input;
using namespace std;
using namespace level;


int main(){
	int width = 800;
	int height = 600;

	//Window creation
	static Window window("Interstellar Explorer", width, height);
	glClearColor(0.1f, 0.2f, 0.5f, 0.0f);

	// Construction
	PlayerObject player;
	CircleObject planet1(20, 100, 4), planet2(-30, -53, 20);
	Motion motion;
	Input input;
	Level load;

	vector<CircleObject> test = load.loadPlanets(test, "level.txt");

	// opengl setup
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-width / 2.0, width / 2.0, -height / 2.0, height / 2.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	while (!window.closed()){
		window.clear();
		
		input.checkForInput(&window, &motion);

		// Translation
		glPushMatrix();
		motion.applySpeed();
		planet1.Draw();
		planet2.Draw();
		for (int i = 0; i < test.size(); i++){
			test[i].Draw();
		}
		glPopMatrix();
		
		// Rotation
		glPushMatrix();
		motion.applyRotation();
		player.Draw();
		glPopMatrix();

		window.update();
		Sleep(0.825); //Controls how fast the game loop runs
	}

	return 0;
}

