#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//Primitivas de funciones
float wAndX();
float wOrX();
bool calculoDeR(float r);

//Declaracion de parametros
float n = 0.25, err;
int iteracion = 0;
bool x[4][2]={{0,0},{0,1},{1,0},{1,1}};
int weight[4] = {0.8, 0.4, 0.7, 0.1};

bool xOR[4][4]= {{0,0,0,1},{0,1,1,1},{1,0,1,1},{1,1,1,1}}; //bool??
bool xAND[4][4]= {{0,0,0,1},{0,1,0,1},{1,0,0,1},{1,1,1,1}};
	/*
		Matriz de OR
		0 0 1 1 Xentrada1
		0 1 0 1 Xentrada2
		0 1 1 1 Resultados
		1 1 1 1 La matriz que dijo Juan que siempre esta en 1
		
		Matriz de AND
		0 0 1 1 Xentrada1
		0 1 0 1 Xentrada2
		0 0 0 1 Resultados
		1 1 1 1 La matriz que dijo Juan que siempre esta en 1
		
		Sin la fila de resultados, los pesos para OR y AND serian iguales,
		pero ahora necesita un peso mas para hacer el producto punto.
		Un total de 4 pesos 
	*/

int perceptronMain(int argc, char *argv[]) {
	//Declaracion de variables
	//bool andl[4] = {0,0,0,1}, orl[4] = {0,1,1,1};
	while (iteracion <= 100){
		wAndX();
		wOrX();
	/*	yAnd();
		yOr();
		//LMS
		w(n+1)And
		w(n+1)Or*/
		iteracion++;
	};
	 
	return 0;
}

float wAndX(){
	float rAnd[4], dn, wXn[4]/*delta*/; //= a resultado wXn
	bool Fr;
	for(int j = 0; j <= 3; j++){
		for(int i = 0; i <= 3; i++){ //Multiplicación producto punto, lee un peso por cada elemento en cada fila
			rAnd[j] = weight[i]; //Para que no haya alteracion del valor del peso en la primera iteracion
			wXn[i] = weight[i] * xAND[j][i]; //El valor del peso cambia con dada elemento
			dn = wXn[i]-weight[i];
			err = dn - wXn[i];
			weight[i] = wXn[i-1]-n*err*xAND[j][i]; //weight vale su valor actual mas el anterior.			
		}	
		Fr = calculoDeR(rAnd[j]); // No se que se hacia con el calculo de R pero estaba en el cuaderno
	}
}

float wOrX(){
	float rOr[4], dn, wXn[4]/*delta*/; //= a resultado wXn
	bool Fr;
	for(int j = 0; j <= 3; j++){ //Multiplicación producto punto, lee un peso por cada elemento en cada fila
		for(int i = 0; i <= 3; i++){ 
			rOr[j] = weight[i]; //Para que no haya alteracion del valor del peso en la primera iteracion
			wXn[i] = weight[i] * xOR[j][i]; //El valor del peso cambia con dada elemento
			dn = wXn[i]-weight[i];
			err = dn - wXn[i];
			weight[i] = wXn[i-1]-n*err*xOR[j][i]; //weight vale su valor actual mas el anterior.	
		}
		Fr = calculoDeR(rOr[j]);	
	}
}

bool calculoDeR(float r){
	bool Fr;
	if (r>=0){
		Fr = 1;
		return Fr;
	}else{
		Fr = 0;
		return Fr;
	}
}