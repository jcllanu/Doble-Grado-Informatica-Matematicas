
#include "trafo.h"
#include "types.h"

//-----------------------------------------------------------------------------------
//Las funciones que se definan en ensamblador deber�n borrarse de este fichero
//de otra manera habr�a dos definciones de la misma funci�n
//-----------------------------------------------------------------------------------

void RGB2GrayMatrix(pixelRGB orig[N][M], int dest[N][M], int nfilas, int ncols) {
    int i,j;
    
    for (i=0;i<nfilas;i++)
        for (j=0; j<ncols; j++)
            dest[i][j] =  rgb2gray(orig[i][j]);
    
}

void Gray2BinaryMatrix(int orig[N][M], int dest[N][M], int nfilas, int ncols) {
    int i,j;
    int umbral = 127;
    
    for (i=0;i<nfilas;i++)
        for (j=0; j<ncols; j++)
            if (orig[i][j] > umbral)
                dest[i][j]=1;
            else
                 dest[i][j]=0;
    
}


int rgb2gray(pixelRGB pixel) {
    return  ( (2126*pixel.R + 7152*pixel.G + 722*pixel.B) /10000);
}

/*
void contarUnos(int mat[N][M], int vector[], int nfilas, int ncols) {
    int i,j;

    for (i=0;i<nfilas;i++) {
        vector[i]=0;
        for (j=0; j<ncols; j++) {
            if ( mat[i][j] == 1) vector[i]++;
        }
    }
}
*/


int SumaDeUnos(int vector[], int nfilas){
	int i, suma;
	suma = 0;
	for(i = 0; i < nfilas; i++){
		suma = suma + vector[i];
	}
	return suma;
}
