TARGET=../../bin/kruskal.bin
ALG=kruskal.cpp
ALG_HEADER=kruskal.h
OBJ=kruskal.o
CXX=g++-12

../../bin/kruskal.bin: $(OBJ) graphs.o main.cpp
	$(CXX) -g -o $(TARGET) main.cpp $(OBJ) graphs.o

graphs.o: ../graphs.cpp ../graphs.h
	$(CXX) -c ../graphs.cpp

$(OBJ): $(ALG) $(ALG_HEADER) graphs.o
	$(CXX) -c $(ALG) graphs.o
	
clean:
	rm $(TARGET)
	rm $(OBJ)
	rm graphs.o
	clear

test:
	./$(TARGET) -f ../../tests/Bat1/instances/exemp.mtx

debug:
	gdb ./$(TARGET) -f ../../tests/Bat1/instances/exemp.mtx

