PROG=$(P)
OBJECTS=
CFLAGS=-g -Wall -O3 -std=c99 -include standard.h
LDLIBS=
CC=cc

$(PROG): $(OBJECTS)
