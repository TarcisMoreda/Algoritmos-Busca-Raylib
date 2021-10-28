#if !defined(PILHA_H)
#define PILHA_H

typedef struct{
    int x;
    int y;
} dados;

typedef struct elemento{
    dados coordenada;
    struct elemento* proximo;
} elemento;

typedef elemento* pilha;

pilha* criar_pilha();
int insere_pilha(pilha* pi, dados coordenada);
int remove_pilha(pilha* pi);
int checar_valor_pilha(pilha* pi, dados coordenada);
int limpar_pilha(pilha* pi);
int limpar_memoria_pilha(pilha* pi);

#endif // PILHA_H
