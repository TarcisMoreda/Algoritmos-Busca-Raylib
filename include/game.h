#include "comum.h"
#include "pilha.h"
#include "fila.h"

#if !defined(GAME_H)
#define GAME_H



celula** criar_tabuleiro();
dados** criar_caminho();
int busca_profundidade(celula** tabuleiro, pilha* pi, dados** caminho, bool* estado_jogos);
int busca_largura(celula** tabuleiro, fila* fi, dados** caminho, bool* estado_jogos);
int resetar_tabuleiro(celula** tabuleiro);
int carregar_arquivo(celula** tabuleiro);
int limpar_memoria_tabuleiro(celula** tabuleiro);
int limpar_memoria_caminho(dados** caminho);

#endif // GAME_H