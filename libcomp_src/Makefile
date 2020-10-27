#declare compile varible
CC= gcc

.PHONY: all lib install

#to build the shared library and remove .o files.
lib: libcomponent.c
	$(CC) -fPIC -c libcomponent.c
	$(CC) -shared -o libcomponent.so libcomponent.o
	rm libcomponent.o

all: lib test.c
	$(CC) -c test.c
	mkdir -p lib
	mv ./libcomponent.so ./lib/libcomponent.so
	$(CC) -o testProgram test.o -L./lib -lcomponent -Wl,-rpath,./lib
