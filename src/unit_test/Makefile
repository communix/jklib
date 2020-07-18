CC = gcc
CFLAGS = -g

# source files
SRC = jklib_unit_test.c
# include the herder files and library
INCLUDES =-I../include -Ilibs/
LIB = libs/libunity.a
LIB += ../build/libjk.a
all: $(SRC) $(LIB)
	$(CC) -o unit_test $(CFLAGS) ${INCLUDES} $(SRC) $(LIB)
clean:
	rm *.exe