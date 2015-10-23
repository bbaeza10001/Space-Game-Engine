#pragma once
#include <GL\glew.h>
#include <GL\GLU.h>
#include <cmath>
#include "../graphics/Window.h";

namespace spacey{ namespace objects{

		using namespace graphics;

		class PlayerObject{
			public:
				PlayerObject();
				void Draw();
				float x_coord;
				float y_coord;

		};
} }