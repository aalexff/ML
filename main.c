#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//Primitivas de funciones
float wAndX();
bool calculoDeR(float r);
//Declaracion de parametros
float n = 0.25, err;
int iteracion = 0;
bool x[4][2]={{0,0},{0,1},{1,0},{1,1}};
int weight[2] = {0.8, 0.4};

int main(int argc, char *argv[]) {
	//Declaracion de variables
	bool andl[4] = {0,0,0,1}, orl[4] = {0,1,1,1};

	while (iteracion <= 100){
		wAndX();
	/*	wOrX();
		yAnd();
		yOr();
		//LMS
		w(n+1)And
		w(n+1)Or*/
		iteracion++;
	};
	 
	return 0;
}

float wAndX(){
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
	}
}