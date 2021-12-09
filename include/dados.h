#if !defined(DADOS_H)
#define DADOS_H

typedef struct{
    int x;
    int y;
} dados;

typedef struct elemento{
    dados coordenada;
    struct elemento* proximo;
} elemento;

#endif // DADOS_H
