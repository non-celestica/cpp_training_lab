# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++11 -Wextra -pedantic

# Project structure
TARGET = mathlab
OBJS = main.o math.o

# Default build target
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp math.h
	$(CXX) $(CXXFLAGS) -c main.cpp

math.o: math.cpp math.h
	$(CXX) $(CXXFLAGS) -c math.cpp

# Clean build files
clean:
	rm -f $(OBJS) $(TARGET)
