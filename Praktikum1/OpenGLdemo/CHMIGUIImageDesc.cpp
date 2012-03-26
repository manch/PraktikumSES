#include "CHMIGUIImageDesc.h"

const int CHMIGUIImageDesc::mBitsForPixelType[] = { 8, 		// UNSIGNED_BYTE
										8, 		// BYTE
										1, 		// BITMAP
										2*8, 	// SHORT
										2*8, 	// UNSIGNED_SHORT
										4*8, 	// INT
										4*8, 	// UNSIGNED_INT
										4*8 }; 	// FLOAT
/**
 * components of the PixelFormat
 */
const int CHMIGUIImageDesc::mPixelFormatComponents[] = { 4, // RGBA
									3, // RGB
									1, // ALPHA
									1, // RED
									1, // GREEN
									1, // BLUE
									1, // ALPHA_BIAS
									1, // LUMINANCE
									2}; // LUMINANCE_ALPHA
