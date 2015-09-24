#include "../graphics/Window.h"
#include <GL\freeglut.h>

namespace spacey{ namespace input{

	using namespace graphics;
	using namespace std;

	class button{
	public:
		button();
		button(Window* window, double x, double y, double width, double height, char *text);
		void draw();
		bool clicked();

	private:
		//Member Variables
		Window* m_window;
		char *m_text;
		double m_x;
		double m_y;
		double m_width;
		double m_height;
	};

} }