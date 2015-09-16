#include "src\include\Includes.h"
#include "src\motion\Orbits.h"
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
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	Motion motion;
	Input input;
	Level load;
	Orbit orb1;
	Orbit orb2;

	// Construction
	PlayerObject player;
	vector<CircleObject> test = load.loadPlanets(test, "level.txt");
	vector<CircleObject> test2 = load.loadPlanets(test2, "Star System 2.txt");

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
		for (int i = 0; i < test.size(); i++){
			test[i].Draw();
		}
		/*for (int i = 0; i < test.size(); i++){
			test2[i].Draw();
		}*/
		glPopMatrix();
		
		// Rotation
		glPushMatrix();
		motion.applyRotation();
		player.Draw();
		glPopMatrix();

		//Orbits
		glPushMatrix();
		orb1.orbit(test);
		glPopMatrix();

		window.update();
		Sleep(0.5); //Controls how fast the game loop runs
	}

	return 0;
}

