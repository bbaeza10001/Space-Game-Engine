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

namespace spacey {
	namespace motion{
		float xspeed = 0;
		float yspeed = 0;
		float angle = 0;
		float const accelMax = 10;

		void applySpeed(float xaccel, float yaccel){
		
			// use -= to move background opposite input
			xspeed -= xaccel;
			yspeed -= yaccel;
			glTranslatef(xspeed, yspeed, 0);
		
		}
		void applyRotation(float rangle){

			angle += rangle;
			glRotatef(angle, 0, 0, 1);
		}
	}
}

int main(){

	//For accelerations
	float xacceleration = 0;
	float yacceleration = 0;
	float input_angle = 0;

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
		
		// apply translation to world objects
		glPushMatrix();
		motion::applySpeed(xacceleration, yacceleration);
		planet1.Draw();
		planet2.Draw();
		glPopMatrix();
		
		// draw the player in the middle every time, i.e., I don't care about translating it at all
		glPushMatrix();
		// do rotation here
		motion::applyRotation(input_angle);
		player.Draw();
		glPopMatrix();

		// can't remember why I put this in main.. D'oh
		// TODO: put this back in a reasonable location & put it on a timer
		if (window.isKeyPressed(GLFW_KEY_D)){ //If D key is pressed
			if (abs(xacceleration) < motion::accelMax)
				xacceleration += 0.1;
		}
		else if (window.isKeyPressed(GLFW_KEY_A)){
			if (abs(xacceleration) < motion::accelMax)
				xacceleration -= 0.1;
		}
		else {
			if (xacceleration > 0){
				xacceleration -= 0.1;
			}
			else if (xacceleration < 0){
				xacceleration += 0.1;
			}
		}

		if (window.isKeyPressed(GLFW_KEY_W)){
			if (abs(yacceleration) < motion::accelMax)
				yacceleration += 0.1;
		}
		else if (window.isKeyPressed(GLFW_KEY_S)){
			if (abs(yacceleration) < motion::accelMax)
				yacceleration -= 0.1;
		}
		else{
			if (yacceleration > 0){
				yacceleration -= 0.1;
			}
			else if (yacceleration < 0){
				yacceleration += 0.1;
			}
		}


		if (window.isKeyPressed(GLFW_KEY_Q)){
			input_angle = 5;
		}
		else if (window.isKeyPressed(GLFW_KEY_E)){
			input_angle = -5;
		}
		else{
			input_angle = 0;
		}


		window.update();
	}

	return 0;
}

