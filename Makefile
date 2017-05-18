CC = gcc
CFLAGS = -g -Wall -std=c99
LDLIBS = -lm

mandelbrot: mandelbrot.o

clean:
	rm -f mandelbrot
	rm -f mandelbrot.o
