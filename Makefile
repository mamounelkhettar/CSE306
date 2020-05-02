CC=g++
CFLAGS= -std=c++17 
LDFLAGS= 
EXEC=mek
SRC= $(wildcard *.cpp)
HEAD= $(wildcard *.h)
OBJ= $(SRC:.cpp=.o)

all: $(EXEC)

mek: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp $(HEAD)
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)