#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SDL/SDL.h"
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "input.h"
#include "struct.h"
#include "player.h"
int main ()
{SDL_Event event;
SDL_Surface *screen,*bg;
SDL_Rect bg_pos={0,0};
player pl;
char ch[10];
pos p;
if(SDL_Init(SDL_INIT_EVERYTHING)!=0){
printf("Unable to initialize SDL:%s\n",SDL_GetError());
return 1;
}
screen=SDL_SetVideoMode(800,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
if (screen==NULL){
printf("Unable to set 600x400 video: %s\n",SDL_GetError());
return 1;
}
init_player(&pl);
bg=IMG_Load("image/nature.png");
int done =1,i ;
SDL_EnableKeyRepeat(30,30);
while(done)
{
SDL_PollEvent(&event);
input_t(event,ch,&p);
if(strcmp(ch,"exit")==0)
done=0;
SDL_BlitSurface(bg,NULL,screen,&bg_pos);
Player(&pl,&screen);

SDL_Flip(screen);
}
for(i=0;i<7;i++)
SDL_FreeSurface(pl.images[i]);
SDL_FreeSurface(bg);
SDL_Quit();
 }

