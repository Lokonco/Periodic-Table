# Compiler and flags
CXX = g++
CXXFLAGS = -I./include -std=c++17 -Wall -Wextra

# Directories
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

# Files
SOURCES = $(SRC_DIR)/main.cpp
OBJECTS = $(BUILD_DIR)/main.o
TARGET = Periodic-Table

# Default target
all: $(BUILD_DIR) $(TARGET)

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Build the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files to object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Phony targets (not real files)
.PHONY: all clean