CC = gcc
AR = ar

VENDOR = ./vendor
INCLUDE = -I$(VENDOR)/include
LINK = -L$(VENDOR)/lib/ -lSDL2 -lSDL2main

MANDAW = ./mandaw

all: libmandaw

libmandaw: $(MANDAW)/mandaw.c
	$(CC) -c $< -o ./build/mandaw.o $(INCLUDE) $(LINK)
	$(AR) rcs ./build/libmandaw.a ./build/mandaw.o

example: main.c libmandaw
	$(CC) -o example $< -L./build/ -lmandaw -DSDL_MAIN_HANDLED $(LINK)