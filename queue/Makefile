SHELL=/bin/sh

OBJS= main.cpp Q.cpp 
CFLAG=-Wall -g
CC=g++
INCLUDE=
LIBS=

queue:${OBJ}
	${CC} ${CFLAGS} ${INCLUDES} -o $@ ${OBJS} ${LIBS}

clean:
	-rm -f *.o core *.core queue

.cpp.o:
	${CC} ${CFLAGS} ${INCLUDES} -c $<
