#include "MotionController.h"

namespace spacey{ namespace motion{

	void Motion::dirRight(){
		if (xacceleration < accelMax)
			xacceleration += 0.001;
	}

	void Motion::dirLeft(){
		if (xacceleration > -accelMax)
			xacceleration -= 0.001;
	}

	void Motion::dirUp(){
		if (yacceleration < accelMax)
			yacceleration += 0.001;
	}

	void Motion::dirDown(){
		if (yacceleration > -accelMax)
			yacceleration -= 0.001;
	}

	void Motion::rotateLeft(){
		angleIncriment += 0.001f;
	}

	void Motion::rotateRight(){
		angleIncriment += -0.001f;
	}

	void Motion::applySpeed(){
		// use -= to move background opposite input
		xspeed -= xacceleration;
		yspeed -= yacceleration;
		glTranslatef(xspeed, yspeed, 0);
	}

	void Motion::applyRotation(){
		angle += angleIncriment;
		glRotatef(angle, 0, 0, 1);
	}
} }