#include "comum.h"

#if !defined(FILA_H)
#define FILA_H

typedef struct fila{
	elemento* inicio;
	elemento* fim;
} fila;

fila* criar_fila();
int insere_fila(fila* fi, dados coordenada);
int remove_fila(fila* fi);
int checar_valor_fila(fila* fi, dados coordenada);
int limpar_fila(fila* fi);
int limpar_memoria_fila(fila* fi);

#endif // FILA_H