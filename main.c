#include "clavier.h"
int map[LIGNE][COLONNE] = {
    {1,1,1,1,1},
    {1,0,0,0,1},
    {1,0,0,0,1},
    {1,0,0,0,1},
    {1,1,1,1,1}
};

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
    float x = 100;
    float y = 100;
    int w = 8,h = 8;
    float angle = 0;

        
   
    while(running){

        SDL_Event event;//boite d'ordre
        while(SDL_PollEvent(&event))//tant qu'il y a encore un ordre sinon 0
        {
            if(event.type == SDL_QUIT) {running =0;}
            /*if(event.type ==SDL_KEYDOWN){
                printf("UNE TOUCHE EST ENFONCÉE !!! %d\n", event.key.keysym.sym);
            }*/
        }
        gestionTouche(&x,&y,&angle);


        SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);//met en noir pour clear
        SDL_RenderClear(rend);

        //crea de la map
        for (int i = 0; i < LIGNE; i++) {
            for (int j = 0; j < COLONNE; j++) {
                if(map[i][j] == 1){
                    SDL_SetRenderDrawColor(rend, 52, 100, 156, 255); //met en bleu pour le mur
                    SDL_Rect r = { j*TAILLE ,i*TAILLE, TAILLE, TAILLE};
                    SDL_RenderFillRect(rend, &r); // met la couleur au carr
                    
                }     
            }
        }

        SDL_SetRenderDrawColor(rend, 238, 130, 238, 255); //met en rose pour le carr
        SDL_Rect r = { x - w/2, y - h/2, w, h };
        SDL_RenderFillRect(rend, &r); // met la couleur au carr

        //ligne regard
        int x2 = x + cos(angle) * 20;
        int y2 = y + sin(angle) * 20;
        SDL_SetRenderDrawColor(rend,139, 157, 52,255);
        SDL_RenderDrawLine(rend, x, y, x2, y2);

        //render et fps
        SDL_RenderPresent(rend);
        SDL_Delay(16); // 60 fps 1000 ms ÷ 16 ms ≈ 62
    }

    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win); //free la fenetre pas de garbage coll
    SDL_Quit();// ferme sdl
    
    return 0;
}