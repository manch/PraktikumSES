#ifndef CHMIGUIIMAGE_H_
#define CHMIGUIIMAGE_H_

#include "CHMIGUIImageDesc.h"


/**
 * modes for drawing the image data to screen
 *
 * GL_FRAMEBUFFER 	via the GL-Framebuffer functions - glDrawPixels
 * GL_TEX			draw the image as full featured texture
 * GL_DRAW_TEX		with the GL ES Extensions for fast drawing textures to screen (supported only NG3-B1 with nVidia EMP)
 * GF_BITMAP_BLIT	blits a 1bit-Bitmap with the fast QNX GF functions (PixelType needs to be BITMAP (only NG3-B0)
 * GF_ALPHA_BLIT	blits to the alpha-layer (only NG3-B0) - currently not used
 */
#ifndef GL_FRAMEBUFFER
#define GL_FRAMEBUFFER 1
#endif
#define GL_TEX 2
#define GL_DRAW_TEX 3
#define GF_BITMAP_BLIT 4
#define GF_ALPHA_BLIT 5

/**
 * on NG3-B0: blitting of a b/w bitmap
 * on NG3-B1: drawing as texture - todo: use the GL_DRAW_TEX mode
 * on NG3 on Linux or Windows: use the GL_FRAMEBUFFER modes
 */

/*#if defined(__SH__)
	#define DRAWING_MODE GL_TEX
#else
	#if defined(__linux__)
		#define DRAWING_MODE GL_FRAMEBUFFER
	#endif
#endif
*/
#define DRAWING_MODE GL_TEX
/**
 * \brief representation of a surface
 *
 * the memory for the image data is not allocated or controlled by the class. this
 * is the job of the user (f.e. the allocation of the memory for font-glyphs is done
 * by the freetype library.
 *
 * if OpenGL texture drawing methods are used, the image is copied to the driver
 * but deleted afterwards. Repeated drawing of the same texture is better done
 * individually.
 */
class CHMIGUIImage
{
public:
	CHMIGUIImage(void);
	CHMIGUIImage(int* pixelData, CHMIGUIImageDesc::ePixelFormat pixelFormat, CHMIGUIImageDesc::ePixelType pixelType, int width, int height, int pitch=0);

	virtual ~CHMIGUIImage(void);
	void setImageData(int* pixelData, CHMIGUIImageDesc::ePixelFormat pixelFormat, CHMIGUIImageDesc::ePixelType pixelType, int width, int height, int pitch=0);
	void setImageData(CHMIGUIImageDesc & imageDesc);
	void setBiasColor(float red, float green, float blue, float alpha);
	void setFlipV(bool flip) { mFlipV = flip; }
	void drawToScreen(int posX, int posY);
	void flipV(void);
protected:
	CHMIGUIImageDesc mImageDesc;
	bool mFlipV;

	struct
	{
		float mRedComponent;
		float mGreenComponent;
		float mBlueComponent;
		float mAlphaComponent;
	} mBiasColor;

	void drawRGBATexture(int posX, int posY);
};

#endif // CHMIGUIIMAGE_H_
