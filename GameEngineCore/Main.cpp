#include <string>
#include <GL\glew.h>
#include <GL\GLU.h>
#include <GL\glut.h>
#include "src\objects\PlayerObject.h"
#include "src\objects\CircleObject.h"
#include "src\graphics\Window.h"

using namespace spacey;
using namespace graphics;
using namespace objects;


int main(){

	//For accelerations
	float speed = 0;
	float xacceleration = 0;
	float yacceleration = 0;
	float const accelMax = 10;

	//Window creation
	static Window window("A Soon To Be Space Game", 800, 600);
	glClearColor(0.1f, 0.2f, 0.5f, 0.0f);

	// Construction
	PlayerObject player;
	CircleObject planet1(20, 100, 4), planet2(-30, -53, 1);

	// opengl setup
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-800 / 2.0, 800 / 2.0, -600 / 2.0, 600 / 2.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	while (!window.closed()){
		window.clear();
		
		glPushMatrix();
		// do movement here? a gltranslatef should move planets 1 and 2 but not the player
		planet1.Draw();
		planet2.Draw();
		glPopMatrix();
		
		// draw the player in the middle every time, i.e., I don't care about translating it at all
		glPushMatrix();
		// do rotation here
		player.Draw();
		glPopMatrix();

		// can't remember why I put this in main.. D'oh
		// TODO: put this back in a reasonable location
		if (window.isKeyPressed(GLFW_KEY_D)){ //If D key is pressed

			if (xacceleration < 0.0f){
				xacceleration = 0.0f;
			}
			if (abs(xacceleration) < accelMax)
				xacceleration += 0.0001;
		}
		else {
			if (xacceleration > 0.0f){
				xacceleration -= 0.0001;
			}
		}

		if (window.isKeyPressed(GLFW_KEY_A)){

			if (xacceleration > 0.0f){
				xacceleration = 0.0f;
			}
			if (abs(xacceleration) < accelMax)
				xacceleration -= 0.0001;
		}
		else {
			if (xacceleration < 0.0f){
				xacceleration += 0.0001;
			}
		}

		if (window.isKeyPressed(GLFW_KEY_W)){

			if (yacceleration < 0.0f){
				yacceleration = 0.0f;
			}
			if (abs(yacceleration) < accelMax)
				yacceleration += 0.0001;
		}
		else{
			if (yacceleration > 0.0f){
				yacceleration -= 0.0001;
			}
		}

		if (window.isKeyPressed(GLFW_KEY_S)){

			if (yacceleration > 0.0f){
				yacceleration = 0.0f;
			}
			if (abs(yacceleration) < accelMax)
				yacceleration -= 0.0001;
		}
		else{
			if (yacceleration < 0.0f){
				yacceleration += 0.0001;
			}
		}
	
		window.update();
	}

	return 0;
}

