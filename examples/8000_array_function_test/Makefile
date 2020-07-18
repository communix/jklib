CC = gcc
CFLAGS = -g

# source files
SRC = array_function_test.c
# include the herder files and library
INCLUDES =-I../../src/include -I../../release/
LIB = ../../release/libjk.a
array_function_test: $(SRC) $(LIB)
	$(CC) -o $@ $(CFLAGS) ${INCLUDES} $(SRC) $(LIB)
clean:
	rm *.exe