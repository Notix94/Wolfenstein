
main: main.c clavier.c clavier.h
	gcc main.c clavier.c -o main $(shell sdl2-config --cflags --libs) -lm