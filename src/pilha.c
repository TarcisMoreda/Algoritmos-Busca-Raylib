#include "../include/pilha.h"
#include <stdlib.h>

//Cria uma pilha vazia
pilha* criar_pilha(){
    pilha* pi = NULL;
    pi = (pilha*) malloc(sizeof(pilha));

    *pi = NULL;

    return pi;
}

//Insere um dado na pilha
int insere_pilha(pilha* pi, dados coordenada){
    if (pi == NULL) return 0;

    elemento* elem = (elemento*) malloc(sizeof(elemento));
    elem->coordenada = coordenada;
    elem->proximo = (*pi);

    *pi = elem;

    return 1;
}

//Remove o topo daa pilha
int remove_pilha(pilha* pi){
    if(pi == NULL) return 0;
    if((*pi) == NULL) return 0;

    elemento* no = *pi;
    *pi = no->proximo;
    free(no);

    return 1;
}

//Remove todos os dados da pilha
int limpar_pilha(pilha* pi){
    if(pi == NULL) return 0;
    if((*pi) == NULL) return 0;

    elemento* no;
    while ((*pi) != NULL){
        no = *pi;
        *pi = no->proximo;
        free(no);
    }

    return 1;
}

//Limpa a memoria da pilha
int limpar_memoria_pilha(pilha* pi){
    if (pi == NULL) return 0;

    elemento* no;
    while ((*pi) != NULL){
        no = *pi;
        *pi = no->proximo;
        free(no);
    }
    free(pi);

    return 1;
}