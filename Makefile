CC=g++
CFLAGS= -Wall -std=c++11 -O3
LDFLAGS=
EXEC=mek
SRC= $(wildcard *.cpp)
HEAD= $(wildcard *.h)
OBJ= $(SRC:.cpp=.o)

all: $(EXEC)

mek: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp $(HEAD)
	$(CC) -o $@ -c $<

.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)