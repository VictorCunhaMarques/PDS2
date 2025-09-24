CC=g++
CFLAGS=-std=c++11 -Wall
SRC_DIR=src
INCLUDE_DIR=include
BUILD_DIR=build
BIN_DIR=bin


all: $(BIN_DIR)/executable

$(BUILD_DIR)/user.o: $(SRC_DIR)/user.cpp $(INCLUDE_DIR)/user.hpp
	$(CC) $(CFLAGS) -c -I$(INCLUDE_DIR) $(SRC_DIR)/user.cpp -o $(BUILD_DIR)/user.o

$(BUILD_DIR)/system.o: $(SRC_DIR)/system.cpp $(INCLUDE_DIR)/system.hpp
	$(CC) $(CFLAGS) -c -I$(INCLUDE_DIR) $(SRC_DIR)/system.cpp -o $(BUILD_DIR)/system.o

$(BUILD_DIR)/project.o: $(SRC_DIR)/project.cpp $(INCLUDE_DIR)/project.hpp
	$(CC) $(CFLAGS) -c -I$(INCLUDE_DIR) $(SRC_DIR)/project.cpp -o $(BUILD_DIR)/project.o

$(BUILD_DIR)/task.o: $(SRC_DIR)/task.cpp $(INCLUDE_DIR)/task.hpp
	$(CC) $(CFLAGS) -c -I$(INCLUDE_DIR) $(SRC_DIR)/task.cpp -o $(BUILD_DIR)/task.o

$(BUILD_DIR)/main.o: $(SRC_DIR)/main.cpp $(INCLUDE_DIR)/task.hpp $(INCLUDE_DIR)/project.hpp $(INCLUDE_DIR)/system.hpp $(INCLUDE_DIR)/user.hpp
	$(CC) $(CFLAGS) -c -I$(INCLUDE_DIR) $(SRC_DIR)/main.cpp -o $(BUILD_DIR)/main.o

$(BIN_DIR)/executable: $(BUILD_DIR)/main.o $(BUILD_DIR)/task.o $(BUILD_DIR)/project.o $(BUILD_DIR)/system.o $(BUILD_DIR)/user.o
	$(CC) $(CFLAGS) -o $@ $^ 