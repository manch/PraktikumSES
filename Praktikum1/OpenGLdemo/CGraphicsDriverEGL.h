#ifndef CGRAPHICSDRIVEREGL_H_
#define CGRAPHICSDRIVEREGL_H_

#include "AGraphicsDriver.h"

#include "CFTRender.h"

class CGraphicsDriverEGL: public AGraphicsDriver
{

public:
	CGraphicsDriverEGL(Int32 windowWidth, Int32 windowHeight) :
		AGraphicsDriver(windowWidth, windowHeight)
	{
	}

	virtual void init();
	virtual void run();
	virtual void renderText(float pos_x, float pos_y, float scale,
			const char* text);
	virtual void finishDraw();

	static CFTRender mRender;
};

#endif /* CGRAPHICSDRIVEREGL_H_ */
