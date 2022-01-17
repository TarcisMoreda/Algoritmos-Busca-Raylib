#include "comum.h"

#if !defined(RENDERIZADOR_H)
#define RENDERIZADOR_H

int mostrar_tabuleiro(celula** tabuleiro);
int desenhar_botao(Rectangle* botao, Color cor, char texto[]);
int checar_clique(celula** tabuleiro);
int checar_entrada(celula** tabuleiro);

#endif // RENDERIZADOR_H
