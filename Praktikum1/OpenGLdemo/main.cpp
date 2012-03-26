
#include "Global.h"
#include "GraphicsIncludes.h"


// +++++ screen settings +++++
int width = 800;
int height = 480;

// +++++ content ++++++
//   draw a rectangle in the middle of viewport:
GLshort border = 50;
GLshort verticeArray[] = { border, border, width - border, border, width
		- border, height - border, border, height - border };

GLbyte allindices[] = { 0, 1, 2, 0, 2, 3 };

// +++++ global vars +++++
int counter = 0; // draw counter

// this is the graphics driver
AGraphicsDriver* graphics ;

// +++++ opengl drawing +++++
static void draw_gl() {
	TRACE("begin draw gl\n");
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/*
	 * put your drawing stuff here,
	 * using OpenGL ES
	 */
	graphics->renderText(5,5,2,"Hello World!");


	/*
	 * draw some text,
	 * using AGraphicsDriver-pointer
	 */
	// ...
	graphics->finishDraw();   // dependency to graphics driver



	TRACE("end draw gl\n");
	glFinish();
}

// +++++ main routine +++++
int main(int argc, char *argv[]) {

#ifdef EGL
	CGraphicsDriverEGL nativeGraphics(width,height);
#elif GFX
	CGraphicsDriverGFX nativeGraphics(width,height);
#else
	CGraphicsDriverGLUT nativeGraphics(width,height);
#endif

	graphics = &nativeGraphics;
	graphics->setDrawRoutine(draw_gl);
	graphics->init();
	graphics->run();

	return 0;
}


// EOF
