#pragma once
#include <GL\glew.h>
#include <GL\GLU.h>
#include <cmath>
#include <string>
#include "../graphics/Window.h"
#include "BaseObject.h"
#include "../motion/MotionController.h"

namespace spacey{ namespace objects{

		using namespace graphics;
		using namespace std;
		using namespace motion;

		class PlayerObject : public BaseObject{
			public:
				PlayerObject();
				PlayerObject(string filename);
				void Draw(Motion* motion);
				int health = 100;
			private:
				//For Health Bar
				vector<unsigned char> m_hImage;
				size_t h_u2 = 1;
				size_t h_v2 = 1;
				double h_u3;
				double h_v3;
		};
} }