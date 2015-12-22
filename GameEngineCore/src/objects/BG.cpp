#include "BG.h"

namespace spacey{
	namespace background{
	
		BG::BG(){
			planets.clear();
		}

		void BG::loadP(string filename){
			planets = loadPlanets(planets, filename);
			cout << "Elements added to BG vector\n";
		}

		void BG::update(Motion* motion){
			if (!planets.empty()){

				glPushMatrix();
				motion->applySpeed();
				move(motion);
				for (unsigned int i = 0; i < planets.size(); i++){
					
					if (planets[i].x_coord < 800 && planets[i].x_coord > -800){
						if (planets[i].y_coord < 600 && planets[i].y_coord > -600){
							planets[i].Draw();
						}
					}
				}
				orb.orbit(planets);

				glPopMatrix();
			}
		}

		void BG::move(Motion* motion){
			if (!planets.empty()){
				for (unsigned int i = 0; i < planets.size(); i++){
					planets[i].x_coord += motion->xspeed;
					planets[i].y_coord += motion->yspeed;
				}
			}
		}

	}
}