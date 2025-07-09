CXX = g++
CXXFLAGS = -Wall -std=c++11

OBJS = main.o unit.o fighter.o knight.o

lab: $(OBJS)
	$(CXX) -o game $(OBJS)

main.o: main.cpp unit.h fighter.h knight.h
unit.o: unit.cpp unit.h
fighter.o: fighter.cpp fighter.h unit.h
knight.o: knight.cpp knight.h fighter.h

clean:
	rm -f *.o game
