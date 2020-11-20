#include <stdio.h>
#include <stdlib.h>
#include "listaOrdenada.h"


int main() {
	
	ListaOrdenada* lista = create(10);
	

	add(lista, 9);
	add(lista, 8);
	add(lista, 7);
	add(lista, 6);
	add(lista, 5);
	add(lista, 4);
	add(lista, 3);
	add(lista, 2);
	add(lista, 1);
	
	printAll(lista);
	
	printf("\nRetorna 1 se removeu o elemento informado: %i \n", remover(lista, 6));
	
	printAll(lista);
	
	printf("\nTamanho : %i \n\n", size(lista));
	
	printf("Busca sequencial. Retorna -1 ou indice do elemento : %i \n\n", linearSearch(lista, 8));
	
	printf("Busca binaria. Retorna -1 ou indice do elemento : %i \n\n", bynarySearch(lista, 5));
	
	printf("Retorna 1 se a Lista esta cheia e 0 para o caso oposto: %d\n\n", isFull(lista));
	
	printf("Retorna 1 se a Lista esta vazia e 0 para o caso oposto: %d\n\n", isEmpty(lista));
	
	 clear(lista);
	
	printAll(lista);
	
	return 0;
}
