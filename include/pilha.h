#include "dados.h"
#if !defined(PILHA_H)
#define PILHA_H

typedef elemento* pilha;

pilha* criar_pilha();
int insere_pilha(pilha* pi, dados coordenada);
int remove_pilha(pilha* pi);
int checar_valor_pilha(pilha* pi, dados coordenada);
int limpar_pilha(pilha* pi);
int limpar_memoria_pilha(pilha* pi);

#endif // PILHA_H
