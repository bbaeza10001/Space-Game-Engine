#include "InputController.h"

namespace spacey{ namespace input{

	void Input::checkForInput(Window* window, Motion* motionObj){

		//Horizontal Movement
		if (window->isKeyPressed(GLFW_KEY_D)){
			motionObj->dirRight();

			if (motionObj->zoom > 0)
				motionObj->zoom -= 0.0001;
		}
		else if (window->isKeyPressed(GLFW_KEY_A)){
			motionObj->dirLeft();

			if (motionObj->zoom > 0)
				motionObj->zoom -= 0.0001;
		}
		else {
			if (motionObj->xacceleration > 0){
				motionObj->xacceleration -= 0.001;
			}
			else if (motionObj->xacceleration < 0){
				motionObj->xacceleration += 0.001;
			}

		}

		//Vertical Movement
		if (window->isKeyPressed(GLFW_KEY_W)){
			motionObj->dirUp();

			if (motionObj->zoom > 0)
				motionObj->zoom -= 0.0001;
		} 
		else if (window->isKeyPressed(GLFW_KEY_S)){
			motionObj->dirDown();

			if (motionObj->zoom > 0)
				motionObj->zoom -= 0.0001;
		}
		else{
			if (motionObj->yacceleration > 0){
				motionObj->yacceleration -= 0.001;
			}
			else if (motionObj->yacceleration < 0){
				motionObj->yacceleration += 0.001;
			}

		}

		if (!window->isKeyPressed(GLFW_KEY_D) && !window->isKeyPressed(GLFW_KEY_A) &&
			!window->isKeyPressed(GLFW_KEY_W) && !window->isKeyPressed(GLFW_KEY_S)){
			if (motionObj->zoom < 1)
				motionObj->zoom += 0.0005;
		}

		if (window->isKeyPressed(GLFW_KEY_Q)){
			motionObj->rotateLeft();
		}
		else if (window->isKeyPressed(GLFW_KEY_E)){
			motionObj->rotateRight();
		}
		else{
			if (motionObj->angleIncriment > 0){
				motionObj->angleIncriment -= 0.001f;
			}
			else if (motionObj->angleIncriment < 0){
				motionObj->angleIncriment += 0.001f;
			}
		}
	}

} }