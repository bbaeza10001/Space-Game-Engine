#include "PlayerObject.h"

namespace spacey{
	namespace objects{
		PlayerObject::PlayerObject(){
			x_coord = 0;
			y_coord = 0;
			angle = 0;
		}

		void PlayerObject::Draw(){
			glPushMatrix();
			glRotatef(angle, 0, 0, 1);
			glBegin(GL_TRIANGLES);
			glVertex2d(-5.0f, -10.0f);
			glVertex2d(0, 10.0f); //Nose of Ship
			glVertex2d(5.0f, -10.0f);
			glEnd();
			glPopMatrix();
		}

		void PlayerObject::move(Window* window, float &xacceleration, float &yacceleration){
			//Add Timer
			if (window->isKeyPressed(GLFW_KEY_D)){ //If D key is pressed
				if (abs(xacceleration) < accelMax)
					xacceleration += 0.001;
			}
			else if (window->isKeyPressed(GLFW_KEY_A)){
				if (abs(xacceleration) < accelMax)
					xacceleration -= 0.001;
			}
			else {
				if (xacceleration > 0){
					xacceleration -= 0.001;
				}
				else if (xacceleration < 0){
					xacceleration += 0.001;
				}
			}

			if (window->isKeyPressed(GLFW_KEY_W)){
				if (abs(yacceleration) < accelMax)
					yacceleration += 0.001;
			}
			else if (window->isKeyPressed(GLFW_KEY_S)){
				if (abs(yacceleration) <accelMax)
					yacceleration -= 0.001;
			}
			else{
				if (yacceleration > 0){
					yacceleration -= 0.001;
				}
				else if (yacceleration < 0){
					yacceleration += 0.001;
				}
			}
		}

		void PlayerObject::rotate(Window* window, float &input_angle){
			if (window->isKeyPressed(GLFW_KEY_Q)){
				input_angle = 1;
			}
			else if (window->isKeyPressed(GLFW_KEY_E)){
				input_angle = -1;
			}
			else{
				input_angle = 0;
			}
		}
	}
}