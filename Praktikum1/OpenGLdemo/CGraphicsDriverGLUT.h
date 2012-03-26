#ifndef CGRAPHICSDRIVERGLUT_H_
#define CGRAPHICSDRIVERGLUT_H_

#include "AGraphicsDriver.h"

#include "CFTRender.h"

class CGraphicsDriverGLUT: public AGraphicsDriver
{
public:
	CGraphicsDriverGLUT(Int32 windowWidth, Int32 windowHeight);

	virtual void init();
	virtual void run();
	virtual void renderText(float pos_x, float pos_y, float scale,
			const char* text);
	virtual void finishDraw();
#ifndef GLUT_STROKE_CHAR
private:
	static CFTRender mRender;
#endif
};

#endif /* CGRAPHICSDRIVERGLUT_H_ */
