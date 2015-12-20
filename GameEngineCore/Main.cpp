#include "src\include\Includes.h"

using namespace spacey;
using namespace graphics;
using namespace objects;
using namespace motion;
using namespace input;
using namespace std;
using namespace level;

/*
	CURRENT ISSUES:
	1) Screen starts in a random position every time 
		it runs

	2) Buttons are not in correct position yet (Unimportant error)

	3) Sun is not currently a sun-ish color

	4) Zooming out continues indefinitely

	TO DO:

	** Add background photo to start screen

	** Begin a sound engine

	** Add param to text doc to set planet colors or images

	** Add collision detection

	** Re-enable and fix zoom compunding issue

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

	//Start screen button declarations
	button b_start(&start, 250, 400, 50, 40, "Imgs/start.png");
	button b_exit(&start, 550, 400, 50, 40, "Imgs/exit.png");
	bool exit = true; //Exit code for closing the start window

	while (!start.closed()){
		start.clear();

		b_start.draw();
		b_exit.draw();

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
		PlayerObject player;
		vector<CircleObject> test = loadPlanets(test, "level.txt");

		// opengl setup
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(-width / 2.0, width / 2.0, -height / 2.0, height / 2.0); //Sets coordinate system to start in 
		                                                                    //the middle of the screen like a standard graph
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

	}
	return 0;
}
#endif

//Sandbox main function
#if 0
int main(){

	

	return 0;
}
#endif