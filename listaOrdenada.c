#include <stdio.h>
#include <stdlib.h>
#include "listaOrdenada.h"

struct ListaOrdenada{
	int n;
	int p; 
	int* dados; 
};
typedef struct ListaOrdenada ListaOrdenada;

ListaOrdenada* create(int n){ //1
	
	//complexidade espacial -> O (2) = O(c). constante.
	
	ListaOrdenada * l = (ListaOrdenada*) malloc(sizeof(ListaOrdenada)); //1 //1
 	
 	l->n = n; //1
 	l->p = 0;//1
 	
 	l->dados = (int*) calloc(sizeof(int), n); //1 
	 	
 	return l;	//1
 	
 	//complexidade temporaal -> O (5) = O(c). constante.
}

int add(ListaOrdenada* lo, int e){ //2
	
	//complexidade espacial -> O (3) = O(c). constante.
	
	if(lo!=NULL && lo->p < lo->n ) { //1
		
			int i = 0, posicao = lo->p; //1 //1
			
			for(i = 0; i < lo->p; i++){ //n
				
				if(e < lo->dados[i]){ //1
					posicao = i;  //1
					break; //1
				}
			}
			if(posicao != lo->p){ //1 
			
				for(i = lo->p+1; i > posicao; i--){ //n
					
					swap(lo->dados, i-1, i); //1
				}
			}
			lo->dados[posicao] = e; //1
			lo->p++; //1
		
			return 1;	//1		
	}
	else{
		return 0;//1
	}
	
	//complexidade temporal -> O (11 + n + n) = O(n). linear.
}

void swap(int* v, int i, int j){ //3
	//complexidade espacial -> O (4) = O(c). constante.
	
	int aux = v[i]; //1 //1
	v[i] = v[j]; //1
	v[j] = aux; //1
	//complexidade temporal -> O (3) = O(c). constante.
	
}

int remover(ListaOrdenada* lo, int valor){ //2
	int i; //1
	
	//complexidade espacial -> O (6) = O(c). constante.
	
	if(lo != NULL){ //1
		
	for(i = 0; i < lo->p; i++){ //n
		if(lo->dados[i] == valor){ //1
			int *novoVet = (int*) malloc(lo->n* sizeof(int)); //1 //1
		
			int  j; //1
			int k = 0; //1
			for(j = 0; j < lo->n; j++){ //n
				if(valor != lo->dados[j]){ //1
					novoVet[k] = lo->dados[j]; //1
					k++; //1
				}
			}	
			lo->p--; //1
			free(lo->dados); //1
			lo->dados = novoVet; //1
		}
	}
			return 1; //1
		}else{
			return 0; //1
		}
	//complexidade temporal -> O ( 11 + n + n) = O(n). linear.

}

int size(ListaOrdenada* lo){ //1
	int i; //1
	//complexidade espacial -> O (2) = O(c). constante.
	
	if(lo->p <= lo->n) //1
		return lo->p;	//1
	//complexidade temporal -> O (2) = O(c). constante.
}

int linearSearch(ListaOrdenada* lo, int e){ //2
	int i ; //1
		
		//complexidade espacial -> O (3) = O(c). constante.
		
		if(lo != NULL){ //1
		for(i = 0; i < lo->p; i++){ //n	
			if(e == lo->dados[i]){ //1
				return i;	//1
			}
		}
		}return -1; //1

//complexidade temporal -> O (4 + n) = O(n). linear.

}

int bynarySearch(ListaOrdenada* lo, int e){ //2
	
	//complexidade espacial -> O (5) = O(c). constante.
	
	int esq = 0; //1
	int dir = lo->n; // 1 //1
	
	while(esq <= dir){ //n
		
		int meio = (esq + dir) /2; //1 //1
		
		if(lo->dados[meio] == e){ //1
			return meio; //1
		}else if(lo->dados[meio] > e){ //1
			dir = meio - 1; //1
		}else{
			esq = meio + 1; //1
		}
	}
	return -1; //1
	
	//complexidade temporal -> O (8 + n) = O(n). linear.
	
	
}

void printAll(ListaOrdenada* lo){ //1
	
	//complexidade espacial -> O (2) = O(c). constante.
	
	int i = 0; //1
	
	printf("\nLista "); //1
	
	if(lo->p > 0){ //1
		printf("["); //1
		for(i = 0 ; i < lo->n; i++){ //n
			printf("%i ", lo->dados[i]); //1
		}
		printf("]\n");	//1
	}		
	else
		printf("[ ]\n"); //1
		
//complexidade temporal -> O (6 + n) = O(n). linear.

}

int isFull(ListaOrdenada* lo){ //1
	
	//complexidade espacial -> O (1) = O(c). constante.
	
	if (lo->p <= lo->n-1 ){//1
		return 1;//1
	}else{
	return 0; //1
	}
	
	//complexidade temporal -> O (3) = O(c). constante.
}

int isEmpty(ListaOrdenada* lo){ //1

//complexidade espacial -> O (1) = O(c). constante.

	if( lo == NULL ){ //1
		return 1;//1
	}
	if(lo->p <= 0){ //1
	return 1; //1
	}else{
		return 0;//1
	}
	
	//complexidade temporal -> O (5) = O(c). constante.
	
}

void clear(ListaOrdenada* lo){ //1
	//complexidade espacial -> O (1) = O(c). constante.
	
	printf("Removendo elementos !!\n");
	if(lo != NULL){ //1
		lo->p = 0;
		free(lo->dados); //1
		free(lo); //1
		 //1
	}
	
	//complexidade temporal -> O (5) = O(c). constante.
}


