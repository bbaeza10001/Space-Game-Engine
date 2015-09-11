#include "PlayerObject.h"

namespace spacey{
	namespace objects{
		PlayerObject::PlayerObject(){
			x_coord = 0;
			y_coord = 0;
		}

		void PlayerObject::Draw(){
			glPushMatrix();
			glColor3f(1.0, 0.0, 0.0); //Sets the color of the ship each time it's drawn
			glBegin(GL_TRIANGLES);
			glVertex2d(-5.0f, -10.0f);
			glVertex2d(0, 10.0f); //Nose of Ship
			glVertex2d(5.0f, -10.0f);
			glEnd();
			glPopMatrix();
		}
	}
}