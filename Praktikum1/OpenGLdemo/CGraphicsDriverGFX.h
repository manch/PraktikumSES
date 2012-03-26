#ifndef CGRAPHICSDRIVERGFX_H_
#define CGRAPHICSDRIVERGFX_H_

#include "AGraphicsDriver.h"

#include "CFTRender.h"

class CGraphicsDriverGFX: public AGraphicsDriver
{

public:
	CGraphicsDriverGFX(Int32 windowWidth, Int32 windowHeight) :
		AGraphicsDriver(windowWidth, windowHeight)
	{
	}

	virtual void init();
	virtual void run();
	virtual void renderText(float pos_x, float pos_y, float scale,
			const char* text);
	virtual void finishDraw();

	static CFTRender mRender;
	static GfxEglState mGfxEglState;
};

#endif /* CGRAPHICSDRIVERGFX_H_ */
