#pragma once
#include <GL\glew.h>
#include <GL\GLU.h>
#include <cmath>
#include <math.h>
#include <string>
#include "BaseObject.h"

namespace spacey{ namespace objects{
		
	using namespace std;

	class CircleObject : public BaseObject{
		public:
			CircleObject();
			CircleObject(float x_in, float y_in, float radius_in, string filename);
			void Draw();
			float radius;
			float x_coord;
			float y_coord;
		};
} }