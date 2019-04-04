#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <windows.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <glut.h>
#elif defined(__APPLE__)
#include <OpenGL/gl.h>
#include <glut.h>
#else
#include <GL/GL.h>
#include <GL/GLU.h>
#include <GL/glut.h>
#endif

#include <iostream>
#include <fstream>

#include <chrono>

using namespace std::chrono;
using namespace std;

const int WIDTH = 1024;
const int HEIGHT = 768;


milliseconds startTime;


void draw() {
	// TODO: OpenGL Rendering implementation here.
}


/* Determine the current system clock time since the epoch in milliseconds.
*/
milliseconds getCurrentTime() {
	return duration_cast< milliseconds >(system_clock::now().time_since_epoch());
}

/* Glut idle function in charge of updating the screen based on elapsed time, updating all the bezier anchor springs.
*/
void update() {
	double elapsedTime = ((getCurrentTime() - startTime).count()) / 1000.0;

	if (elapsedTime < 0.01) {
		return;
	}

	// TODO: Update this function.
}

/* Glut resize function in charge of updating the viewport and display when the screen size changes.
*/
void resize(int w, int h) {
	// TODO: Update this function to handle resize logic.
}


void mouse_move(int x, int y) {
	// TODO: Any mouse move handling.
}


void mouse_input(int button, int state, int x, int y) {
	// TODO: Any mouse input handling.
}




/* Initialize OpenGL lighting and depth testing.
	TOOD: Reimplement this along with proper bezier normal calculations to get proper lighting visuals.
*/
void init(void)
{
	glEnable(GL_DEPTH_TEST);

	// TODO: Any additional initialization necessary.
	// Optionally, call init_lighting() if GL lighting and shading is desired.
	// init_lighting();
}


void init_lighting() {
	GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat mat_shininess[] = {50.0};
	GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Test");
	glutDisplayFunc(draw);
	glutReshapeFunc(resize);
	glutMouseFunc(mouse_input);
	glutMotionFunc(mouse_move);
	glutIdleFunc(update);

	init();

	startTime = getCurrentTime();

	glutMainLoop();

	return 0;
}
