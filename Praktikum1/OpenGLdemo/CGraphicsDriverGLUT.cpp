#include "GraphicsIncludes.h"
#include "CGraphicsDriverGLUT.h"

#ifndef GLUT_STROKE_CHAR
CFTRender CGraphicsDriverGLUT::mRender(10000);
#endif
CGraphicsDriverGLUT::CGraphicsDriverGLUT(Int32 windowWidth, Int32 windowHeight) :
	AGraphicsDriver(windowWidth, windowHeight)
{
}

void CGraphicsDriverGLUT::init()
{
	int dummy = 0;
	glutInit(&dummy, NULL);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(getWindowWidth(), getWindowHeight());
	glutCreateWindow("OpenGLdemo");

	glEnable(GL_LINE_SMOOTH);
	glShadeModel(GL_SMOOTH);
	glDisable(GL_ALPHA_TEST);
	glAlphaFunc(GL_EQUAL, 1.0f);
	glEnable(GL_BLEND);
	glEnable(GL_LINE_SMOOTH);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glViewport(0, 0, getWindowWidth(), getWindowHeight());
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glOrtho(0, getWindowWidth(), 0, getWindowHeight(), 0, 100);
}

void CGraphicsDriverGLUT::run()
{
	glutDisplayFunc(getDrawRoutine());
	glutMainLoop();
}

void CGraphicsDriverGLUT::renderText(float posX, float posY, float scale,
		const char* text)
{
	const char *p;
	glPushMatrix();
	glDisable(GL_DEPTH_TEST);

#ifdef GLUT_STROKE_CHAR
	glTranslatef(posX, posY, 0.0);
	glScalef(scale, scale, 0.1);
	for (p = text; *p; p++)
	glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
#else
	//TODO implement scale
	mRender.setFont(CFTRender::NORMAL_NPROP);
	mRender.setFontSize(CFTRender::FONT_SIZE_MAXIMUM);
	mRender.setForegroundColor(1, 1, 1, 1); //white with alpha //TODO set color depending on current gl color
	mRender.drawString(text, posX, posY);

#endif

	glPopMatrix();
}

void CGraphicsDriverGLUT::finishDraw()
{
	glutSwapBuffers();
	glutPostRedisplay();

	sleep(1); // TODO hack hardcoded update rate to prevent busy loop
}

