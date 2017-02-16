SOURCES = $(wildcard *.cpp)
OBJECTS = $(subst .cpp,.o, $(SOURCES))

.PHONY: clean

$(OBJECTS).o: $(SOURCES)
	g++ -c $(SOURCES)

clean:
	rm -f $(OBJECTS) *~
