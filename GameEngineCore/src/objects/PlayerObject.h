#pragma once
#include <GL\glew.h>
#include <GL\GLU.h>
#include <cmath>
#include "../graphics/Window.h"
#include "BaseObject.h"
#include <string>

namespace spacey{ namespace objects{

		using namespace graphics;
		using namespace std;

		class PlayerObject : public BaseObject{
			public:
				PlayerObject();
				PlayerObject(string filename);
				void Draw();
		};
} }