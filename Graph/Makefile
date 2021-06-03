CC=gcc
CFLAGS=-g
TARGET:test.exe

OBJS=graph.o	\
     topology.o

test.exe:testapp.o ${OBJS}
	${CC} ${CFLAGS} testapp.o ${OBJS} -o test.exe

testapp.o:testapp.c
	${CC} ${CFLAGS} -c testapp.c -o testapp.o

graph.o:graph.c
	${CC} ${CFLAGS} -c -I . graph.c -o graph.o

topologies.o:topologies.c
	${CC} ${CFALGS} -c -I . topology.c -o topology.o

clean:
	rm *.o
	rm *exe

