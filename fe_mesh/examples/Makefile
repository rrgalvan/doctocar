FE_MESH_SRC=../src
TARGETS = point_example node_example element_example mesh_example
INCLUDE_DIR = $(FE_MESH_SRC)
OBJECTS = $(wildcard $(FE_MESH_SRC)/*.o)
INCLUDES = $(wildcard $(FE_MESH_SRC)/*.h)
CXX_FLAGS=-std=c++11

all: $(TARGETS)

point_example: point_example.cpp
	g++ -o $@ $< -I$(INCLUDE_DIR) $(CXX_FLAGS) $(OBJECTS)

node_example: node_example.cpp
	g++ -o $@ $< -I$(INCLUDE_DIR) $(CXX_FLAGS) $(OBJECTS)

element_example: element_example.cpp
	g++ -o $@ $< -I$(INCLUDE_DIR) $(CXX_FLAGS) $(OBJECTS)

mesh_example: mesh_example.cpp
	g++ -o $@ $< -I$(INCLUDE_DIR) $(CXX_FLAGS) $(OBJECTS)

clean:
	rm -f $(TARGETS) *~

.PHONY: all clean
