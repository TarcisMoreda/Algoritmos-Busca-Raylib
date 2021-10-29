#include "../include/game.h"

int main(int argc, char const *argv[]){
    //Alocando toda a memoria nescessaria para o jogo funcionar
    celula** tabuleiro = criar_tabuleiro();
    dados** caminho_dados = criar_caminho();
    pilha* pi = criar_pilha();

    //Variaveis para a logica do jogo
    bool estado_jogo = false;
    bool inicio = false;
    bool destino = false;
    bool carregando_arquivo = false;
    int frame_atual = 0;
    char str_passo[50];
    int passo = 0;

    //Criando os botoes
    Rectangle botao_iniciar;
    botao_iniciar.x = 0;
    botao_iniciar.y = linhas_tela*tamanho_celula;
    botao_iniciar.width = 200;
    botao_iniciar.height = altura_janela;
    Rectangle botao_limpar;
    botao_limpar.x = largura_janela-200;
    botao_limpar.y = linhas_tela*tamanho_celula;
    botao_limpar.width = 200;
    botao_limpar.height = altura_janela;

    Rectangle botao_arquivo;
    botao_arquivo.x = botao_limpar.x-300;
    botao_arquivo.y = linhas_tela*tamanho_celula;
    botao_arquivo.width = 300;
    botao_arquivo.height = altura_janela;

    //Iniciando a janela e configurando
    InitWindow(largura_janela, altura_janela, "Busca em Profundidade");
    SetTargetFPS(fps);

    //Loop principal do jogo
    while (!WindowShouldClose()){
        //Logica do input
        if (!estado_jogo) checar_clique(tabuleiro);
        checar_entrada(tabuleiro);

        //Logica dos botoes
        if (CheckCollisionPointRec(GetMousePosition(), botao_iniciar) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON) && !carregando_arquivo){
            inicio = false;
            destino = false;
            if (!estado_jogo){
                for (int y=0; y<linhas; y++)
                for (int x=0; x<colunas; x++){
                    if (tabuleiro[x][y].estado == inicio) inicio = true;
                    if (tabuleiro[x][y].estado == destino) destino = true;
                }
            }
            if (estado_jogo) estado_jogo = false;
            else if (*pi != NULL && inicio && destino){
                for (int y=0; y<linhas; y++)
                for (int x=0; x<colunas; x++)
                if (tabuleiro[x][y].estado == checado || tabuleiro[x][y].estado == finalizado || tabuleiro[x][y].estado == caminho)
                tabuleiro[x][y].estado = vazio;
                
                limpar_pilha(pi);
                passo = 0;
                estado_jogo = true;
            }
            else if (*pi != NULL && destino) estado_jogo = true; 
            else if (inicio && destino) estado_jogo = true;
        }

        if (CheckCollisionPointRec(GetMousePosition(), botao_limpar) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON) && !estado_jogo && !carregando_arquivo){
            resetar_tabuleiro(tabuleiro);
            limpar_pilha(pi);
            passo = 0;
        }

        if (CheckCollisionPointRec(GetMousePosition(), botao_arquivo) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON) && !estado_jogo && !carregando_arquivo){
            carregando_arquivo = true;
            resetar_tabuleiro(tabuleiro);
            limpar_pilha(pi);
            carregar_arquivo(tabuleiro);
            passo = 0;
            carregando_arquivo = false;
        }

        //Condicao para o proximo passo
        if (frame_atual%frames_por_passo == 0 && estado_jogo){
            busca_profundidade(tabuleiro, pi, caminho_dados, &estado_jogo);
            if (*pi == NULL) estado_jogo = false;
            else ++passo;
        }

        //Concatenando str dos passos
        snprintf(str_passo, 50, "Passos: %d", passo);

        BeginDrawing();
        ClearBackground(GRAY);

        mostrar_tabuleiro(tabuleiro);

        //Logica para a mudanca de cor e texto do botao botao_iniciar
        if (!estado_jogo) {
            DrawRectangleRec(botao_iniciar, LIME);
            DrawText("Iniciar", botao_iniciar.x+10, botao_iniciar.y+5, altura_janela-botao_iniciar.y, WHITE);
        }
        else{
            DrawRectangleRec(botao_iniciar, RED);
            DrawText("Parar", botao_iniciar.x+10, botao_iniciar.y+5, altura_janela-botao_iniciar.y, WHITE);
        }

        DrawRectangleRec(botao_limpar, BROWN);
        DrawText("Limpar", botao_limpar.x+20, botao_limpar.y+5, altura_janela-botao_limpar.y, WHITE);

        DrawRectangleRec(botao_arquivo, GOLD);
        DrawText("Carregar", botao_arquivo.x+20, botao_arquivo.y+5, altura_janela-botao_arquivo.y, WHITE);

        DrawText(str_passo, botao_iniciar.width+10, botao_iniciar.y+5, altura_janela-botao_limpar.y, WHITE);

        EndDrawing();
        if (estado_jogo) ++frame_atual;
    }

    //Limpando memoria e finalizando raylib
    limpar_memoria_pilha(pi);
    limpar_memoria_caminho(caminho_dados);
    limpar_memoria_tabuleiro(tabuleiro);
    CloseWindow();

    return 0;
}