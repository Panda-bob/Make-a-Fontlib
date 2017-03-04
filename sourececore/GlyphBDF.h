#ifndef _GLYPHBDF_H_
#define _GLYPHBDF_H_

struct Glyph_BDF{
		unsigned char ENCODIN;//ENCODING is followed by a positive integer representing the Adobe Standard Encoding value
		unsigned char BBw;//the width of the black pixels in x
		unsigned char BBh;//the height in y
		unsigned char BITMAP[16][2];//BITMAP introduces the hexadecimal data for the character bitmap
		unsigned int  File_offset[9];
};
typedef struct Glyph_BDF GlyphBDF;
typedef GlyphBDF * BDF;

void GlyphBDF_Init(BDF Glyph_BDF,char BBw,char BBh);
int GlyphBDF_FindGlyph(FILE *stream,BDF Glyph_BDF,unsigned char Glyph);

//typedef unsigned long       DWORD;
//typedef int                 BOOL;
//typedef unsigned char       BYTE;
//typedef unsigned short      WORD;










#endif

/*********************end file******************/

