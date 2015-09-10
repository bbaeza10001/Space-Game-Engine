#pragma once
#include <GL\glew.h>
#include <GL\GLU.h>
#include <cmath>

namespace spacey{ namespace objects{
		
	class CircleObject{
		public:
			CircleObject();
			CircleObject(float x_in, float y_in, float radius_in);
			void Draw();
			float radius;
			float x_coord;
			float y_coord;
		};
} }