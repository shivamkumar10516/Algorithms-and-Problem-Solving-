# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -O2 -g
TARGET = algorithms_project

# Source files
SOURCES = main.cpp Sorting.cpp Searching.cpp Greedy.cpp
HEADERS = Sorting.h Searching.h Greedy.h

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Compile source files to object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJECTS) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean and rebuild
rebuild: clean all

# Debug build with debug symbols
debug: CXXFLAGS += -DDEBUG -g -O0
debug: clean all

# Release build with optimizations
release: CXXFLAGS += -O3 -DNDEBUG
release: clean all

# Create documentation
docs:
	doxygen -g
	@echo "Run 'doxygen' to generate documentation"

# Format code (requires clang-format)
format:
	clang-format -i *.cpp *.h

# Check for memory leaks (requires valgrind)
memcheck: $(TARGET)
	valgrind --leak-check=full ./$(TARGET)

# Profile performance (requires gprof)
profile: CXXFLAGS += -pg
profile: clean all
	./$(TARGET)
	gprof $(TARGET) gmon.out > analysis.txt
	@echo "Profile data written to analysis.txt"

.PHONY: all clean run rebuild debug release docs format memcheck profile
