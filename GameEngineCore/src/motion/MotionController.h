#pragma once
#include <GL\glew.h>
#include <GL\GLU.h>
#include <cmath>
#include <iostream>

namespace spacey{ namespace motion{

	class Motion{
	public:
		void dirRight();
		void dirLeft();
		void dirUp();
		void dirDown();

		void rotateLeft();
		void rotateRight();

		void applySpeed();
		void applyRotation();
		
		//For Translations
		float xacceleration = 0;
		float yacceleration = 0;
		float xspeed = 0;
		float yspeed = 0;
		
		//For Rotations
		float angle = 0;

		//For Zooming
		float zoom = 1;
	private:
		//Incriments
		const float speeInc = 0.00001;
		const float angleIncriment = 1.0f;
		const float zoomInc = 0.0001;

		//Max Values
		float const accelMax = 5;
		float const zoomMax = 0.7;
	};

} }