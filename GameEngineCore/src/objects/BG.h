#pragma once

#include <iostream>
#include <vector>
#include "../graphics/Window.h"
#include "../graphics/LoadLevel.h"
#include "CircleObject.h"
#include "Merchant.h"
#include "../motion/Orbits.h"
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
			void loadEntity(string filename, string type);
			void update(Motion* motion);
			//Add functions to load in enemies and 
			//other background elements

		public: //Other Functions
			int testCollision();

		private: //Personal Functions
			void move(Motion* motion);
			void collided();

		private: //Objects
			vector<CircleObject> planets;
			vector<Merchant> merchants;

		private: //Tools
			Window* m_window;
			Orbit orb;
			bool hit = false;
			int colCode;
		};
	}
}