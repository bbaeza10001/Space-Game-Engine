#include "InputController.h"

namespace spacey{ namespace input{

	void checkForInput(Window* window, Motion* motionObj){

		//Horizontal Movement
		if (window->isKeyPressed(GLFW_KEY_D) && !window->isKeyPressed(GLFW_KEY_W) 
			&& !window->isKeyPressed(GLFW_KEY_S)){
			motionObj->dirRight();

			//Turning the player to point where they are going
			if (motionObj->angle != 90){
				if (motionObj->angle >= 270 || motionObj->angle < 90){
					motionObj->rotateRight();
				}
				else if (motionObj->angle < 270 && motionObj->angle > 90){
					motionObj->rotateLeft();
				}
			}
		}
		else if (window->isKeyPressed(GLFW_KEY_A) && !window->isKeyPressed(GLFW_KEY_W)
			&& !window->isKeyPressed(GLFW_KEY_S)){
			motionObj->dirLeft();

			//Turning the player to point where they are going
			if (motionObj->angle != 270){
				if (motionObj->angle > 270 || motionObj->angle <= 90){
					motionObj->rotateLeft();
				}
				else if (motionObj->angle < 270 && motionObj->angle > 90){
					motionObj->rotateRight();
				}
			}

		}

		//Vertical Movement
		if (window->isKeyPressed(GLFW_KEY_W) && !window->isKeyPressed(GLFW_KEY_A)
			&& !window->isKeyPressed(GLFW_KEY_D)){
			motionObj->dirUp();

			//Turning the player to point where they are going
			if (motionObj->angle != 0){
				if (motionObj->angle >= 180){
					motionObj->rotateRight();
				}
				else if (motionObj->angle < 180){
					motionObj->rotateLeft();
				}
			}
		} 
		else if (window->isKeyPressed(GLFW_KEY_S) && !window->isKeyPressed(GLFW_KEY_A)
			&& !window->isKeyPressed(GLFW_KEY_D)){
			motionObj->dirDown();

			//Turning the player to point where they are going
			if (motionObj->angle != 180){
				if (motionObj->angle < 180){
					motionObj->rotateRight();
				}
				else if (motionObj->angle > 180){
					motionObj->rotateLeft();
				}
			}

		}

		//Checking if moving at an angle and turns/moves player accordingly
		if (window->isKeyPressed(GLFW_KEY_W) && window->isKeyPressed(GLFW_KEY_D)){
			motionObj->dirRight();
			motionObj->dirUp();

			if (motionObj->angle != 45){
				if (motionObj->angle >= 225 || motionObj->angle < 45){
					motionObj->rotateRight();
				}
				else if (motionObj->angle < 225 && motionObj->angle > 45){
					motionObj->rotateLeft();
				}
			}
		}
		else if (window->isKeyPressed(GLFW_KEY_W) && window->isKeyPressed(GLFW_KEY_A)){
			motionObj->dirLeft();
			motionObj->dirUp();

			if (motionObj->angle != 315){
				if (motionObj->angle >= 135 && motionObj->angle < 315){
					motionObj->rotateRight();
				}
				else if (motionObj->angle < 135 || motionObj->angle > 315){
					motionObj->rotateLeft();
				}
			}
		}
		else if (window->isKeyPressed(GLFW_KEY_S) && window->isKeyPressed(GLFW_KEY_D)){
			motionObj->dirRight();
			motionObj->dirDown();

			if (motionObj->angle != 135){
				if (motionObj->angle >= 315 || motionObj->angle < 135){
					motionObj->rotateRight();
				}
				else if (motionObj->angle > 135 && motionObj->angle < 315){
					motionObj->rotateLeft();
				}
			}
		}
		else if (window->isKeyPressed(GLFW_KEY_S) && window->isKeyPressed(GLFW_KEY_A)){
			motionObj->dirLeft();
			motionObj->dirDown();

			if (motionObj->angle != 225){
				if (motionObj->angle >= 45 && motionObj->angle < 225){
					motionObj->rotateRight();
				}
				else if (motionObj->angle > 225 || motionObj->angle < 45){
					motionObj->rotateLeft();
				}
			}
		}
		else {
			

		}

		//Things being done once nothing is being pressed
		if (!window->isKeyPressed(GLFW_KEY_D) && !window->isKeyPressed(GLFW_KEY_A) &&
			!window->isKeyPressed(GLFW_KEY_W) && !window->isKeyPressed(GLFW_KEY_S)){
			//Resetting zoom 
			if (motionObj->zoom < 1)
				motionObj->zoom += 0.0005;

			//Slowing player back to a stop
			if (motionObj->xacceleration > 0){
				motionObj->xacceleration -= 0.001;
			}
			else if (motionObj->xacceleration < 0){
				motionObj->xacceleration += 0.001;
			}

			if (motionObj->yacceleration > 0){
				motionObj->yacceleration -= 0.001;
			}
			else if (motionObj->yacceleration < 0){
				motionObj->yacceleration += 0.001;
			}
		}

		
	}

} }