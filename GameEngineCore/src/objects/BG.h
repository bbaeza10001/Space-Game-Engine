#pragma once

#include <iostream>
#include <vector>
#include "../graphics/Window.h"
#include "../graphics/LoadLevel.h"
#include "../motion/Orbits.h"
#include "CircleObject.h"
#include "../motion/MotionController.h"

namespace spacey{
	namespace background{

		using namespace std;
		using namespace objects;
		using namespace level;
		using namespace motion;
		using namespace graphics;

		class BG{
		public: //Set up functions
			BG();
			BG(Window* window);
			void update(Motion* motion);
			void loadP(string filename);
			//Add function to load in enemies and 
			//other background elements

		public: //Other Functions
			int testCollision();
		private:
			void move(Motion* motion);
			void collided();

		private:
			Window* m_window;
			vector<CircleObject> planets;
			Orbit orb;
			bool hit = false;
			int colCode;
		};
	}
}