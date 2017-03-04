#include "ProtableGrayMap.h"
#include "stdlib.h"
#include "stdio.h"
#include "GlyphBDF.h"

extern unsigned char PGMBuffer[Max_range*32][Max_line*16];

/**
	*function:get the bitmap of Glyph to PGM map
	*@author:pandabob
	*@email:1287928950@qq.com
	*/
void PGM_ASIIC_versionsInit(PGM PGM_Map,unsigned char Glyph){
	
	FILE *BDP_file;//file head pointer
	GlyphBDF Glyph_BDF;
	GlyphBDF_Init(&Glyph_BDF,8,16);
	GlyphBDF_FindGlyph(BDP_file,&Glyph_BDF,Glyph);
	
	for(int i=0;i<16;i++)
		for(int j=0; j<8; j++)
			PGM_Map->ASIIC_versions[i][j]=0;
		
	for(int i=0;i<16;i++)
		for(int j=0;j<2;j++){
			
			switch(Glyph_BDF.BITMAP[i][j]){
				case '0':break;
				
				case '1':{
					if(j==0)
						PGM_Map->ASIIC_versions[i][3]=15;
					else 
						PGM_Map->ASIIC_versions[i][7]=15;
					break;
				}
				
				case '2':{
					if(j==0)
						PGM_Map->ASIIC_versions[i][2]=15;
					else
						PGM_Map->ASIIC_versions[i][6]=15;
					break;
					
				}
				
				case '3':{
					if(j==0){
						PGM_Map->ASIIC_versions[i][3]=15;
						PGM_Map->ASIIC_versions[i][2]=15;
					}
					else{
						PGM_Map->ASIIC_versions[i][7]=15;
						PGM_Map->ASIIC_versions[i][6]=15;
					}
					break;
				}
					
				case '4':{
					if(j==0)
						PGM_Map->ASIIC_versions[i][1]=15;
					else 
						PGM_Map->ASIIC_versions[i][5]=15;
					break;
				}
				
				case '5':{
					if(j==0){
						PGM_Map->ASIIC_versions[i][3]=15;
						PGM_Map->ASIIC_versions[i][1]=15;
					}
					else{
						PGM_Map->ASIIC_versions[i][7]=15;
						PGM_Map->ASIIC_versions[i][5]=15;
					}
					break;
				}
				
				case '6':{
					if(j==0){
						PGM_Map->ASIIC_versions[i][2]=15;
						PGM_Map->ASIIC_versions[i][1]=15;
					}
					else{
						PGM_Map->ASIIC_versions[i][6]=15;
						PGM_Map->ASIIC_versions[i][5]=15;
					}
					break;	
				}
				
				case '7':{
					if(j==0){
						PGM_Map->ASIIC_versions[i][3]=15;
						PGM_Map->ASIIC_versions[i][2]=15;
						PGM_Map->ASIIC_versions[i][1]=15;
					}
					else{
						PGM_Map->ASIIC_versions[i][7]=15;
						PGM_Map->ASIIC_versions[i][6]=15;
						PGM_Map->ASIIC_versions[i][5]=15;
					}
					break;
				}
				
				case '8':{
					if(j==0)
						PGM_Map->ASIIC_versions[i][0]=15;
					else
						PGM_Map->ASIIC_versions[i][4]=15;
					break;
				}
				
				case '9':{
					if(j==0){
						PGM_Map->ASIIC_versions[i][3]=15;
						PGM_Map->ASIIC_versions[i][0]=15;
					}
					else{
						PGM_Map->ASIIC_versions[i][7]=15;
						PGM_Map->ASIIC_versions[i][4]=15;
					}
					break;
				}
				
				case 'A':{
					
					if(j==0){
						PGM_Map->ASIIC_versions[i][2]=15;
						PGM_Map->ASIIC_versions[i][0]=15;
					}
					else{
						PGM_Map->ASIIC_versions[i][6]=15;
						PGM_Map->ASIIC_versions[i][4]=15;
					}
					break;
				}
				 
				case 'B':{
					
					if(j==0){
						PGM_Map->ASIIC_versions[i][3]=15;
						PGM_Map->ASIIC_versions[i][2]=15;
						PGM_Map->ASIIC_versions[i][0]=15;
					}
					else{
						PGM_Map->ASIIC_versions[i][7]=15;
						PGM_Map->ASIIC_versions[i][6]=15;
						PGM_Map->ASIIC_versions[i][4]=15;
					}
					break;
				}
				
				case 'C':{
					
					if(j==0){
						PGM_Map->ASIIC_versions[i][1]=15;
						PGM_Map->ASIIC_versions[i][0]=15;
					}
					else{
						PGM_Map->ASIIC_versions[i][5]=15;
						PGM_Map->ASIIC_versions[i][4]=15;
					}
					break;
				}
				
				case 'D':{
					
					if(j==0){
						PGM_Map->ASIIC_versions[i][3]=15;
						PGM_Map->ASIIC_versions[i][1]=15;
						PGM_Map->ASIIC_versions[i][0]=15;
					}
					else{
						PGM_Map->ASIIC_versions[i][7]=15;
						PGM_Map->ASIIC_versions[i][5]=15;
						PGM_Map->ASIIC_versions[i][4]=15;
					}
					break;
				}
				
				case 'E':{
					
					if(j==0){
						PGM_Map->ASIIC_versions[i][2]=15;
						PGM_Map->ASIIC_versions[i][1]=15;
						PGM_Map->ASIIC_versions[i][0]=15;
					}
					else{
						PGM_Map->ASIIC_versions[i][6]=15;
						PGM_Map->ASIIC_versions[i][5]=15;
						PGM_Map->ASIIC_versions[i][4]=15;
					}
					break;
				}
				
				case 'F':{
					
					if(j==0){
						PGM_Map->ASIIC_versions[i][3]=15;
						PGM_Map->ASIIC_versions[i][2]=15;
						PGM_Map->ASIIC_versions[i][1]=15;
						PGM_Map->ASIIC_versions[i][0]=15;
					}
					else{
						PGM_Map->ASIIC_versions[i][7]=15;
						PGM_Map->ASIIC_versions[i][6]=15;
						PGM_Map->ASIIC_versions[i][5]=15;
						PGM_Map->ASIIC_versions[i][4]=15;
					}
					break;
				}
				
				default: exit(2);
				
			}
		}
}

/**
	*function:initialization the struct of PGM map
	*
	*
	*/
void ProtableGrayMapASIIC_Init(PGM PGM_Map,int width,int high,unsigned char Glyph){
	
	PGM_Map->Max_value=20;
	PGM_Map->Magic=2;
	PGM_Map->X_axis=width;
	PGM_Map->Y_axis=high;
	PGM_ASIIC_versionsInit(PGM_Map,Glyph);
	
}

/**
	*function:write the data to the header of file.pgm 
	*
	*
	*/
int WritePGMHeader(FILE *stream,PGM PGM_Map){
	
	   if (stream==NULL) {  
        printf("FILE error\n");  
        exit(3);  
    }  
  
    switch(PGM_Map->Magic){
    
    	case 1:{
    	
    		fprintf(stream,"P1\n");	
    		break;
    	}	
    	case 2:	{
    	
    		fprintf(stream,"P2\n");	
    		break;
    	}
    	case 3:{
    	
    		fprintf(stream,"P3\n");	
    		break;
    	}	
    	case 4:{
    	
    		fprintf(stream,"P4\n");	
    		break;
    	}	
    	case 5:{
    	
    		fprintf(stream,"P5\n");	
    		break;
    	}	
    	case 6:{
    	
    		fprintf(stream,"P6\n");	
    		break;
    	}	
    	default :	exit(4);
    }
    
    fprintf(stream,"%d,%d\n",PGM_Map->X_axis,PGM_Map->Y_axis);
    fprintf(stream,"%d\n",PGM_Map->Max_value);
    
    return 1;  
}

/**
	*function:write the data to file.gpm
	*
	*
	*/
void WritePGMData(PGM PGM_Map,int range,int line) {  
    
    for(int i=0;i<16;i++) {   // every rwo 
     			
        for(int j=0;j<8;j++) {   // every line 
        		
        		PGMBuffer[range*32+2*i][line*16+2*j]=PGM_Map->ASIIC_versions[i][j];
        		PGMBuffer[range*32+2*i][line*16+2*j+1]=PGM_Map->ASIIC_versions[i][j];
        } 
        for(int j=0;j<8;j++) {   // every line  
        
        	PGMBuffer[range*32+2*i+1][line*16+2*j]=PGM_Map->ASIIC_versions[i][j];
        	PGMBuffer[range*32+2*i+1][line*16+2*j+1]=PGM_Map->ASIIC_versions[i][j];	 
        } 
    }
    
}  

/**
	*function:initialzation the file.pgm buffer
	*
	*
	*/

void WritePGMBufferInit(FILE* stream,PGM PGM_Map,int max_range,int max_line){
	
	ProtableGrayMapASIIC_Init(PGM_Map,max_line*16,max_range*32,' ');
	WritePGMHeader(stream,PGM_Map);
	fgetpos(stream,&(PGM_Map->pos));
	for(int i=0;i<max_range;i++)
		for(int j=0;j<max_line;j++)
			WritePGMData(PGM_Map,i,j);
}
/**
	*write the buffer data to the file.pgm
	*
	*/
void UpdataPGMBuffer(FILE* stream,PGM PGM_Map){
	
	fsetpos(stream,&(PGM_Map->pos));
	for(int i=0;i<Max_range*32;i++){
	
		for(int j=0;j<Max_line*16;j++){
			if(!PGMBuffer[i][j])
				fprintf(stream," %d ",PGMBuffer[i][j]);
			else
				fprintf(stream,"%d ",PGMBuffer[i][j]);
		}
		fprintf(stream,"\n");
	}
	

}




/******************end file*********************/

