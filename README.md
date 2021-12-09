# Busca em Profundidade com visualização grafica

## Resumo:
Trabalho de Teoria dos Grafos, utilizando como base o Game of Life anteriormente feito, foi-se criada uma interface grafica.

## Instrucoes:
Instale o make e raylib.

### Arch:
```
sudo pacman -S make
sudo pacman -S raylib
``` 

### Outras distribuicoes:
https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux

### Windows:
https://github.com/raysan5/raylib/wiki/Working-on-Windows

## Compilar:
Apos instalar os requisitos mencionados e baixar o repositorio, entre na pasta build e execute o comando make, depois disso basta executar BuscaProfundidade.bin para utilizar.
```
git clone https://github.com/TarcisMoreda/Busca-em-Profundidade-Raylib.git
cd Busca\ Em\ Profundidade\ Raylib/build
make
./Busca.bin
```

## Controles:
### Espaco:
Altera as funcoes dos botoes do mouse.
### LMB:
Parede/inicio
### RMB:
Borracha/Destino

## Aviso:
Os parâmetros de compilacao do arquivo make estao otimizados para ArchLinux com X11, se algo de errado acontecer durante o processo de compilacao retirar os seguintes parametros:

### Antes:
```
busca: main.o game.o pilha.o
	gcc main.o game.o pilha.o -o BuscaProfundidade.bin -lraylib -lglfw -lGL -lopenal -lm -pthread -ldl -lX11 -lXrandr -lXinerama -lXi -lXxf86vm -lXcursor
```

### Depois:
```
busca: main.o game.o pilha.o
	gcc main.o game.o pilha.o -o BuscaProfundidade.bin -lraylib -lglfw -lGL -lopenal -lm -pthread -ldl
```
