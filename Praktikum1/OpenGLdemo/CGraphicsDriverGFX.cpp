#include "GraphicsIncludes.h"
#include "CGraphicsDriverGFX.h"

GfxEglState CGraphicsDriverGFX::mGfxEglState;

CFTRender CGraphicsDriverGFX::mRender(10000);

void CGraphicsDriverGFX::init()
{
	memset(&mGfxEglState, 0, sizeof(mGfxEglState)); // passiert im Konstrukturaufruf
	if (!GfxEglInitialize(&mGfxEglState))
		TRACE("Graphics initialization failed!")
	else
	{
		TRACE("Graphics initialized...")
	}

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

	glOrthof(0, getWindowWidth(), 0, getWindowHeight(), 0, 100);
}

void CGraphicsDriverGFX::run()
{
	while (true)
	{
		getDrawRoutine()();
		GfxEglSwapBuffers(&mGfxEglState);
		sleep(1); // TODO hack hardcoded update rate to prevent busy loop;
	}
}

void CGraphicsDriverGFX::renderText(float posX, float posY, float scale,
		const char* text)
{
	TRACE("entered for [%s]",text)

	mRender.setFont(CFTRender::NORMAL_NPROP);
	mRender.setFontSize(CFTRender::FONT_SIZE_MAXIMUM);
	mRender.setForegroundColor(1, 1, 1, 1); //white with alpha //TODO set color depending on current gl color
	mRender.drawString(text, posX, posY);

}

void CGraphicsDriverGFX::finishDraw()
{
	eglWaitGL();
	eglWaitNative(0);
}

