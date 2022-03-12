CC = g++
CFLAGS = -std=c++14 -c -g -Og -Wall -Werror -pedantic 
OBJ = Triangle.o TFractal.o
DEPS = 
LIBS = -lsfml-system -lsfml-audio -lsfml-graphics -lsfml-window
EXE = TFractal

all: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm $(OBJ) $(EXE)
