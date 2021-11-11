#comment lines

#defining macros
CC = gcc
CCFLAGS = -O3
LDFLAGS = -lm

#executable
all: mmc

#linking 
#gcc -o mmc main.o matmult.o -lm
mmc: main.o matmult.o
	$(CC) -o $@ $^ $(LDFLAGS)


#compling
#gcc -c -O3 main.c	
main.o: main.c
	$(CC) -c $(CCFLAGS) $<


#compiling
#gcc -c -O3 matmult.c	
matmult.o: matmult.c
	$(CC) -c $(CCFLAGS) $<

#removing object files	
clean:
	rm *.o
