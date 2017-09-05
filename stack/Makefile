SHELL=/bin/sh

OBJS= main.cpp S.cpp 
CFLAG=-Wall -g
CC=g++
INCLUDE=
LIBS=

stack:${OBJ}
	${CC} ${CFLAGS} ${INCLUDES} -o $@ ${OBJS} ${LIBS}

clean:
	-rm -f *.o stack

.cpp.o:
	${CC} ${CFLAGS} ${INCLUDES} -c $<
