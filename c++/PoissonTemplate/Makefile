SOURCES = $(wildcard *.cpp)  
OBJECTS = $(subst .cpp,.o,$(SOURCES))
SOBRANTES = $(wildcard *~)
EIGENDIR=/usr/include/eigen3/

.PHONY: test clear help

ejecutable: $(OBJECTS)
	g++ $(OBJECTS) -o ejecutable

$(OBJECTS).o: $(SOURCES)
	g++  -O2 -I $(EIGENDIR) -c $(SOURCES)

clear:
	rm $(OBJECTS) ejecutable $(SOBRANTES)
test:
	@echo "Sources are: " $(SOURCES)
	@echo "Objects are: " $(OBJECTS)

help:
	@echo "Objetivos del Makefile"
	@echo $(SOURCES)
	@echo "clean elimina .o, ejecutable y copias de seguridad"
