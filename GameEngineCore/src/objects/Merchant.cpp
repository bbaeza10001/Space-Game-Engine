#include "Merchant.h"

namespace spacey{
	namespace objects{

		Merchant::Merchant(){
			x_coord = 0;
			y_coord = 0;
		}

		Merchant::Merchant(int x, int y, string filename){
			x_coord = x;
			y_coord = y;

			if (filename != "")
				imageLoaded = loadImage(filename, m_image, u2, v2, u3, v3, width, height);
		}

		void Merchant::Draw(){
			if (imageLoaded){
				//Prepare the texture
				glEnable(GL_TEXTURE_2D);
				glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //GL_NEAREST = no smoothing
				glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);//GL_LINEAR = smoothing
				glTexImage2D(GL_TEXTURE_2D, 0, 4, u2, v2, 0, GL_RGBA, GL_UNSIGNED_BYTE, &m_image[0]);

				//Draw the texture
				glPushMatrix();

				glTranslatef(x_coord, y_coord, 0);
				glBegin(GL_QUADS);
				glTexCoord2d(0, v3);		 glVertex2d(x_coord, y_coord);
				glTexCoord2d(0, 0);		 glVertex2d(x_coord, y_coord + height);
				glTexCoord2d(u3, 0);	 glVertex2d(x_coord + width, y_coord + height);
				glTexCoord2d(u3, v3);		 glVertex2d(x_coord + width, y_coord);
				glEnd();

				glPopMatrix();

			}
			else{
				cout << "Image loading failed, drawing polygon instead\n";
				glPushMatrix();

				glBegin(GL_LINE_LOOP);
				glVertex2d(x_coord - 10, y_coord - 10);
				glVertex2d(x_coord, y_coord + 10);
				glVertex2d(x_coord - 10, y_coord - 10);
				glEnd();

				glPopMatrix();

			}
		}

	}
}