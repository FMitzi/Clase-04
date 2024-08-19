#include <stdio.h>
#include <stdlib.h>

void portada (){
	
	printf("\t\tRECORRIDO DE MATRICES\n\n");
	system ("pause");

}

void ZigZag (){
    system("cls");  
	int i, j;
    int col=4;
    int fila=6;
    
    
	int matzz[6][4] = {
	  { 1,  2,  3,  4},
      { 5,  6,  7,  8},
      {9, 10, 11, 12},
      {13, 14, 15, 16},
      {17, 18, 19, 20},
      {21, 22, 23, 24}
	};
	
	
	for (i = 0; i < fila; i++) {
        if (i % 2 == 0) {  // Si es par, recorrer de izquierda a derecha
            for (j = 0; j < col; j++) {
                printf("%d ", matzz[i][j]);
            }
        } else {  // Si es impar, recorrer de derecha a izquierda
            for (j = col - 1; j >= 0; j--) {
                printf("%d ", matzz[i][j]);
            }
        }
        printf("\n");  // Nueva l�nea despu�s de cada fila
    }

	
}

void RecorridoZ (){
    int i, j;
    int col = 4;
    int fila = 6;
    
    system("cls");
    
    int matd[6][4] = {
        { 1,  2,  3,  4},
        { 5,  6,  7,  8},
        { 9, 10, 11, 12},
        {13, 14, 15, 16},
        {17, 18, 19, 20},
        {21, 22, 23, 24}
    };
    
    
    for (j = 0; j < col; j++) {
        printf("%d ", matd[fila-1][j]);
    }
    
    
    for (i = fila - 2, j = col - 2; i > 0 && j > 0; i--, j--) {
        printf("%d ", matd[i][j]);
    }
    
    
    for (j = col - 1; j >= 0; j--) {
        printf("%d ", matd[0][j]);
    }

    printf("\n");
}

int menu (){
	int opcion;
	
	printf("Seleccione un tipo de recorrido: ");

	printf("1. Recorrido en Zigzag\n");
	printf("2. Recorrido en Z invertido\n");
	printf("3. salir\n");

	do{
		printf("Opci�n: ");
		scanf("%d", &opcion);
	}while(opcion<1 || opcion>3);

    return opcion;
}


int main (){
	int respuesta;
	
	portada();
	do{
		respuesta=menu();

		switch(respuesta){
			case 1:
				ZigZag();
				break;
			case 2:
				RecorridoZ();
				break;
			case 3:
			    printf("Hasta luego\n");
			    break;
			}
	}while(respuesta != 3);
	
	system("pause");
	
	return 0;
}

