/*
 * Compile this file together with the ASCII Art source code
 * to generate the executable. For example: 
 *
 *  gcc -W -Wall -O6 ascii_art.c sample.c -o ascii
 * ./ascii test.png
 *
 * If you get a compile-time error, that mean that the `ascii_art.hex` model is missing.
 * Download it from: https://pixlab.io/art
 */

#include <stdio.h>
#include <stdlib.h>
#include "ascii_art.h"

int main(int argc, char **argv) {
	ascii_render sRender; /* Stack allocated */
	
	unsigned char *zText, *zBlob;
	int width, height;
	unsigned int nBytes;
	
	if( argc < 2 ){
		puts("Missing input image");
		return -1;
	} 
	
	/* Initialize the render structure */
	AsciiArtInit(&sRender);

	/* Load an image from disk */
	zBlob = AsciiArtLoadImage(argv[1], &width, &height);
	if (zBlob == 0) {
		puts("Cannot load image");
		return -1;
	}

	/* Allocate a buffer big enough to hold the entire text output */
	nBytes = AsciiArtTextBufSize(&sRender, width, height);
	zText = malloc(nBytes);

	/* Finally, process */
	AsciiArtRender(&sRender, zBlob, &width, &height, zText, 1);

	/* Output the result */
	fwrite(zText, sizeof(char), nBytes, stdout);
	/* zBlob[] hold the binary ASCII glyphs now */

	/* Release memory */
	free(zText);
	free(zBlob);
	
	return 0;
}
