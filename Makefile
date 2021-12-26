﻿CC=g++
CCFLAGS=-Wall -Werror -std=c++11 -g
LIBFLAGS=-lsfml-graphics -lsfml-window -lsfml-system -lm
SRC_DIR=src
SRC=$(wildcard $(SRC_DIR)/pbPlots/*.cpp) $(wildcard $(SRC_DIR)/*.cpp)
OBJ=$(SRC:.cpp=.o)
TST_DIR=tests
TST=$(wildcard $(TST_DIR)/*.cpp)
OBJ_TEST=$(filter-out $(SRC_DIR)/main.o, $(OBJ)) $(TST:.cpp=.o)
EXEC=game

all: $(EXEC)


testcase:
	cd $(TST_DIR) ; make


$(EXEC): $(OBJ)
	$(CC) $^ $(LIBFLAGS) -o $@

$(SRC_DIR)/pbPlots/%.o: $(SRC_DIR)/pbPlots/%.cpp
	$(CC) -c $< -o $@

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $< -o $@

.depend: $(SRC)
	$(CC) $(CCFLAGS) -MM $(SRC) > .depend

-include .depend

clean:
	rm -f $(OBJ) $(EXEC) .depend plot/resultat.png

cleantest:
	cd $(TST_DIR) ; make clean

distclean: clean cleantest