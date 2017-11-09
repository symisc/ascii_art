/*
* ASCII Art: Real-time ASCII Art Rendering Library.
* Copyright (C) PixLab. https://pixlab.io/art
* Version 1.2
* For information on licensing, redistribution of this file, and for a DISCLAIMER OF ALL WARRANTIES
* please contact:
*       support@pixlab.io
*       contact@pixlab.io
* or visit:
*     https://pixlab.io/art
*/
/*
 * An Implementation based on the paper:
 * > N. Markus, M. Fratarcangeli, I. S. Pandzic and J. Ahlberg, "Fast Rendering of Image Mosaics and ASCII Art", Computer Graphics Forum, 2015, http://dx.doi.org/10.1111/cgf.12597
 */
#ifndef __ASCIIART_H__
#define __ASCIIART_H__
/* Make sure we can call this stuff from C++ */
#ifdef __cplusplus
extern "C" {
#endif 

#if defined (_MSC_VER) || defined (__MINGW32__) ||  defined (__GNUC__) && defined (__declspec)
#define ART_APIEXPORT	__declspec(dllexport)
#else
#define	ART_APIEXPORT
#endif
#ifndef INDEX_MATRIX_SZ
#define INDEX_MATRIX_SZ 640 * 480
#endif
/*
 * Current rendering state and the glyph table is recorded on a instance
 * of the following structure.
 */
typedef struct ascii_render ascii_render;
struct ascii_render
{
	int nGlyphs;
	unsigned char* zGlyphs[256];
	unsigned char zMatrix[INDEX_MATRIX_SZ];
	int nRows;
	int nCols;
	int* pTree;
};
/*
* CAPIREF: Refer to the official documentation for the main purpose of this interface.
*/
ART_APIEXPORT void AsciiArtInit(ascii_render *pRender);
/*
* CAPIREF: Refer to the official documentation for the main purpose of this interface.
*/
ART_APIEXPORT unsigned int AsciiArtTextBufSize(ascii_render *pRender, int img_width, int img_height);
/*
* CAPIREF: Refer to the official documentation for the main purpose of this interface.
*/
ART_APIEXPORT void AsciiArtRender(ascii_render *pRender, unsigned char *zPixel /*IN/OUT*/, int *pnWidth /*IN/OUT*/, int *pnHeight /*IN/OUT*/, unsigned char *zBuf/* Optional/OUT */, int Optimize);

#ifdef ART_ENABLE_STB_IMAGE
/*
* CAPIREF: Refer to the official documentation for the main purpose of this interface.
*/
ART_APIEXPORT unsigned char * AsciiArtLoadImage(const char *zPath, int *pWidth, int *pHeight);
#endif /* ART_ENABLE_STB_IMAGE */

#ifdef __cplusplus
}
#endif 
#endif /* __ASCIIART_H__ */