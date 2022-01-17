GCC=gcc
CFLAGS=-g -Wall
LIBS=-lraylib -lGL -lm -lpthread -ldl -lrt -lX11

SRC=../src
INC=../include
OBJ=obj
SRCS=$(wildcard $(SRC)/*.c)
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
HDRS=$(wildcard $(INC)/*.h)
BIN=AlgBusca

all: $(BIN)

$(BIN): $(OBJS) $(OBJ)
	$(GCC) $(CFLAGS) $(OBJS) -o $(BIN) $(LIBS)

$(OBJ)/%.o: $(SRC)/%.c $(OBJ)
	$(GCC) $(CFLAGS) -c $< -o $@

$(OBJ):
	mkdir -p $@

clean:
	$(RM) -r $(OBJ)
	$(RM) $(BIN)