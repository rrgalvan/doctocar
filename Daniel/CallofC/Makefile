SOURCES = $(wildcard *.c)  
OBJECTS = $(subst .c,.o,$(SOURCES))
SOBRANTES = $(wildcard *~)

.PHONY: test clear help

ejecutable: $(OBJECTS)
	g++ $(OBJECTS) -o ejecutable

$(OBJECTS).o: $(SOURCES)
	g++ -O2 -I /usr/include/python3.5  -c $(SOURCES)

clear:
	rm $(OBJECTS) ejecutable $(SOBRANTES)
test:
	@echo "Sources are: " $(SOURCES)
	@echo "Objects are: " $(OBJECTS)

help:
	@echo "Objetivos del Makefile"
	@echo $(SOURCES)
	@echo "clean elimina .o, ejecutable y copias de seguridad
