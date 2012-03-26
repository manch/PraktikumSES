#ifndef AGRAPHICSDRIVER_H_
#define AGRAPHICSDRIVER_H_

#include "Global.h"

typedef void(*PTtoDrawFunction)(void);


class AGraphicsDriver
{
public:
	AGraphicsDriver(Int32 windowWidth, Int32 windowHeight) {
		this->mWindowWidth = windowWidth;
		this->mWindowHeight = windowHeight;
	}

	virtual void init() = 0;
	virtual void run() = 0;
	virtual void renderText(float pos_x, float pos_y, float scale, const char* text) = 0;
	virtual void setDrawRoutine(PTtoDrawFunction);
	virtual PTtoDrawFunction getDrawRoutine() {
		return mDrawFunction;
	}

	virtual void finishDraw() = 0;

	Int32 getWindowWidth() const
    {
        return mWindowWidth;
    }

    void setWindowWidth(Int32 windowWidth)
    {
        this->mWindowWidth = windowWidth;
    }

    Int32 getWindowHeight() const
    {
        return mWindowHeight;
    }

    void setWindowHeight(Int32 windowHeight)
    {
        this->mWindowHeight = windowHeight;
    }



private:
    void (*mDrawFunction)(void);
    Int32 mWindowWidth;
    Int32 mWindowHeight;
};

#endif /* AGRAPHICSDRIVER_H_ */
