#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

#if !defined(COMUM_H)
#define COMUM_H

//Definindo constantes importantes
#define largura_janela 1200
#define altura_janela 950
#define tamanho_celula 24
#define colunas 300
#define linhas 300
#define colunas_tela ((int) (largura_janela-50)/tamanho_celula)
#define linhas_tela ((int) (altura_janela-50)/tamanho_celula)
#define fps 60
#define passos_por_segundo 10 //Deve ser menor ou igual ao fps
#define frames_por_passo ((int) fps/passos_por_segundo)
#define tamanho_fonte 50

//definindo os estados de uma celula
enum{inicio, vazio, parede, checado, finalizado, caminho, destino};

typedef struct{
    Rectangle rect;
    int estado;
} celula;

typedef struct{
    int x;
    int y;
} dados;

typedef struct elemento{
    dados coordenada;
    struct elemento* proximo;
} elemento;

#endif // COMUM_H
