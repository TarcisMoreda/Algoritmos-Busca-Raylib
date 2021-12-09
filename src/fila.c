#include "../include/fila.h"
#include <stdlib.h>

//Cria uma fila vazia
fila* criar_fila(){
    fila* fi = NULL;
    fi = (fila*) malloc(sizeof(fila));

    fi->inicio = NULL;
	fi->fim = NULL;

    return fi;
}

//Insere um dado na fila
int insere_fila(fila* fi, dados coordenada){
    if (fi == NULL) return 0;

	elemento* novo = (elemento*) malloc(sizeof(elemento));
	novo->coordenada = coordenada;
	novo->proximo = NULL;

	if (fi->inicio == NULL) fi->inicio = novo;
	else fi->fim->proximo = novo;
	fi->fim = novo;

    return 1;
}

//Remove o topo da fila
int remove_fila(fila* fi){
    if (fi == NULL) return 0;
	if (fi->inicio == NULL) return 0;

	elemento* aux = fi->inicio;
	fi->inicio = fi->inicio->proximo;

	if (fi->inicio == NULL) fi->fim = NULL;

	free(aux);
    return 1;
}

int checar_valor_fila(fila* fi, dados coordenada){
    if (fi == NULL) return 0;
	if (fi->inicio == NULL) return 0;

	elemento* aux = fi->inicio;
	while (aux != NULL){
		if (aux->coordenada.x == coordenada.x && aux->coordenada.y == coordenada.y) 
		return 1;
		
		aux = aux->proximo;
	}

    return 0;
}

//Remove todos os dados da fila
int limpar_fila(fila* fi){
    if (fi == NULL) return 0;
	if (fi->inicio == NULL) return 0;

	elemento* aux = fi->inicio;
	elemento* aux2 = NULL;

	while (aux != NULL){
		aux2 = aux->proximo;
		free(aux);
		aux = aux2;
	}

	fi->inicio = NULL;
	fi->fim = NULL;

    return 1;
}

//Limpa a memoria da fila
int limpar_memoria_fila(fila* fi){
    if (fi == NULL) return 0;
	if (fi->inicio == NULL) return 0;

	limpar_fila(fi);
	free(fi);

    return 1;
}