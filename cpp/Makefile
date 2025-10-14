CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
TARGET = tic_tac_toe
SRC = game.cpp
HEADER = game.h

all: $(TARGET)

$(TARGET): $(SRC) $(HEADER)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET) *.o

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
