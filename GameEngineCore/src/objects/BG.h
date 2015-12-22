#include <iostream>
#include <vector>
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

		class BG{
		public:
			BG();
			void update(Motion* motion);
			void loadP(string filename);
			//Add function to load in enemies and 
			//other background elements
		private:
			void move(Motion* motion);

		private:
			vector<CircleObject> planets;
			Orbit orb;
		};
	}
}