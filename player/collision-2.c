#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include "collision.h"
#include "scrolling.h"

#ifndef PLAYER_H_
#define PLAYER_H_
typedef struct player
{SDL_Surface *images[7];
int compteur,nbr_vie,score;
SDL_Rect pos;
}player;
void init_player(player *p);
void install_player(SDL_Surface **screen,player *p);
void player_animation(char ch[10],player *p);
void player_mvt(player *p,char ch[10]);
void Player(player *p,SDL_Surface **screen);
#endif /* FONCTIONS_H_ */