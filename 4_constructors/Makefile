CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

TARGET = table_example
OBJS = main.o table.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp table.h
	$(CXX) $(CXXFLAGS) -c main.cpp

table.o: table.cpp table.h
	$(CXX) $(CXXFLAGS) -c table.cpp

clean:
	rm -f $(TARGET) $(OBJS)