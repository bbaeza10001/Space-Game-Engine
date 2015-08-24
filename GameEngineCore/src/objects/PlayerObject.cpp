#include "PlayerObject.h"

namespace spacey{
	namespace objects{
		PlayerObject::PlayerObject(){
			x_coord = 0;
			y_coord = 0;
			angle = 0;
		}

		void PlayerObject::Draw(){
			glPushMatrix();
			glRotatef(angle, 0, 0, 1);
			glBegin(GL_TRIANGLES);
			glVertex2d(-5.0f, -20.0f);
			glVertex2d(0, 0); //Nose of Ship
			glVertex2d(5.0f, -20.0f);
			glEnd();
			glPopMatrix();
		}
	}
}