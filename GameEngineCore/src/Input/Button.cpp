#include "Button.h"

namespace spacey{ namespace input{

	button::button(){
		m_width = 0;
		m_height = 0;
		m_x = 0;
		m_y = 0;
		m_text = NULL;
		m_window = NULL;
	}

	button::button(Window* window, double x, double y, double width, double height, char *text){
		m_x = x;
		m_y = y;
		m_width = width;
		m_height = height;
		m_text = text;
		m_window = window;
	}

	void button::draw(){
		glPushMatrix();
		glTranslatef(m_x, m_y, 0);

		glBegin(GL_QUADS);
		glVertex2d(m_x, m_y);
		glVertex2d(m_x + m_width, m_y);
		glVertex2d(m_x + m_width, m_y + m_height);
		glVertex2d(m_x, m_y + m_height);
		glEnd();

		glPopMatrix();
		

	}

	bool button::clicked(){
		if (m_window->isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT)){
			double x, y;
			m_window->getMousePosition(x, y);

			if (x >= m_x && x <= m_x + m_width){
				if (y >= m_y && y <= m_y + m_height){
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
		else{
			return false;
		}
	}


} }