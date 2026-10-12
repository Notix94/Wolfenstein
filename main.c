#include <SDL2/SDL.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>


int main(void){
    int running = 1;

    if(SDL_Init(SDL_INIT_VIDEO)<0){
        printf("%s\n", SDL_GetError());
        exit(1);
    };

    SDL_Window *win = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, 640, 480, 0); //Titre, pos ecran en x2,larg haut,flag 
    
    if(!win){
        printf("%s\n", SDL_GetError());
        exit(1);
    }
    //SDL_Renderer *SDl_CreateRenderer(SDL_Window *window, int index, Uint32 flags)//La fenetre,pil graphique, option 
    SDL_Renderer  *rend = SDL_CreateRenderer(win,-1,0); // l'obj qui dessine 
    if(rend == NULL){
        printf("%s\n", SDL_GetError());
        exit(1);
    }
    int x = 320;
    int y = 240;
    int w = 8,h = 8;

    while(running){

        SDL_Event event;//boite d'ordre
        while(SDL_PollEvent(&event))//tant qu'il y a encore un ordre sinon 0
        {
            if(event.type == SDL_QUIT) {running =0;}
            /*if(event.type ==SDL_KEYDOWN){
                printf("UNE TOUCHE EST ENFONCÉE !!! %d\n", event.key.keysym.sym);
            }*/
        }
        const Uint8 *keys = SDL_GetKeyboardState(NULL);
        if(keys[SDL_SCANCODE_W]){
            y-= 1;
        }
        if(keys[SDL_SCANCODE_A]){
            x-= 1;
        }
        if(keys[SDL_SCANCODE_S]){
            y+= 1;
        }
        if(keys[SDL_SCANCODE_D]){
            x+= 1;
        }
        
        SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);//met en noir pour clear
        SDL_RenderClear(rend);
        SDL_SetRenderDrawColor(rend, 238, 130, 238, 255); //met en gris pour le carr
        SDL_Rect r = { x, y, w, h };
        SDL_RenderFillRect(rend, &r); // affich le rendu du carre
        SDL_RenderPresent(rend);
       
    }

    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win); //free la fenetre pas de garbage coll
    SDL_Quit();// ferme sdl
    
    return 0;
}