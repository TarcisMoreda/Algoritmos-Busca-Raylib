#include "../include/renderizador.h"

int offset_x = 0;
int offset_y = 0;
int alt = 0;

//Desenha o tabuleiro na tela
int mostrar_tabuleiro(celula** tabuleiro){
    if (tabuleiro == NULL) return 0;

    for (int y=offset_y; y<linhas_tela+offset_y; ++y)
    for (int x=offset_x; x<colunas_tela+offset_x; ++x){
        tabuleiro[x][y].rect.x = (tamanho_celula*x)-(tamanho_celula*offset_x);
        tabuleiro[x][y].rect.y = (tamanho_celula*y)-(tamanho_celula*offset_y);
    }

    for (int y=offset_y; y<linhas_tela+offset_y; ++y){
        for (int x=offset_x; x<colunas_tela+offset_x; ++x){
            switch (tabuleiro[x][y].estado){
                case inicio:
                DrawRectangleRec(tabuleiro[x][y].rect, GREEN);
                break;

                case vazio:
                DrawRectangleRec(tabuleiro[x][y].rect, WHITE);
                break;

                case parede:
                DrawRectangleRec(tabuleiro[x][y].rect, BLACK);
                break;

                case checado:
                DrawRectangleRec(tabuleiro[x][y].rect, WHITE);
                break;

                case finalizado:
                DrawRectangleRec(tabuleiro[x][y].rect, RED);
                break;

                case destino:
                DrawRectangleRec(tabuleiro[x][y].rect, GOLD);
                break;

                case caminho:
                DrawRectangleRec(tabuleiro[x][y].rect, BLUE);
                break;

                default:
                break;
            }            
        }
    }

    for (int x=0; x<colunas_tela+1; ++x)
    DrawLine(x*tamanho_celula, 0, x*tamanho_celula, linhas_tela*tamanho_celula, BLACK);
    for (int y=0; y<linhas_tela+1; ++y)
    DrawLine(0, y*tamanho_celula, colunas_tela*tamanho_celula, y*tamanho_celula, BLACK);

    return 1;
}

int desenhar_botao(Rectangle* botao, Color cor, char texto[]){
    if (botao == NULL) return 0;

    DrawRectangleRec(*botao, cor);
    DrawText(texto, (*botao).x+10, (*botao).y+5, tamanho_fonte, BLACK);
    DrawRectangleLines((*botao).x, (*botao).y, (*botao).x+(*botao).width, (*botao).y+(*botao).height, BLACK);

    return 1;
}

//Checa por clique em celula do tabuleiro e muda seu estado dependendo do estado de alteracao
int checar_clique(celula** tabuleiro){
    if (tabuleiro == NULL) return 0;

    if (IsKeyReleased(KEY_SPACE)) alt = !alt;

    for (int y=offset_y; y<linhas_tela+offset_y; ++y)
    for (int x=offset_x; x<colunas_tela+offset_x; ++x){
        int estado_switch = (tabuleiro[x][y].estado == vazio || tabuleiro[x][y].estado == checado || tabuleiro[x][y].estado == finalizado || tabuleiro[x][y].estado == caminho);

        if (CheckCollisionPointRec(GetMousePosition(), tabuleiro[x][y].rect) && IsMouseButtonDown(MOUSE_LEFT_BUTTON) && !alt && estado_switch)
        tabuleiro[x][y].estado = parede;

        if (CheckCollisionPointRec(GetMousePosition(), tabuleiro[x][y].rect) && IsMouseButtonDown(MOUSE_RIGHT_BUTTON) && !alt)
        switch (tabuleiro[x][y].estado){
            case parede:
            tabuleiro[x][y].estado = vazio;
            break;

            default:
            break;
        }

        if (CheckCollisionPointRec(GetMousePosition(), tabuleiro[x][y].rect) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON) && alt){
            if (tabuleiro[x][y].estado == inicio) tabuleiro[x][y].estado = vazio;
            else if (estado_switch){
                for (int y1=0; y1<linhas; y1++)
                for (int x1=0; x1<colunas; x1++){
                    if (tabuleiro[x1][y1].estado == inicio)
                    tabuleiro[x1][y1].estado = vazio;
                    if (tabuleiro[x1][y1].estado == checado || tabuleiro[x1][y1].estado == finalizado || tabuleiro[x1][y1].estado == caminho)
                    tabuleiro[x1][y1].estado = vazio;
                }

                tabuleiro[x][y].estado = inicio;
            }
        }

        if (CheckCollisionPointRec(GetMousePosition(), tabuleiro[x][y].rect) && IsMouseButtonReleased(MOUSE_RIGHT_BUTTON) && alt){
            if (tabuleiro[x][y].estado == destino) tabuleiro[x][y].estado = vazio;
            else if (estado_switch){
                for (int x1=0; x1<colunas; x1++) 
                for (int y1=0; y1<linhas; y1++){
                    if (tabuleiro[x1][y1].estado == destino)
                    tabuleiro[x1][y1].estado = vazio;
                    if (tabuleiro[x1][y1].estado == checado || tabuleiro[x1][y1].estado == finalizado || tabuleiro[x1][y1].estado == caminho)
                    tabuleiro[x1][y1].estado = vazio;
                } 

                tabuleiro[x][y].estado = destino;
            }
        }
    }

    return 1;
}

//Checa pelas entradas do teclado para mover o tabuleiro
int checar_entrada(celula** tabuleiro){
    if (tabuleiro == NULL) return 0;

    if (IsKeyDown(KEY_LEFT) && offset_x>0) --offset_x;
    else if (IsKeyDown(KEY_RIGHT) && offset_x<colunas) ++offset_x;

    if (IsKeyDown(KEY_UP) && offset_y>0) --offset_y;
    else if (IsKeyDown(KEY_DOWN) && offset_y<linhas) ++offset_y;

    return 1;
}