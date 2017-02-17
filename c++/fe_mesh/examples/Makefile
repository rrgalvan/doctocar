FE_MESH_SRC=../src
TARGETS = node_example
INCLUDE_DIR = $(FE_MESH_SRC)
OBJECTS = $(wildcard $(FE_MESH_SRC)/*.o)
INCLUDES = $(wildcard $(FE_MESH_SRC)/*.hpp)

all: $(TARGETS)

node_example: node_example.cpp $(INCLUDES)
	g++ -o $@ $< -I$(INCLUDE_DIR) $(OBJECTS)

clean:
	rm -f $(TARGETS) *~

.PHONY: all clean
