#include"clavier.h"


void gestionTouche(float *x,float *y,float *angle){
const Uint8 *keys = SDL_GetKeyboardState(NULL);
        if(keys[SDL_SCANCODE_LEFT]){
            *angle -=0.05;
        }
        if(keys[SDL_SCANCODE_RIGHT]){
            *angle +=0.05;
        }
        if (keys[SDL_SCANCODE_W]) {
            int ny = *y - 1;
            if (map[ny / TAILLE][(int)*x / TAILLE] == 0) {
                *y = ny;
            }
        }
        if (keys[SDL_SCANCODE_S]) {
            int ny = *y + 1;
            if (map[ny / TAILLE][(int)*x / TAILLE] == 0) {
                *y = ny;
            }
        }
        if (keys[SDL_SCANCODE_A]) {
            int nx = *x - 1;
            if (map[(int)*y / TAILLE][nx / TAILLE] == 0) {
                *x = nx;
            }
        }
        if (keys[SDL_SCANCODE_D]) {
            int nx = *x + 1;
            if (map[(int)*y / TAILLE][nx / TAILLE] == 0) {
                *x = nx;
            }
        }
}
