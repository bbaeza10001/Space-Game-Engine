#include "src\include\Includes.h"
#include "src\graphics\Texture.h"

using namespace spacey;
using namespace graphics;
using namespace objects;
using namespace motion;
using namespace input;
using namespace std;
using namespace level;

/*
	CURRENT ISSUES:
	1) Screen starts in a random position every time 
		it runs

	2) Buttons are not in correct position yet (Unimportant error)

	3) Sun is not currently a sun-ish color

	4) Zooming out continues indefinitely

	TO DO:

	** Figure out if turning some functions into librarys rather than object classes
		is more efficient

	** Fix the zoom out feature compounding 

	** Add background photo to start screen

	** Begin a sound engine

	** Change ship rotation to directional movement

	** Add param to text doc to set planet colors

	** Add collision detection

	** Fix the image loader

	** Give the start screen its own function under the main function
*/

#if 1
int main(){
	int width = 800;
	int height = 600;

	//Start Screen
	static Window start("Interstellar Explorer - Start", width, height);
	

	// opengl setup
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, width * 2, height * 2, 0); //Adjusts coordinate system to start from top left
	                                         //and be the correct width and height
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	button b_start(&start, 250, 400, 50, 40, "Brandenbrug Tor.jpg");
	button b_exit(&start, 550, 400, 50, 40, "sample.bmp");
	bool exit = false;

	Texture test("Brandenbrug Tor.jpg");

	while (!start.closed()){
		start.clear();

		b_start.draw();
		b_exit.draw();
		if (b_start.clicked()){
			start.~Window();
		}
		else if (b_exit.clicked()){
			start.~Window();
			exit = true;
		}
		start.update();
	}
	
	if (exit == false){

		//Game Window
		static Window window("Interstellar Explorer", width, height);
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

		Motion motion;
		Input input; //see if changing to a library type file is possible/better
		Level load;  //And this
		Orbit orb1;  //Also this
		Orbit orb2;

		// Construction
		PlayerObject player;
		vector<CircleObject> test = load.loadPlanets(test, "level.txt");

		// opengl setup
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(-width / 2.0, width / 2.0, -height / 2.0, height / 2.0); //Sets coordinate system to start in 
		                                                                    //the middle of the screen like a standard graph
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		while (!window.closed()){
			window.clear();

			input.checkForInput(&window, &motion);

			// Translation
			glPushMatrix();
			motion.applySpeed();
			for (unsigned int i = 0; i < test.size(); i++){
				test[i].Draw();
			}
			glPopMatrix();

			// Rotation
			glPushMatrix();
			motion.applyRotation();
			player.Draw();
			glPopMatrix();

			//Orbits
			glPushMatrix();
			orb1.orbit(test);
			glPopMatrix();

			window.update();
			Sleep(0.5); //Controls how fast the game loop runs
		}

	}
	return 0;
}
#endif

#if 0
int main(){

	const char *filename = "sample.bmp";

	//image format
	FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
	//pointer to the image, once loaded
	FIBITMAP *dib(0);
	//pointer to the image data
	BYTE* bits(0);
	//image width and height
	unsigned int width(0), height(0);
	//OpenGL's image ID to map to
	GLuint gl_texID;

	//check the file signature and deduce its format
	fif = FreeImage_GetFileType(filename, 0);
	//if still unknown, try to guess the file format from the file extension
	if (fif == FIF_UNKNOWN)
		fif = FreeImage_GetFIFFromFilename(filename);
	//if still unkown, return failure
	if (fif == FIF_UNKNOWN)
		return false;

	//check that the plugin has reading capabilities and load the file
	if (FreeImage_FIFSupportsReading(fif))
		dib = FreeImage_Load(fif, filename);
	//if the image failed to load, return failure
	if (!dib)
		return false;

	//retrieve the image data
	bits = FreeImage_GetBits(dib);
	unsigned int bitsPerPixel = FreeImage_GetBPP(dib);
	unsigned int pitch = FreeImage_GetPitch(dib);
	//get the image width and height
	width = FreeImage_GetWidth(dib);
	height = FreeImage_GetHeight(dib);
	//if this somehow one of these failed (they shouldn't), return failure
	if ((bits == 0) || (width == 0) || (height == 0))
		return false;

	for (int y = height; y > 0; y--){
		BYTE *pixel = (BYTE*)bits;
		for (int x = 0; x < width; x++){
			cout << +pixel[FI_RGBA_RED] << " " << +pixel[FI_RGBA_GREEN] << " " << +pixel[FI_RGBA_BLUE] << endl;
			pixel += 3;
		}

		bits += pitch;
	}


	return 0;
}
#endif