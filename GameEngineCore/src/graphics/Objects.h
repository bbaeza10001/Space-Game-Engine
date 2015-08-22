#include <GL/glew.h>
//#include <GLU.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <string>
#include "Window.h"

namespace spacey{ namespace graphics{

	using namespace std;

	class object{
	public:
		object();
		object(string shape, float x, float y, float radius);

		void checkForMovement(Window* window);
		void Draw();

		float m_x;
		float m_y;
	private:
		void circle();
		void rectangle();
		void ship();
		
		void rotate(string dir);

		float m_radius;
		string m_shape;
		
	};

}}