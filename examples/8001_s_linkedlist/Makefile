CC = gcc
CFLAGS = -g

# source files
SRC = slinkedlist_test.c
# include the herder files and library
INCLUDES =-I../../src/include -I../../release/
LIB = ../../release/libjk.a
slinkedlist_test: $(SRC) $(LIB)
	$(CC) -o $@ $(CFLAGS) ${INCLUDES} $(SRC) $(LIB)
clean:
	rm *.exe