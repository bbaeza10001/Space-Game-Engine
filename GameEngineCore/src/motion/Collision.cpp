#include "Collision.h"

namespace spacey{
	namespace motion{

		bool checkCollided(vector<CircleObject> planets){
			for (int i = 0; i < planets.size(); i++){
				if (planets[i].x_coord >= -15 && planets[i].x_coord <= 15){
					if (planets[i].y_coord >= -15 && planets[i].y_coord <= 15){
						//True
						return true;
					}
					else{
						return false;
					}
				}
				else{
					return false;
				}
			}
		}

	}
}