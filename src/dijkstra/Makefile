TARGET=dijkstra.bin
ALG=dijkstra.cpp
ALG_HEADER=dijkstra.h
OBJ=dijkstra.o
CXX=g++-12

dijkstra.bin: $(OBJ) graphs.o
	$(CXX) -o $(TARGET) main.cpp dijkstra.o graphs.o

graphs.o: ../graphs.cpp ../graphs.h
	$(CXX) -c ../graphs.cpp

dijkstra.o: $(ALG) $(ALG_HEADER) graphs.o
	$(CXX) -c $(ALG) graphs.o
	
clean:
	rm $(TARGET)
	rm $(OBJ)
	rm graphs.o
