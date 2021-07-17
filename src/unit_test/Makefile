CC = gcc
CFLAGS = -g

# source files
SRC_UNITY = jklib_unity.c
SRC_CMOCKA = jklib_cmocka.c
# include the herder files and library
INCLUDES =-I../include -Ilibs/
LIB_UNITY = libs/libunity.a
LIB_CMOCKA = libs/libcmocka-static.a
LIB = ../build/libjk.a
all: $(SRC_UNITY) $(LIB_UNITY) $(LIB)
	$(CC) -o jklib_unity $(CFLAGS) ${INCLUDES} $(SRC_UNITY) $(LIB_UNITY) $(LIB)
	$(CC) -o jklib_cmocka $(CFLAGS) ${INCLUDES} $(SRC_CMOCKA) $(LIB_CMOCKA) $(LIB)
clean:
	rm jklib_unity jklib_cmocka