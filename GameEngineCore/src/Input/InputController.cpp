#include "InputController.h"

namespace spacey{ namespace input{

	void Input::checkForInput(Window* window, Motion* motionObj){

		//Horizontal Movement
		if (window->isKeyPressed(GLFW_KEY_D)){
			motionObj->dirRight();

		}
		else if (window->isKeyPressed(GLFW_KEY_A)){
			motionObj->dirLeft();

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

		} 
		else if (window->isKeyPressed(GLFW_KEY_S)){
			motionObj->dirDown();

		}
		else{
			if (motionObj->yacceleration > 0){
				motionObj->yacceleration -= 0.001;
			}
			else if (motionObj->yacceleration < 0){
				motionObj->yacceleration += 0.001;
			}
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