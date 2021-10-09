#include <raylib.h>
#include <stdio.h>
#include "pilha.h"

#if !defined(GAME_H)
#define GAME_H

//Definindo constantes que podem ser alteradas para uma experiencia diferente
#define largura_janela 1200
#define altura_janela 950
#define tamanho_celula 16
#define colunas 200
#define linhas 200
#define colunas_tela ((int) largura_janela/tamanho_celula)
#define linhas_tela ((int) (altura_janela-50)/tamanho_celula)
#define fps 60
#define geracoes_por_segundo 10
#define frames_por_passo ((int) fps/geracoes_por_segundo)

//definindo os estados de uma celula
enum{inicio, vazio, parede, checado, destino};

typedef struct{
    Rectangle rect;
    int estado;
} celula;

celula** criar_tabuleiro();
int checar_vizinhos(celula** tabuleiro, int x, int y);
int passo_jogo(celula** tabuleiro, pilha* pi, bool* estado_jogos);
int mostrar_tabuleiro(celula** tabuleiro);
int resetar_tabuleiro(celula** tabuleiro);
int carregar_arquivo(celula** tabuleiro);
int checar_clique(celula** tabuleiro);
int checar_entrada(celula** tabuleiro);
int limpar_memoria_tabuleiro(celula** tabuleiro);

#endif // GAME_H
