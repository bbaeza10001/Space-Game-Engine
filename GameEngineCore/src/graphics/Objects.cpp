#include "Objects.h"

namespace spacey{ namespace graphics{
		
	object::object(){
		m_x = 0.0f;
		m_y = 0.0f;
		speed = 0.0f;
		xacceleration = 0.0f;
		yacceleration = 0.0f;
		m_radius = 0.0f;
		m_shape = "";
	}

	object::object(string shape, float x, float y, float radius){
		m_x = (x / 400.0f) - 1;
		m_y = (y / -300.0f) + 1;
		xacceleration = 0.0f;
		yacceleration = 0.0f;
		m_shape = shape;

		if (m_shape == "CIRCLE"){
			m_radius = radius;
			circle();
		}
		else if (m_shape == "RECTANGLE"){
			m_radius = radius;
			rectangle();
		}
		else if (m_shape == "SHIP"){
			speed = radius;
			ship();
		}
	}

	void object::checkForMovement(Window* window){
		if (window->isKeyPressed(GLFW_KEY_D)){ //If D key is pressed
			
			if (xacceleration < 0.0f){
				xacceleration = 0.0f;
			}

			glTranslatef(-speed - xacceleration, 0.0, 0.0);
			m_x += speed + xacceleration;
			if (abs(xacceleration) < accelMax)
				xacceleration += 0.00001;
		}
		else {
			if (xacceleration > 0.0f){                 
				xacceleration -= 0.00001;              
				glTranslatef(-speed - xacceleration, 0.0, 0.0);
				m_x += speed + xacceleration;
			}
		}

		if (window->isKeyPressed(GLFW_KEY_A)){

			if (xacceleration > 0.0f){
				xacceleration = 0.0f;
			}

			glTranslatef(speed - xacceleration, 0.0, 0.0);
			m_x -= speed - xacceleration;
			if (abs(xacceleration) < accelMax)
				xacceleration -= 0.00001;
		}
		else {
			if (xacceleration < 0.0f){
				xacceleration += 0.00001;
				glTranslatef(speed - xacceleration, 0.0, 0.0);
				m_x -= speed - xacceleration;
			}
		}

		if (window->isKeyPressed(GLFW_KEY_W)){
			
			if (yacceleration < 0.0f){
				yacceleration = 0.0f;
			}

			glTranslatef(0.0, -speed - yacceleration, 0.0);
			m_y += speed + yacceleration;
			if (abs(yacceleration) < accelMax)
				yacceleration += 0.00001;
		}
		else{
			if (yacceleration > 0.0f){
				yacceleration -= 0.00001;
				glTranslatef(0.0, -speed - yacceleration, 0.0);
				m_y += speed + yacceleration;
			}
		}

		if (window->isKeyPressed(GLFW_KEY_S)){
			
			if (yacceleration > 0.0f){
				yacceleration = 0.0f;
			}

			glTranslatef(0.0, speed - yacceleration, 0.0);
			m_y -= speed - yacceleration;
			if (abs(yacceleration) < accelMax)
				yacceleration -= 0.00001;
		}
		else{
			if (yacceleration < 0.0f){
				yacceleration += 0.00001;
				glTranslatef(0.0, speed - yacceleration, 0.0);
				m_y -= speed - yacceleration;
			}
		}

	}

	void object::Draw(){
		if (m_shape == "CIRCLE"){
			circle();
		}
		else if (m_shape == "RECTANGLE"){
			rectangle();
		}
		else if (m_shape == "SHIP"){
			ship();
		}
	}

	void object::circle(){
		const float full_angle = 2.0f*3.141592654f;
		float x = m_x;
		float y = m_y;
		float xN = 0.0f;
		float yN = 0.0f;

		glBegin(GL_POLYGON);
		for (float i = 0; i < 180; i++)
		{
			xN = x + m_radius * (std::cos(i * full_angle / 180.0f));
			yN = y + m_radius * (std::sin(i * full_angle / 180.0f));
			
			glVertex2d(xN, yN);
		}

		glEnd();
	}

	void object::rectangle(){
		glBegin(GL_QUADS);
		glVertex2d(m_x, m_y);
		glVertex2d(m_x + (m_radius / 400.0f), m_y);
		glVertex2d(m_x + (m_radius / 400.0f), m_y - (m_radius / -300.0f));
		glVertex2d(m_x, m_y - (m_radius / -300.0f));
		glEnd();
	}

	void object::ship(){
		

		glBegin(GL_TRIANGLES);
		glVertex2d(m_x, m_y + (20.0f / -300.0f));
		glVertex2d(m_x + (5.0f / 400.0f), m_y); //Nose of Ship
		glVertex2d(m_x + (10.0f / 400.0f), m_y + (20.0f / -300.0f));
		glEnd();
	} 

	void object::rotate(string dir){

		if (dir == "RIGHT"){
			
		}
		else if (dir == "LEFT"){
			
		}
		else{
			cout << "Invalid rotation direction.\n";
		}
	}
}}