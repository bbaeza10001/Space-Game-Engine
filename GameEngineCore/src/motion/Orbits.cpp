#include "Orbits.h"

namespace spacey{ namespace motion{
	
	Orbit::Orbit(){
		counter = 0.0f;
		xDistance.clear();
		yDistance.clear();
	}

	void Orbit::orbit(vector<CircleObject> &starSystem){
		for (float i = 0.0f; i < starSystem.size(); i++){
			xDistance.push_back((abs(starSystem[0].x_coord - starSystem[i].x_coord)));
			yDistance.push_back((abs(starSystem[0].y_coord - starSystem[i].y_coord)));
		}

		for (float i = 1.0f; i < starSystem.size(); i++){
			counter += 0.1f;

			//Horizontal
			starSystem[i].x_coord = (xDistance[i] * (std::cos(counter * full_angle / 360.0f))) + starSystem[0].x_coord;

			//Vertical
			starSystem[i].y_coord = (yDistance[i] * (std::sin(counter * full_angle / 360.0f))) + starSystem[0].y_coord;

			glTranslatef(starSystem[i].x_coord, starSystem[i].y_coord, 0);
		}
	}

} }