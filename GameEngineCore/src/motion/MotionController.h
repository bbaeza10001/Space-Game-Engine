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
		
		//For Rotations
		float angle = 0;

		//For Zooming
		float zoom = 1;
	private:
		
		//For Translations
		float xspeed = 0;
		float yspeed = 0;

		//For Rotations
		const float angleIncriment = 1.0f;

		//Max Value
		float const accelMax = 10;
	};

} }