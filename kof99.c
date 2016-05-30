#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
SDL_Surface *ecran, *imageDeFond, *logo, *visage_iori, *visage_k, *life_meter;
SDL_Surface * img_iori,*img_K,*img_effet;

Uint32 getpixel(SDL_Surface *screen, int i, int j) {
  return ((Uint32*)screen->pixels)[53 * i + j];
}

void setpixel(SDL_Surface *screen, int i, int j, Uint32 color) {
  ((Uint32*)screen->pixels)[53 * i + j] = color;
}

void miroir(SDL_Surface *screen) {
  int i, j;
  Uint32 tmp;
  for(i = 0; i < 60; i++)
    for(j = 0; j < 53/ 2; j++) {
      tmp = getpixel(screen, i, j);
      setpixel(screen, i, j, getpixel(screen, i, 53 - 1 - j));
      setpixel(screen, i, 53 - 1 - j, tmp);
    }
}

void init(void){
    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(550, 225, 32, SDL_HWSURFACE);
    //Les images sont fixes
    imageDeFond = IMG_Load("source/kof99.gif");
    logo =IMG_Load("source/kof99_logo.png");
    //visage_iori= IMG_Load("source/visage3.png");
    life_meter= IMG_Load("source/life3.png");
    life_meter= IMG_Load("source/bar2.png");
    //visage_k= IMG_Load("source/visage4.png");
    //miroir(visage_k); 
}
void input_handle(void){// pour sortir de le boucle while
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

void anime(void){
  SDL_Rect pos_effet, pos_iori,pos_k,positionFond,pos_logo,pos_visage1,pos_visage2,pos_life;
    int iori=0;
    int k=0;
    positionFond.x = 0;
    positionFond.y = 0;
    pos_visage1.x=479;
    pos_visage1.y=0;
    pos_visage2.x=20;
    pos_visage2.y=0;
    pos_logo.x = 100;
    pos_logo.y = 10;
    pos_life.x = 33;
    pos_life.y = 10;
    
    pos_life.x = 120;
    pos_life.y = 0;
    pos_iori.x=350;
    pos_iori.y=105;
    pos_k.x=125;
    pos_k.y=98;



    char image[50];
    int y;
    int effet_count;
    int logo_count=0;
    while(1){
      //if(logo_count>50){
	SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
	SDL_BlitSurface(life_meter, NULL, ecran, &pos_life);
	SDL_BlitSurface(visage_iori, NULL, ecran, &pos_visage1);
	
	SDL_BlitSurface(visage_k, NULL, ecran, &pos_visage2);
	sprintf (image, "source/Iori Yagami_%d.png",iori);
        img_iori = IMG_Load(image);
	SDL_BlitSurface(img_iori, NULL, ecran, &pos_iori);
	
        sprintf (image, "source/Kyo Kusanagi_%dr.png",k);
        img_K = IMG_Load(image);
	SDL_BlitSurface(img_K, NULL, ecran, &pos_k);

  SDL_Event event;
  if(SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_KEYDOWN:
        switch(event.key.keysym.sym) {
          case SDLK_RIGHT:
	    iori=22;
	    pos_iori.y=105;
          break;
          case SDLK_LEFT:
	    if(iori>9 && iori< 22){iori=53;pos_iori.y=125;}
	    else {iori=9;pos_iori.y=105;}
	  break;
          case SDLK_UP:
	    if(iori<28)iori=28;
          break;
          case SDLK_DOWN:
	    iori=35;
	    pos_iori.y=105;
	    break;
	case SDLK_q:
	  if(iori > 202 && iori < 217)iori=267;
	  else if(iori > 92 && iori < 102)iori=202; 
	  else {iori=92;pos_iori.y=105;}
	  break;
	case SDLK_s:
	  if(iori > 234 && iori < 247){iori=326;pos_iori.y=105;}
	  else if(iori > 159 && iori < 169 )iori=234;
	  else if(iori > 144 && iori < 155 )iori=159;
	  else iori=144;
	  break;
	case SDLK_d:	  
	  if(iori > 290 && iori < 325){iori=384;pos_iori.y=105;}
	  else if(iori > 175 && iori < 180){iori=290;pos_iori.y=105;}
	  else if(iori > 170 && iori < 175 )iori=175;
	  else iori=170;
	  break;
	case SDLK_f:
	  iori=217;
	  break;	  
	case SDLK_a:
	  iori=442;
	  pos_iori.y=92; 
	  break;
	case SDLK_z:
	  iori=550;
	  pos_iori.y=85;
	  break;
	case SDLK_e:
	  iori=515;
	  pos_iori.y=77; 
	  break;
	case SDLK_ESCAPE:
	  exit(0);
	  break;
          default:
	    break;
	 }
	}
    }

	// STOP
	if(iori==8){iori=0;pos_iori.y=105;}
	iori++;
	// WALK LEFT
	if(iori>8 && iori< 22)pos_iori.x-=10;
	if(iori==21){iori=0;pos_iori.y=105;}
	// WALK LEFT LEFT (FAST)
	if(iori>52 && iori< 60)pos_iori.x-=18;
	if(iori==60){iori=0;pos_iori.y=105;}
	// WALK RIGHT
	if(iori>21 && iori< 27)if(pos_iori.x<457)pos_iori.x+=16;
	if(iori==27){iori=0;pos_iori.y=105;}
        // JUMP
	if(iori==34){iori=0;pos_iori.y=105;}
	if(iori>27 && iori< 35)if(iori<31)pos_iori.y-=43; else pos_iori.y+=20;
	// DOWN
	if(iori>34 && iori< 41)pos_iori.y=150;
	if(iori==41){iori=0;pos_iori.y=105;}
	
	//PUNCH ATTACK Q
	if(iori==103)iori=0;
        //PUNCH ATTACK Q + Q
	if(iori==217)iori=0;
        //PUNCH ATTACK Q + Q + Q
	if(iori==275)iori=0;
	if(iori==270)effet_count=275;
	if(effet_count>274 && effet_count<288){
	  if(effet_count==288)effet_count=0;
	  effet_count++;
	  pos_effet.x=pos_iori.x-80;
	  pos_effet.y= pos_iori.y+35;
	  sprintf (image, "source/Iori Yagami_%d.png",effet_count);
	  img_effet = IMG_Load(image);
	  SDL_BlitSurface(img_effet, NULL, ecran, &pos_effet);
	}
	//PUNCH ATTACK S
	if(iori==155)iori=0;
        //PUNCH ATTACK S + S 
	if(iori==169)iori=0;
	//PUNCH ATTACK S + S + S	
	if(iori==247){iori=0;pos_iori.y=105;}
	if(iori>234 && iori < 247)pos_iori.y-=5;
	if(iori==238)effet_count=247;
	if(effet_count>246 && effet_count<256){  
	  if(effet_count==257)effet_count=0;
	  effet_count++;
	  pos_effet.x=pos_iori.x-40;
	  pos_effet.y= pos_iori.y;
	  sprintf (image, "source/Iori Yagami_%d.png",effet_count);
	  img_effet = IMG_Load(image);
	  SDL_BlitSurface(img_effet, NULL, ecran, &pos_effet);
	}
        //SUPER SPECIAL MOVE S + S + S + S
	if(iori==366)iori=0;
	if(iori==360)effet_count=366;
	if(effet_count>365 && effet_count<383){
	  if(effet_count==383)effet_count=0;
	  effet_count++;
	  pos_effet.x=pos_iori.x-100;
	  pos_effet.y= pos_iori.y-80;
	  sprintf (image, "source/Iori Yagami_%d.png",effet_count);
	  img_effet = IMG_Load(image);
	  SDL_BlitSurface(img_effet, NULL, ecran, &pos_effet);
	}
        //KICK ATTACK D
	if(iori==174)iori=0;
        //KICK ATTACK D + D
	if(iori==189)iori=0;
        //KICK ATTACK D + D + D
	if(iori==325)iori=0;
        //SPECIAL MOVE D + D + D + D
	if(iori==406)iori=0;
	if(iori==390)effet_count=406;
	if(effet_count>405 && effet_count<441){  
	  if(effet_count==441)effet_count=0;
	  effet_count++;
	  pos_effet.x=pos_iori.x-100;
	  pos_effet.y= pos_iori.y-80;
	  sprintf (image, "source/Iori Yagami_%d.png",effet_count);
	  img_effet = IMG_Load(image);
	  SDL_BlitSurface(img_effet, NULL, ecran, &pos_effet);
	}

        //KICK ATTACK F
	if(iori==229)iori=0;
	
	//CEREMONY 1
	if(iori==461){iori=0;pos_iori.y=105;}
	//CEREMONY 2
	if(iori==567){iori=0;pos_iori.y=105;}
	//CEREMONY 3
	if(iori==530){iori=0;pos_iori.y=105;}
	if(iori==516)effet_count=496;
	if(effet_count>495 && effet_count<514){
	  if(effet_count==515)effet_count=0;
	  effet_count++;
	  pos_effet.x=pos_iori.x;
	  pos_effet.y= pos_iori.y;
	  sprintf (image, "source/Iori Yagami_%d.png",effet_count);
	  img_effet = IMG_Load(image);
	  SDL_BlitSurface(img_effet, NULL, ecran, &pos_effet);
	}

	
        //Kyo STOP
	if(k==9)k=0;
	k++;
	
	//}else{ SDL_BlitSurface(logo, NULL, ecran, &pos_logo); 
	//logo_count++;}
	SDL_Flip(ecran); // On affiche réellement l'image.
        input_handle();
        
        SDL_Delay(52);
    }
}

int main(void){
    init();
    anime();
    return 0;
}
