#include "../include/game.h"

//Funcao aloca memoria para o tabuleiro e preenche os dados de acordo
celula** criar_tabuleiro(){
    celula** tabuleiro = NULL;
    tabuleiro = (celula**) malloc(sizeof(celula*)*colunas);
    for (int x=0; x<colunas; x++) tabuleiro[x] = (celula*) malloc(sizeof(celula)*linhas);

    for (int y=0; y<linhas; y++)
    for (int x=0; x<colunas; x++){
        tabuleiro[x][y].rect.x = tamanho_celula*x;
        tabuleiro[x][y].rect.y = tamanho_celula*y;
        tabuleiro[x][y].rect.width = tamanho_celula;
        tabuleiro[x][y].rect.height = tamanho_celula;
        tabuleiro[x][y].estado = vazio;
    }

    return tabuleiro;
}

dados** criar_caminho(){
    dados** caminho_dados = NULL;
    caminho_dados = (dados**) malloc(sizeof(dados*)*colunas);
    for (int x=0; x<colunas; x++) caminho_dados[x] = (dados*) malloc(sizeof(dados)*linhas);

    for (int y=0; y<linhas; y++)
    for (int x=0; x<colunas; x++){
        caminho_dados[x][y].x = 0;
        caminho_dados[x][y].y = 0;
    }

    return caminho_dados;
}

//Aplica o algoritmo de busca em profundidade e muda os estados de todas as celulas de acordo
int busca_profundidade(celula** tabuleiro, pilha* pi, dados** caminho_dados, bool* estado_jogo){
    if (tabuleiro == NULL) return 0;
    if (caminho_dados == NULL) return 0;
    if (pi == NULL) return 0;

    dados atual;
    dados coord;
    
    if (*pi == NULL){
        for (int y=0; y<linhas; y++)
        for (int x=0; x<colunas; x++) 
        if (tabuleiro[x][y].estado == inicio){
            atual.x = x;
            atual.y = y;
            break;
        }

        insere_pilha(pi, atual);
    }

    atual = (*pi)->coordenada;
    remove_pilha(pi);
    
    if (tabuleiro[atual.x][atual.y].estado == destino) {
        coord = caminho_dados[atual.x][atual.y];
        atual = coord;

        while(tabuleiro[atual.x][atual.y].estado != inicio){
            tabuleiro[atual.x][atual.y].estado = caminho;

            coord = caminho_dados[atual.x][atual.y];
            atual = coord;
        }

        limpar_pilha(pi);
        *estado_jogo = false;
        return 1;
    }
    
    for (int i=-1; i<=1; ++i)
    for (int j=-1; j<=1; ++j){
        if (i == 0 && j == 0) continue;
        if (atual.x+i == -1 || atual.y+j == -1) continue;
        if (atual.x+i == colunas || atual.y+j == linhas) continue;
        if ((i == -1 && j == 1) || (i == 1 && j == 1) || (i == -1 && j == -1) || (i == 1 && j == -1)) continue;
        
        if (tabuleiro[atual.x+i][atual.y+j].estado != finalizado
        && tabuleiro[atual.x+i][atual.y+j].estado != checado
        && tabuleiro[atual.x+i][atual.y+j].estado != parede
        && tabuleiro[atual.x+i][atual.y+j].estado != inicio){
            coord.x = atual.x+i;
            coord.y = atual.y+j;
            caminho_dados[coord.x][coord.y].x = atual.x;
            caminho_dados[coord.x][coord.y].y = atual.y;
            insere_pilha(pi, coord);
            
            if (tabuleiro[coord.x][coord.y].estado != destino)
            tabuleiro[coord.x][coord.y].estado = checado;
        }
    }
    if (tabuleiro[atual.x][atual.y].estado == checado) tabuleiro[atual.x][atual.y].estado = finalizado;

    return 1;
}

//Aplica o algoritmo de busca em largura e muda os estados de todas as celulas de acordo
int busca_largura(celula** tabuleiro, fila* fi, dados** caminho_dados, bool* estado_jogo){
    if (tabuleiro == NULL) return 0;
    if (caminho_dados == NULL) return 0;
    if (fi == NULL) return 0;

    dados atual;
    dados coord;
    
    if ((*fi).inicio == NULL){
        for (int y=0; y<linhas; y++)
        for (int x=0; x<colunas; x++) 
        if (tabuleiro[x][y].estado == inicio){
            atual.x = x;
            atual.y = y;
            break;
        }

        insere_fila(fi, atual);
    }

    atual = (*fi).inicio->coordenada;
    remove_fila(fi);
    
    if (tabuleiro[atual.x][atual.y].estado == destino) {
        coord = caminho_dados[atual.x][atual.y];
        atual = coord;

        while(tabuleiro[atual.x][atual.y].estado != inicio){
            tabuleiro[atual.x][atual.y].estado = caminho;

            coord = caminho_dados[atual.x][atual.y];
            atual = coord;
        }

        limpar_fila(fi);
        *estado_jogo = false;
        return 1;
    }
    
    for (int i=-1; i<=1; ++i)
    for (int j=-1; j<=1; ++j){
        if (i == 0 && j == 0) continue;
        if (atual.x+i == -1 || atual.y+j == -1) continue;
        if (atual.x+i == colunas || atual.y+j == linhas) continue;
        if ((i == -1 && j == 1) || (i == 1 && j == 1) || (i == -1 && j == -1) || (i == 1 && j == -1)) continue;
        
        if (tabuleiro[atual.x+i][atual.y+j].estado != finalizado
        && tabuleiro[atual.x+i][atual.y+j].estado != checado
        && tabuleiro[atual.x+i][atual.y+j].estado != parede
        && tabuleiro[atual.x+i][atual.y+j].estado != inicio){
            coord.x = atual.x+i;
            coord.y = atual.y+j;
            caminho_dados[coord.x][coord.y].x = atual.x;
            caminho_dados[coord.x][coord.y].y = atual.y;
            insere_fila(fi, coord);
            
            if (tabuleiro[coord.x][coord.y].estado != destino)
            tabuleiro[coord.x][coord.y].estado = checado;
        }
    }
    if (tabuleiro[atual.x][atual.y].estado == checado) tabuleiro[atual.x][atual.y].estado = finalizado;

    return 1;
}

//Reseta o estado de todas as celulas para morta
int resetar_tabuleiro(celula** tabuleiro){
    if (tabuleiro == NULL) return 0;

    for (int y=0; y<linhas; y++)
    for (int x=0; x<colunas; x++)
    tabuleiro[x][y].estado = vazio;

    return 1;
}

//Carrega um arquivo .txt com as instrucoes para criar o mapa
int carregar_arquivo(celula** tabuleiro){
    FILE* arquivo;
    char local[100];
    char leitura;
    dados tamanho;

    printf("Insira o local do arquivo:\n");
    scanf("%s", local);
    arquivo = fopen(local, "r");
    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }
    printf("Insira o tamanho do mapa (tanto largura quanto altura):\n");
    scanf("%d %d", &tamanho.x, &tamanho.y);

    for (int y=0; y<tamanho.y; ++y)
    for (int x=0; x<tamanho.x; ++x){
        fscanf(arquivo, "%c", &leitura);

        if (leitura == '.') tabuleiro[x][y].estado = vazio;
        if (leitura == '#') tabuleiro[x][y].estado = parede;
        if (leitura == 'H') tabuleiro[x][y].estado = inicio;
        if (leitura == 'D') tabuleiro[x][y].estado = destino;
    }

    for (int y=0; y<tamanho.y+1; ++y) tabuleiro[tamanho.x][y].estado = parede;
    for (int x=0; x<tamanho.x+1; ++x) tabuleiro[x][tamanho.x].estado = parede;

    fclose(arquivo);
    return 1;
}

//Limpa a memoria do tabuleiro
int limpar_memoria_tabuleiro(celula** tabuleiro){
    if (tabuleiro == NULL) return 0;
    
    for (int x=0; x<colunas; x++) free(tabuleiro[x]);
    free(tabuleiro);

    return 1;
}

//Limpa a memoria do caminho
int limpar_memoria_caminho(dados** caminho_dados){
    if (caminho_dados == NULL) return 0;
    
    for (int x=0; x<colunas; x++) free(caminho_dados[x]);
    free(caminho_dados);

    return 1;
}