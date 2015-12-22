#include "src\include\Includes.h"
#include "src\graphics\bg_Texture.h"
#include "src\objects\BG.h"
#include <thread>

using namespace spacey;
using namespace graphics;
using namespace objects;
using namespace motion;
using namespace input;
using namespace std;
using namespace level;
using namespace background;

/*
	CURRENT ISSUES:
	1) Screen starts in a random position every time 
		it runs

	TO DO:

	** Begin a sound engine

	** Add collision detection

*/

#if 1
int main(){
	int width = 800;
	int height = 600;

	//Start Screen
	static Window start("Interstellar Explorer - Start", width, height);

	//OpenGl Coordinate Grid Setup
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, height, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//Start Screen Object Declarations
	button b_start(&start, 250, 400, 50, 40, "Imgs/start.png");
	button b_exit(&start, 550, 400, 50, 40, "Imgs/exit.png");
	bg_Texture background("Imgs/bg.png");
	bool exit = true; //Exit code for closing the start window

	while (!start.closed()){
		start.clear();

		background.Draw();
		b_start.draw();
		b_exit.draw();

		//Checking if any of the buttons have been clicked
		if (b_start.clicked()){
			start.~Window();
			exit = false;
		}
		else if (b_exit.clicked()){
			start.~Window();
		}

		start.update();
	}
	
	if (exit == false){

		//Game Window
		static Window window("Interstellar Explorer", width, height);
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

		Motion motion;
		Orbit orb1;  //Also this
		Orbit orb2;

		// Construction
		//Set filename to empty quotes to leave objects as polygons
		PlayerObject player("Imgs/ship.png"); 
		BG test;
		test.loadP("level.txt");
		
		//OpenGl Coordinate Grid Setup
		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-width / 2, width / 2, -height / 2, height / 2, 0, 1);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		while (!window.closed()){
			window.clear();

			checkForInput(&window, &motion);

			test.update(&motion);

			glPushMatrix();
			motion.applyRotation();
			player.Draw();
			glPopMatrix();

			window.update();
			Sleep(0.5); //Controls how fast the game loop runs
		}

	}
	return 0;
}
#endif

//Sandbox main function
#if 0
int main(){

	int width = 800;
	int height = 600;

	//Game Window
	static Window window("Interstellar Explorer", width, height);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	Motion motion;
	Orbit orb1;  //Also this
	Orbit orb2;

	// Construction
	PlayerObject player("Imgs/ship.png"); //Set filename to empty quotes to leave player as polygon
	vector<CircleObject> test = loadPlanets(test, "level.txt");

	//OpenGl Coordinate Grid Setup
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-width / 2, width / 2, -height / 2, height / 2, 0, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	while (!window.closed()){
		window.clear();

		checkForInput(&window, &motion);

		// Translation
		glPushMatrix();
		motion.applySpeed();
		for (unsigned int i = 0; i < test.size(); i++){
			test[i].Draw();
		}
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
#endif