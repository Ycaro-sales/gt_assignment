TARGET=../../bin/kosaraju.bin
ALG=kosaraju.cpp
ALG_HEADER=kosaraju.h
OBJ=kosaraju.o
CXX=g++-12

../../bin/kosaraju.bin: $(OBJ) graphs.o
	$(CXX) -o $(TARGET) main.cpp $(OBJ) graphs.o

graphs.o: ../graphs.cpp ../graphs.h
	$(CXX) -c ../graphs.cpp

$(OBJ): $(ALG) $(ALG_HEADER) graphs.o
	$(CXX) -c $(ALG) graphs.o
	
clean:
	rm $(TARGET)
	rm $(OBJ)
	rm graphs.o
	clear
