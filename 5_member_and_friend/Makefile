CXX = g++
CXXFLAGS = -Wall -std=c++11

all: main

main: main.o Matrix.o
	$(CXX) $(CXXFLAGS) -o matrix main.o Matrix.o

main.o: main.cpp Matrix.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Matrix.o: Matrix.cpp Matrix.h
	$(CXX) $(CXXFLAGS) -c Matrix.cpp

clean:
	rm -f *.o matrix
