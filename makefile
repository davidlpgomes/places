CXX = g++
CXXFLAGS = -pedantic-errors -Wall -Wextra -Werror -std=c++20 -O3

BUILD = build
OBJ_DIR = $(BUILD)/objects
EXEC_DIR = $(BUILD)/exec

INCLUDE = -Iinclude/
SRC = $(wildcard src/*.cpp) \
	  $(wildcard src/model/*.cpp) \
	  $(wildcard src/controller/*.cpp) \
	  $(wildcard src/view/*.cpp) \

TARGET = places

OBJECTS = $(SRC:%.cpp=$(OBJ_DIR)/%.o)
DEPENDENCIES = $(OBJECTS:.o=.d)


all: build $(EXEC_DIR)/$(TARGET)

build:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(EXEC_DIR)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -MMD -o $@

$(EXEC_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $(EXEC_DIR)/$(TARGET) $^ $(LDFLAGS)

-include $(DEPENDENCIES)

.PHONY: all build clean info

clean:
	@echo "[*] Removing bin directory: ${BUILD}"
	-@rm -rf $(BUILD)

info:
	@echo "[*] Executable dir: ${EXEC_DIR}"
	@echo "[*] Object dir: ${OBJ_DIR}"
	@echo "[*] Sources: ${SRC}"
	@echo "[*] Objects: ${OBJECTS}"
