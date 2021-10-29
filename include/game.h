#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

#if !defined(GAME_H)
#define GAME_H

//Definindo constantes que podem ser alteradas para uma experiencia diferente
#define largura_janela 1200
#define altura_janela 950
#define tamanho_celula 24
#define colunas 300
#define linhas 300
#define colunas_tela ((int) largura_janela/tamanho_celula)
#define linhas_tela ((int) (altura_janela-50)/tamanho_celula)
#define fps 60
#define passos_por_segundo 10 //Deve ser menor ou igual ao fps
#define frames_por_passo ((int) fps/passos_por_segundo)

//definindo os estados de uma celula
enum{inicio, vazio, parede, checado, finalizado, caminho, destino};

typedef struct{
    Rectangle rect;
    int estado;
} celula;

celula** criar_tabuleiro();
dados** criar_caminho();
int checar_vizinhos(celula** tabuleiro, int x, int y);
int busca_profundidade(celula** tabuleiro, pilha* pi, dados** caminho, bool* estado_jogos);
int mostrar_tabuleiro(celula** tabuleiro);
int resetar_tabuleiro(celula** tabuleiro);
int carregar_arquivo(celula** tabuleiro);
int checar_clique(celula** tabuleiro);
int checar_entrada(celula** tabuleiro);
int limpar_memoria_tabuleiro(celula** tabuleiro);
int limpar_memoria_caminho(dados** caminho);

#endif // GAME_H