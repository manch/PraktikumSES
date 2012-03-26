/**
 * Simon Kretschmer
 */

#ifndef _CHMIGUIIMAGEDESC_H_
#define _CHMIGUIIMAGEDESC_H_

class CHMIGUIImageDesc
{
private:
	/**
	 * stores number of Bits needed for the DataType
	 */
	static const int mBitsForPixelType[];
	/**
	 * components of the PixelFormat
	 */
	static const int mPixelFormatComponents[];

public:
	// different pixel formats
	enum ePixelFormat
	{
		RGBA,
		RGB,
		ALPHA,
		RED,
		GREEN,
		BLUE,
		ALPHA_BIAS,
		LUMINANCE,
		LUMINANCE_ALPHA
	};

	// different pixel data types
	enum ePixelType
	{
		UNSIGNED_BYTE,
		BYTE,
		BITMAP,
		SHORT,
		UNSIGNED_SHORT,
		INT,
		UNSIGNED_INT,
		FLOAT
	};

	/**
	 * \brief constructor sets the PixelFormat and PixelType to default values
	 */
	CHMIGUIImageDesc(void) : mPixelFormat(RGBA), mPixelType(UNSIGNED_BYTE) {}

	/**
	 * \brief returns the number of Bytes needed per Pixel
	 * if you use the Bitmap PixelType you have to call
	 * \sa getBitsPerPixel
	 */
	int getBytesPerPixel(void)
	{
		return mBitsForPixelType[mPixelType]*mPixelFormatComponents[mPixelFormat]/8;
	}

	/**
	 * \brief returns the number of Bits needed per Pixel
	 * needed for calculating memory size for bitmaps of
	 * BITMAP-PixelType
	 */
	int getBitsPerPixel(void)
	{
		return mBitsForPixelType[mPixelType]*mPixelFormatComponents[mPixelFormat];
	}

	int mWidth;
	int mHeight;
	int mPitch;

	ePixelFormat mPixelFormat;
	ePixelType mPixelType;

	int *mPixelData;
};

#endif //_CHMIGUIIMAGEDESC_H_
