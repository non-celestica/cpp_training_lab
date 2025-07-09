# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Target binary
TARGET = bank_app

# Source files
SRCS = main.cpp BankAccount.cpp

# Header files (for reference only, not compiled)
HEADERS = BankAccount.h

# Object files (automatically inferred from SRCS)
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Link the object files into the final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile .cpp to .o
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $<

# Clean up
clean:
	rm -f $(OBJS) $(TARGET)