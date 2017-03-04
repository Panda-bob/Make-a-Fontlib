#include "stdio.h"
#include "stdlib.h"
#include "GlyphBDF.h"


/**
  *function:description the storing bitmap fonts of the Glyph Bitmap Distribution Format,
  *use the glyph that is taken form the GNU Unifont.
  *
  */


/**
  *function:give parameter of the GlaypBDF initialization.
  *@author：pandabob
  *@email:1287928950@qq.com
	*time:2016/12/5
  */
void GlyphBDF_Init(BDF Glyph_BDF,char BBw,char BBh){
	
		unsigned int offset[8]={360,17,11,13,11,14,8,8};
		int sum=-360;
		Glyph_BDF->BBw=BBw;
		Glyph_BDF->BBh=BBh;
		for(int i=0;i<8;i++){
		
			Glyph_BDF->File_offset[i]=offset[i];
			sum+=offset[i];
		}		
		Glyph_BDF->File_offset[8]=sum;		
		
}


/**
	*function:find the ENCODIN offset and get the number of the ENCODIN,then get the
	*	bitmap of the glyph. 
	*time:2016/12/5
	*@author:pandabob
	*/
int GlyphBDF_FindGlyph(FILE *stream,BDF Glyph_BDF,unsigned char Glyph){
		unsigned char ch;
		unsigned char str[17];
		unsigned long offset=0;
		if((stream = fopen("unifont-asiic.bdf","r"))==NULL){
			//open file failure
			printf("file cannot be opened\n");
			exit(0);
		}
		
		 //offset=(int)(Glyph_BDF->File_offset[0]+17+11+14+12+15+8+16*5);
		//printf("%d\n",Glyph_BDF->File_offset[9]);

		/*get the head offset of the glyph */
		if(Glyph<'d')
			offset=(long)(Glyph_BDF->File_offset[0]+32*(Glyph_BDF->File_offset[8]+4+16*5)-10+(Glyph-' ')*(Glyph_BDF->File_offset[8]+1+16*3));
		else
			offset=(long)(Glyph_BDF->File_offset[0]+32*(Glyph_BDF->File_offset[8]+4+16*5)-10+('d'-' ')*(Glyph_BDF->File_offset[8]+1+16*3)+(Glyph-'d')*(Glyph_BDF->File_offset[8]+2+16*3));
		/*fseek(FILE *stream,long offset,int origin);origin=0 is start the file,1 is currenty file,2 is end the file*/
		fseek(stream,offset,0);

		//get the GlyphBDF of the ENCODIN
		if(Glyph<'d'){

			offset=Glyph_BDF->File_offset[1]+Glyph_BDF->File_offset[2]-2;
			fseek(stream,offset,1);
			ch=fgetc(stream);
			Glyph_BDF->ENCODIN=10*(ch-'0');
			ch=fgetc(stream);
			Glyph_BDF->ENCODIN+=(ch-'0');
		
			/*fputc(Glyph_BDF->ENCODIN,stdout);
			printf("\n");*/
		}
		else{

			offset=Glyph_BDF->File_offset[1]+Glyph_BDF->File_offset[2]-2;
			fseek(stream,offset,1);
			ch=fgetc(stream);
			Glyph_BDF->ENCODIN=100*(ch-'0');
			ch=fgetc(stream);
			Glyph_BDF->ENCODIN+=10*(ch-'0');
			ch=fgetc(stream);
			Glyph_BDF->ENCODIN+=(ch-'0');

			/*fputc(Glyph_BDF->ENCODIN,stdout);
			printf("\n");*/
		}
		

		offset=Glyph_BDF->File_offset[3]+Glyph_BDF->File_offset[4]+Glyph_BDF->File_offset[5]+Glyph_BDF->File_offset[6];
		fseek(stream,offset,1);
		ch=fgetc(stream);//remove '\n'
		//printf("%c",ch);
		for(int i=0;i<16;i++){

				
				for(int j=0;j<2;j++)
				{
					
					if((ch = fgetc(stream))!=EOF)
						Glyph_BDF->BITMAP[i][j]=ch;
					//fputc(ch,stdout);
				}
				ch=fgetc(stream);//remove '\n'
				//fputc(ch,stdout);
			}
		
		/*if(fgets(str,17,stream)!=NULL)
				printf("%s\n",str);	*/	
		
		
		if(fclose(stream)!=0){
			//decide the file close
			printf("close file failure\n");
			exit(0);
		}
		
		return 1;
}





/****************end file******************/

