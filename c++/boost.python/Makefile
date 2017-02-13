SOURCE=hellomodule.cpp
TARGET_LIB=build/lib.linux-x86_64-3.5/hello.cpython-35m-x86_64-linux-gnu.so

$TARGET_LIB: $(SOURCE) setup.py
	python3 setup.py build
	ln -fs $(TARGET_LIB)
