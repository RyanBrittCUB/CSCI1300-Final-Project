# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Werror -Wpedantic

# Target executable
TARGET = Run

# For deleting the target
TARGET_DEL = Run

# Source files
SRCS = \
board.cpp \
candyLogic.cpp \
character.cpp \
gameEngine.cpp \
loadCharacter.cpp \
main.cpp


# Object files
OBJS = $(SRCS:.cpp=.o)

# Default rule to build and run the executable
all: $(TARGET) Run

# Rule to link object files into the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) 

# Rule to compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to run the executable
run: $(TARGET)
	./$(TARGET)

# Clean rule to remove generated files
clean:
	del $(TARGET_DEL) $(OBJS)

