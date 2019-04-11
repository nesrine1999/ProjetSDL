 #ifndef COLLISION_H_
#define COLLISION_H_
#include "animation.h"
#include "scrolling.h"


SDL_Color GetPixel(SDL_Surface* pSurface, int x, int y);
int collision_p1(SDL_Surface *back2,perso p1,scrol s);
int collision_p2(SDL_Surface *back3,perso p2,scrol s1);

#endif
