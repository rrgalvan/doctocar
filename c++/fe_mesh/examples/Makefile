FE_MESH_SRC=../src
TARGETS = point_example node_example element_example
INCLUDE_DIR = $(FE_MESH_SRC)
OBJECTS = $(wildcard $(FE_MESH_SRC)/*.o)
INCLUDES = $(wildcard $(FE_MESH_SRC)/*.hpp)
CXX_FLAGS=-std=c++11

all: $(TARGETS)

point_example: point_example.cpp $(INCLUDES)
	g++ -o $@ $< -I$(INCLUDE_DIR) $(CXX_FLAGS) $(OBJECTS)

node_example: node_example.cpp $(INCLUDES)
	g++ -o $@ $< -I$(INCLUDE_DIR) $(CXX_FLAGS) $(OBJECTS)

element_example: element_example.cpp $(INCLUDES)
	g++ -o $@ $< -I$(INCLUDE_DIR) $(CXX_FLAGS) $(OBJECTS)
clean:
	rm -f $(TARGETS) *~

.PHONY: all clean
