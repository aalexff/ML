#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//Primitivas de funciones
float wAndX();
<<<<<<< Updated upstream
bool calculoDeR(float r);
/* Posibles matrices individuales de tamaño completo, 
bool xOR[4][4]= {{0,0,0,1},{0,1,1,1},{1,0,1,1},{1,1,1,1}} //bool??
bool xAND[4][4]= {{0,0,0,1},{0,1,0,1},{1,0,0,1},{1,1,1,1}}

ojala pudiera dibujar en los IDE
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
*/
//Declaracion de parametros
float n = 0.25, err;
int iteracion = 0;
bool x[4][2]={{0,0},{0,1},{1,0},{1,1}};
int weight[2] = {0.8, 0.4};

int main(int argc, char *argv[]) {
=======
float wOrX();

bool yAnd();
bool yOr();

bool calculoDeR();

//Declaracion de parametro
float n = 0.25, errAnd[4], errOr[4];
int iteracion = 0;
bool x[4][2]={{0,0},{0,1},{1,0},{1,1}};

float w1[3] = {0.4, 0.3, 0.8};
float w2[3] = {0.5, 0.5, 0.5};

bool xOR[4][4]= {{0,0,1},{0,1,1},{1,0,1},{1,1,1}};
bool xAND[4][4]= {{0,0,1},{0,1,1},{1,0,1},{1,1,1}};

bool dAnd[4]={0,0,0,1};
bool dOr[4]={0,1,1,1};


	/*
		0 1 0 1 Xentrada2
		0 1 1 1 Resultados
		1 1 1 1 La matriz que dijo Juan que siempre esta en 1
		
		Matriz de AND
		0 0 1 1 Xentrada1
		0 1 0 1 Xentrada2
		1 1 1 1 La matriz que dijo Juan que siempre esta en 1
		
		Sin la fila de resultados, los pesos para OR y AND serian iguales,
		pero ahora necesita un peso mas para hacer el producto punto.
		Un total de 4 pesos 
	*/

int perceptronMain(int argc, char *argv[]) {
>>>>>>> Stashed changes
	//Declaracion de variables
	bool andl[4] = {0,0,0,1}, orl[4] = {0,1,1,1};

	while (iteracion <= 100){
		wAndX();
<<<<<<< Updated upstream
	/*	wOrX();
		yAnd();
		yOr();
		//LMS
=======
		wOrX();
		
	/*  //LMS
>>>>>>> Stashed changes
		w(n+1)And
		w(n+1)Or*/
		
		iteracion++;
	};
	 
	return 0;
}

float wAndX(){
<<<<<<< Updated upstream
	float r[4];
	for(int j = 0; j <= 3; j++){
		for(int i = 0; i <= 1; i++){
			r[j] = weight[i] * x[j][i];
			calculoDeR(r[i]);
		}	
	}
}

bool calculoDeR(float r){
	if (r>=0){
		return 1;
	}else{
		return 0;
=======
	float rAnd[4], wXn[4]/*delta*/; //= a resultado wX
	
	for(int j = 0; j <= 3; j++){
		for(int i = 0; i <= 2; i++){ //Multiplicacion producto punto, lee un peso por cada elemento en cada fila
			rAnd[j] = w1[i] + w1[i-1]; //Para que no haya alteracion del valor del peso en la primera iteracion
			w1[i] = w1[i] * xAND[j][i]; //El valor del peso cambia con dada elemento		
		}	
	}
	
	yAnd(rAnd[4]);
}

float wOrX(){
	float rOr[4], wXn[4]/*delta*/; //= a resultado wXn
	
	for(int j = 0; j <= 3; j++){ //Multiplicacion producto punto, lee un peso por cada elemento en cada fila
		for(int i = 0; i <= 2; i++){ 
			rOr[j] = w2[i] + w2[i-1]; //Para que no haya alteracion del valor del peso en la primera iteracion
			w2[i] = w2[i] * xOR[j][i]; //El valor del peso cambia con dada elemento	
		}
	}
	
	yOr(rOr[4]);
}

bool yAnd(float rAnd[4]){
	
	bool y1[4];
	
	y1[4]=calculoDeR(rAnd[4]);
	
	for(int aux=0; aux<=3; aux++){
		errAnd[aux] = dAnd[aux] - y1[aux];
	}
	
}

bool yOr(float rOr[4]){
	
	bool y2[4];
	
	y2[4]=calculoDeR(rOr[4]);
	
	for(int aux=0; aux<=3; aux++){
		errOr[aux] = dOr[aux] - y2[aux];
	}
}

bool calculoDeR(float r[4]){
	bool Fr[4];
	
	for(int aux=0; aux<=3; aux++){
		if (r[aux]>=0){
			Fr[aux] = 1;
			return Fr[aux];
		}
		else{
			Fr[aux] = 0;
			return Fr[aux];
		}
>>>>>>> Stashed changes
	}
}

	//		err = dnAnd - wXn[i];
	//		err = dnOr - wXn[i];
	
/*
AND

	bool dnAnd[4]={0,0,0,1};
	bool FrAnd[4];
	
dnAnd[i] = wXn[i]-w1[i];
w1[i] = wXn[i-1]-n*err*xAND[j][i]; //weight vale su valor actual mas el anterior.			

Fr[j] = calculoDeR(rAnd[j]); // No se que se hacia con el calculo de R pero estaba en el cuaderno

*/

/*
OR

	bool dnOr[4]={0,1,1,1};
	bool FrOr[4];
	
dnOr[i] = wXn[i]-w2[i];
w2[i] = wXn[i-1]-n*err*xOR[j][i]; //weight vale su valor actual mas el anterior.	

Fr[j] = calculoDeR(rOr[j]);	
*/
