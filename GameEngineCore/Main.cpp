#include "src\include\Includes.h"
#include "src\motion\Orbits.h"
#include <fstream>
#include <iostream>
#include <vector>
#include "src\Input\Button.h"
//#include <SOIL.h>

using namespace spacey;
using namespace graphics;
using namespace objects;
using namespace motion;
using namespace input;
using namespace std;
using namespace level;

/*
	CURRENT ISSUES:
	1) background image rendering for start screen failing to 
		run
	2) glutBitmapCharacter function in button.cpp is undefined??
		-Try updating freeglut library-
	
*/


int main(){
	int width = 800;
	int height = 600;

	//Start Screen
	static Window start("Interstellar Explorer - Start", width, height);
	glClearColor(0.5f, 0.0f, 1.0f, 0.0f);

	// opengl setup
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, width * 2, height * 2, 0); //Adjusts coordinate system to start from top left
	                                         //and be the correct width and height
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	button b_start(&start, 250, 400, 50, 40, "Start game");
	button b_exit(&start, 550, 400, 50, 40, "Exit");
	bool exit = false;

	while (!start.closed()){
		start.clear();

		b_start.draw();
		b_exit.draw();
		if (b_start.clicked()){
			start.~Window();
		}
		else if (b_exit.clicked()){
			start.~Window();
			exit = true;
		}

		start.update();
	}
	
	if (exit == false){

		//Game Window
		static Window window("Interstellar Explorer", width, height);
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

		Motion motion;
		Input input; //see if changing to a library type file is possible/better
		Level load;  //And this
		Orbit orb1;  //Also this
		Orbit orb2;

		// Construction
		PlayerObject player;
		vector<CircleObject> test = load.loadPlanets(test, "level.txt");

		// opengl setup
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(-width / 2.0, width / 2.0, -height / 2.0, height / 2.0); //Sets coordinate system to start in 
		                                                                    //the middle of the screen like a graph
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

	}
	return 0;
}

