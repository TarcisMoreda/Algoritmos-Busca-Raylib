busca: main.o game.o pilha.o fila.o
	gcc main.o game.o pilha.o fila.o -o BuscaProfundidade.bin -lraylib -lglfw -lGL -lopenal -lm -pthread -ldl -lX11 -lXrandr -lXinerama -lXi -lXxf86vm -lXcursor

main.o: ../src/main.c ../include/game.h
	gcc -c ../src/main.c

game.o: ../src/game.c ../include/game.h
	gcc -c ../src/game.c

pilha.o: ../src/pilha.c ../include/pilha.h ../include/dados.h
	gcc -c ../src/pilha.c

fila.o: ../src/fila.c ../include/fila.h ../include/dados.h
	gcc -c ../src/fila.c

clean:
	rm *.o BuscaProfundidade.bin