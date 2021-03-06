#include "MotionController.h"

namespace spacey{ namespace motion{

	void Motion::dirRight(){
		if (xacceleration < accelMax)
			xacceleration += speeInc;
		if (zoom > zoomMax){
			zoom -= zoomInc;
		}
		else{
			zoom = zoomMax;
		}
	}

	void Motion::dirLeft(){
		if (xacceleration > -accelMax)
			xacceleration -= speeInc;
		if (zoom > zoomMax){
			zoom -= zoomInc;
		}
		else{
			zoom = zoomMax;
		}
	}

	void Motion::dirUp(){
		if (yacceleration < accelMax)
			yacceleration += speeInc;
		if (zoom > zoomMax){
			zoom -= zoomInc;
		}
		else{
			zoom = zoomMax;
		}
	}

	void Motion::dirDown(){
		if (yacceleration > -accelMax)
			yacceleration -= speeInc;
		if (zoom > zoomMax){
			zoom -= zoomInc;
		}
		else{
			zoom = zoomMax;
		}
	}

	void Motion::rotateLeft(){
		angle -= angleIncriment;

		//Angle resetting to stay within 360 degrees
		while (angle >= 360){
			angle -= 360;
		}
		while (angle < 0){
			angle += 360;
		}
	}

	void Motion::rotateRight(){
		angle += angleIncriment;

		//Angle resetting to stay within 360 degrees
		while (angle >= 360){
			angle -= 360;
		}
		while (angle < 0){
			angle += 360;
		}
	}

	void Motion::applySpeed(){
		// use -= to move background opposite to input
		xspeed -= xacceleration;
		yspeed -= yacceleration;

		if (zoom > 1){
			zoom = 1;
		}

		if (zoom < zoomMax)
			zoom = zoomMax;

		glScalef(zoom, zoom, 1);
	}

	void Motion::applyRotation(){
		glRotatef(-angle, 0, 0, 1);
	}
} }