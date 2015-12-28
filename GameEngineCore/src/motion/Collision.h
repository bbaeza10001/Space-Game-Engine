#pragma once
#include "../objects/CircleObject.h"
#include <vector>

namespace spacey{
	namespace motion{
		using namespace std;
		using namespace objects;

		bool checkCollided(vector<CircleObject> planets);

	}
}