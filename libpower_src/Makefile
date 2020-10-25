#declare compile varible
CC= gcc

.PHONY: all lib install

#to build the shared library and remove .o files.
lib: calc_power_i.c calc_power_r.c
	$(CC) -fPIC -c calc_power_i.c calc_power_r.c
	$(CC) -shared -o libpower.so calc_power_i.o calc_power_r.o
	rm calc_power_i.o calc_power_r.o

all: lib test.c
	$(CC) -c test.c
	mkdir -p lib
	mv ./libpower.so ./lib/libpower.so
	$(CC) -o testProgram test.o -L./lib -lpower -Wl,-rpath,./lib
