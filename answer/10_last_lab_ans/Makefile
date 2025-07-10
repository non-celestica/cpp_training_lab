CXX = g++
CXXFLAGS = -Wall -std=c++11

OBJS = main.o unit.o fighter.o knight.o mage.o wizzard.o

lab: $(OBJS)
	$(CXX) -o game $(OBJS)

main.o: main.cpp unit.h fighter.h knight.h mage.h wizzard.h
unit.o: unit.cpp unit.h
fighter.o: fighter.cpp fighter.h unit.h
knight.o: knight.cpp knight.h fighter.h
mage.o: mage.cpp mage.h unit.h
wizzard.o: wizzard.cpp wizzard.h mage.h

clean:
	rm -f *.o game
