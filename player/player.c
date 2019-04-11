#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "SDL/SDL.h"
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "player.h"
#include "input.h"
void init_player(player *p)
{p->pos.x=0;
p->pos.y=400;
p->images[0]=IMG_Load("image/face.png");
p->images[1]=IMG_Load("image/mv1.png");
p->images[2]=IMG_Load("image/mv2.png");
p->images[3]=IMG_Load("image/mv3.png");
p->images[4]=IMG_Load("image/mv4.png");
p->images[5]=IMG_Load("image/down.png");
p->images[6]=IMG_Load("image/up.png");
p->nbr_vie=3;
p->compteur=0;
p->score=0;
}
void install_player(SDL_Surface **screen,player *p)
{int i;
for(i=0;i<480;i++)
{
SDL_BlitSurface(p->images[p->compteur],NULL,*screen,&p->pos);
}
}
void player_animation(char ch[10],player *p)
{int i=p->compteur;
if(strcmp(ch,"right")==0)
{if((p->compteur==0)||(p->compteur==5)||(p->compteur==6))
i=1;
else if(p->compteur==4)
i=1;
else i++;
p->compteur=i;
SDL_Delay(30);
}
else if(strcmp(ch,"RIGHT")==0)
{
p->compteur=1;
}
else if(strcmp(ch,"up")==0)
{if(p->compteur==5)
	{
	p->compteur=1;}
else {
	p->compteur=6;}
}
else if(strcmp(ch,"UP")==0)
{
	p->compteur=1;
}
else if(strcmp(ch,"down")==0)
{{
	p->compteur=5;
}
}
}
void player_mvt(player *p,char ch[10])
{
if((strcmp(ch,"up")==0)/*&&(x!=1)*/)
{p->pos.y=440;
p->pos.x+=5;
}
else if((strcmp(ch,"UP")==0)/*&&(x!=3)*/)
{p->pos.y=480;
}
else if((strcmp(ch,"right")==0)/*&&(x!=2)*/)
{p->pos.x+=5;
//printf("here3\n");
}
else if((strcmp(ch,"left")==0)/*&&(x!=4)*/)
{p->pos.x--;
//printf("here4\n");
}
if((p->pos.x<=0)&&(strcmp(ch,"left")==0))
p->pos.x=3200;
if((p->pos.x>=3700)&&(strcmp(ch,"right")==0))
p->pos.x=0;
}
void Player(player *p,SDL_Surface **screen)
{SDL_Event event;
pos po;
char ch[10];
SDL_PollEvent(&event);
install_player(screen,p);
input_t(event,ch,&po);
player_animation(ch,p);
player_mvt(p,/*int x,*/ch);
strcpy(ch,"");
}

SDL_Color GetPixel(SDL_Surface* pSurface, int x, int y)
{
  SDL_Color color;
  Uint32 col = 0;
  //determine position
  char* pPosition = (char*) pSurface->pixels;
  //offset by y
  pPosition += (pSurface->pitch * y);
  //offset by x
  pPosition += (pSurface->format->BytesPerPixel * x);
  //copy pixel data
  memcpy (&col, pPosition, pSurface->format->BytesPerPixel);
  //convert color
  SDL_GetRGB (col, pSurface->format, &color.r , &color.g, &color.b);
  return (color);
}


int collision_p1(SDL_Surface *back,perso p1,scrol s)
{
	int verif=0;
	int i;
	SDL_Color couleur[1];

      
	
	couleur[0] = GetPixel(back,s.positioncamera.x+250,s.positioncamera.y+400);
        

        
        //couleur[0] = GetPixel(back1,s1.positioncamera.x+450,s1.positioncamera.y+400);
	//couleur[0] = GetPixel(back,s.positioncamera.x+520,s.positioncamera.y+490);
	//couleur[2] = GetPixel(back,s.positioncamera.x+500,s.positioncamera.y+500);
	//couleur[3] = GetPixel(back,s.positioncamera.x+520,s.positioncamera.y+500);

for(i=0;i<1;i++)
	{
		if((couleur[i].r == 238) && ((couleur[i].g == 238) && (couleur[i].b == 238))) 
		{
			verif=1;
			break;
		}


}


	return verif;

