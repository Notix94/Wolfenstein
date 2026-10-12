#ifndef CLAVIER_H
#define CLAVIER_H

#include <SDL2/SDL.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define TAILLE 64
#define LIGNE 5
#define COLONNE 5

extern int map[LIGNE][COLONNE];

void gestionTouche(float *x,float *y,float *angle);

#endif 