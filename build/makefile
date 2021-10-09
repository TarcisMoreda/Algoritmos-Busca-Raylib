GoL: main.o game.o pilha.o
	gcc main.o game.o pilha.o -o BuscaProfundidade.bin -lraylib -lglfw -lGL -lopenal -lm -pthread -ldl -lX11 -lXrandr -lXinerama -lXi -lXxf86vm -lXcursor

main.o: ../src/main.c ../include/game.h
	gcc -c ../src/main.c

game.o: ../src/game.c ../include/game.h
	gcc -c ../src/game.c

pilha.o: ../src/pilha.c ../include/pilha.h
	gcc -c ../src/pilha.c

clean:
	rm *.o BuscaProfundidade.bin