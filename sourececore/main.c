#include <stdio.h>
#include <stdlib.h>
#include "GlyphBDF.h"
#include "ProtableGrayMap.h"
int main(void){
	
		extern unsigned char PGMBuffer[Max_range*32][Max_line*16];
		
		char * filename = "test1.pgm";
		ProtableGrayMap PGM_Map;
		
		FILE * PgmFile = fopen(filename, "w");  
    if (PgmFile==NULL) {  

        printf("FILE error\n");  
        exit(0);  
    } 
   

	


		WritePGMBufferInit(PgmFile,&PGM_Map,Max_range,Max_line);
		ProtableGrayMapASIIC_Init(&PGM_Map,Max_line*16,Max_range*32,'H');
		WritePGMData(&PGM_Map,10,40);
		ProtableGrayMapASIIC_Init(&PGM_Map,Max_line*16,Max_range*32,'e');
		WritePGMData(&PGM_Map,10,41);
		ProtableGrayMapASIIC_Init(&PGM_Map,Max_line*16,Max_range*32,'l');
		WritePGMData(&PGM_Map,10,42);
		WritePGMData(&PGM_Map,10,43);
		WritePGMData(&PGM_Map,10,49);
		ProtableGrayMapASIIC_Init(&PGM_Map,Max_line*16,Max_range*32,'o');
		WritePGMData(&PGM_Map,10,44);
		WritePGMData(&PGM_Map,10,48);
		ProtableGrayMapASIIC_Init(&PGM_Map,Max_line*16,Max_range*32,'w');
		WritePGMData(&PGM_Map,10,46);
		ProtableGrayMapASIIC_Init(&PGM_Map,Max_line*16,Max_range*32,'r');
		WritePGMData(&PGM_Map,10,47);
		ProtableGrayMapASIIC_Init(&PGM_Map,Max_line*16,Max_range*32,'d');
		WritePGMData(&PGM_Map,10,50);
		UpdataPGMBuffer(PgmFile,&PGM_Map);
	
	if(fclose(PgmFile)!=0){
			//decide the file close
			printf("close file failure\n");
			exit(0);
		}
	//printf("hello world\n");
	return 0;

}






/*******************end file*******************/

