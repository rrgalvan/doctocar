FE_MESH_SRC=../src

TARGETS = node_example
INCLUDES=-I$(FE_MESH_SRC)
OBJECTS = $(wildcard $(FE_MESH_SRC)/*.o)

all: $(TARGETS)

node_example: node_example.cpp
	g++ $(INCLUDES) $(OBJECTS) $< -o $@

clean:
	rm -f $(TARGETS) *~

.PHONY: all clean
