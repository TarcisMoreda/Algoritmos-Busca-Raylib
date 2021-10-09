# Conway's Game of Life com visualizacao grafica

## Resumo:
Utilizando como base o GoL no terminal publicado anteriormente, foi-se criado um programa novo utilizando-se da biblioteca raylib para criacao de janela e renderizacao das celulas, assim como uma maneira mais interativa de fazer o mapa inicial. 

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

### Compilar:
Apos instalar os requisitos mencionados e baixar o repositorio, entre na pasta build e execute o comando make, depois disso basta executar GoL.bin para utilizar.
```
git clone https://github.com/TarcisMoreda/Game-Of-Life-Raylib.git
cd Game\ Of\ Life\ Window/build
make
./GoL.bin
```

### Aviso:
Os paramentros de compilacao do arquivo make estao otimizados para ArchLinux com X11, se algo de errado acontecer durante o processo de compilacao retirar os seguintes parametros:

### Antes:
```
GoL: main.o game.o
gcc main.o game.o -o GoL.bin -lraylib -lglfw -lGL -lopenal -lm -pthread -ldl -lX11 -lXrandr -lXinerama -lXi -lXxf86vm -lXcursor
```

### Depois:
```
GoL: main.o game.o
gcc main.o game.o -o GoL.bin -lraylib -lglfw -lGL -lopenal -lm -pthread -ldl
```
