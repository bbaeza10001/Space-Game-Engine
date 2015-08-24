#pragma once
#include <GL\glew.h>
#include <GL\GLU.h>
#include <cmath>

namespace spacey{
	namespace objects{
		struct BaseObject{
			virtual void Draw() = 0;
			float x_coord;
			float y_coord;
		};
	}
}