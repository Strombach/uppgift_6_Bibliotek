#declare compile varible
CC= gcc

.PHONY: all lib install

#to build the shared library and remove .o files.
lib: calc_power_i.c calc_power_r.c
	$(CC) -fPIC -c calc_power_i.c calc_power_r.c
	$(CC) -shared -o libpower.so calc_power_i.o calc_power_r.o
	rm calc_power_i.o calc_power_r.o
