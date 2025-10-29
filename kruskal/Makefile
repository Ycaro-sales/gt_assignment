TEST_DIR = ../tests/Bat1
TEST_SCRIPT=Bat1.sh

BIN=bin

TARGET_EXEC = $(shell basename $(CURDIR))

SRCS := $(wildcard src/*.cpp)
OBJS := $(foreach o, $(SRCS), $(shell basename $(o)).o)
CXX=g++

$(BIN)/$(TARGET_EXEC): $(foreach o,$(OBJS), $(BIN)/$(shell basename $(o)))
	echo $(foreach o,$(OBJS), $(BIN)/$(shell basename $(o)))
	$(CXX) -g -ggdb $^ -o $@

$(BIN)/%.cpp.o: src/%.cpp
	$(CXX) -g -std=c++11 -ggdb -c $< -o $@

.PHONY: clean
clean:
	rm -f $(BIN)/*

run: clean $(BIN)/$(TARGET_EXEC)  
	./$(BIN)/$(TARGET_EXEC) -f $(TEST_DIR)/instances/exemp.mtx

run_edges: clean $(BIN)/$(TARGET_EXEC)  
	./$(BIN)/$(TARGET_EXEC) -s -f $(TEST_DIR)/instances/exemp.mtx

test: clean $(BIN)/$(TARGET_EXEC)
	(cd $(TEST_DIR) && ./$(TEST_SCRIPT))

debug: clean $(BIN)/$(TARGET_EXEC)
	gdb --args ./$(BIN)/$(TARGET_EXEC) -f ../../tests/Bat1/instances/exemp.mtx

