src:
	make -C src/

examples:
	make -C examples/

doc:
	make -C doc/

all: src doc examples

clean:
	make -C src/ clean
	make -C doc/ clean
	rm -f *~

.PHONY: src doc clean examples
