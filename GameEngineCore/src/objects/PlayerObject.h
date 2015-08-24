#pragma once
#include "BaseObject.h"
#include "../graphics/Window.h";

namespace spacey{
	namespace objects{
		using namespace graphics;
		class PlayerObject : BaseObject{

			public:
				PlayerObject();
				void Draw();
				void move(Window* window, float &xacceleration, float &yacceleration);
				void rotate(Window* window, float &angle);

				float const accelMax = 10;
				float angle;
		};
	}
}