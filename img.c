#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

struct data{
  SDL_Surface * ecran;
  SDL_Surface * tortue;
};
typedef struct data * data; 


data * init(void){
data * data;
    SDL_Init(SDL_INIT_VIDEO);
    data->ecran = SDL_SetVideoMode(550, 225, 32, SDL_HWSURFACE);
    data->tortue = img
return data;



}
void input_handle(data * data){// pour sortir de le boucle while
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            SDL_Quit();
            exit(0);
            break;
        }
    }
}
void animation(){
  SDL_Rect pos;
  
   while(1){
  

   }
}
int main(){
data d;
d=init();


}
