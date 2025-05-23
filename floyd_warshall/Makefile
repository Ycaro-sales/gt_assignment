INST_DIR = ./instances/

BIN=bin

TARGET_EXEC = $(shell basename $(CURDIR))

SRCS := $(wildcard src/*.cpp)
OBJS := $(foreach o, $(SRCS), $(shell basename $(o)).o)
CXX=g++

$(BIN)/$(TARGET_EXEC): $(foreach o,$(OBJS), $(BIN)/$(shell basename $(o)))
	echo $(foreach o,$(OBJS), $(BIN)/$(shell basename $(o)))
	$(CXX) -g -ggdb $^ -o $@

$(BIN)/%.cpp.o: src/%.cpp
	$(CXX) -g -ggdb -c $< -o $@

.PHONY: clean instances
clean:
	rm -f $(BIN)/*

run: clean $(BIN)/$(TARGET_EXEC)  
	./$(BIN)/$(TARGET_EXEC) -f .instances/instance_1.mtx

debug: clean $(BIN)/$(TARGET_EXEC)
	gdb --args ./$(BIN)/$(TARGET_EXEC) -f .instances/instance_1.mtx

instances:
	(cd ./instances && python3 ./create_weighted_graph_instance.py)
