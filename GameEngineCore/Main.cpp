#include <string>
#include <GL\glew.h>
#include <GL\GLU.h>
#include <GL\glut.h>
#include "src\objects\PlayerObject.h"
#include "src\objects\CircleObject.h"
#include "src\graphics\Window.h"
#include "src\Input\InputController.h"
#include "src\motion\MotionController.h"

using namespace spacey;
using namespace graphics;
using namespace objects;
using namespace motion;
using namespace input;


int main(){

	//Window creation
	static Window window("A Soon To Be Space Game", 800, 600);
	glClearColor(0.1f, 0.2f, 0.5f, 0.0f);

	// Construction
	PlayerObject player;
	CircleObject planet1(20, 100, 4), planet2(-30, -53, 20);
	Motion motion;
	Input input;

	// opengl setup
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-800 / 2.0, 800 / 2.0, -600 / 2.0, 600 / 2.0);
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
		glPopMatrix();
		
		// Rotation
		glPushMatrix();
		motion.applyRotation();
		player.Draw();
		glPopMatrix();

		//Object Movement functions
		
		//

		window.update();
	}

	return 0;
}

