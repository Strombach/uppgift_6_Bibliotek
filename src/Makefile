#declare compile varible
CC= gcc

.PHONY: all lib install

#to build the shared library and remove .o files.
lib: libcomponent.c libresistance.c libpower.c
	$(CC) -c -Wall -Werror -fpic libcomponent.c libresistance.c libpower.c
	$(CC) -shared -o libresistance.so libresistance.o
	$(CC) -shared -o libpower.so libpower.o
	$(CC) -shared -o libcomponent.so libcomponent.o
	rm *.o

all:lib electrotest.c
	$(CC) -c electrotest.c
	mkdir -p lib
	mv ./*.so ./lib/
	$(CC) -o electrotest electrotest.o -L./lib -lcomponent -lpower -lresistance -Wl,-rpath,./lib
