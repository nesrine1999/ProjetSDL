#ifndef INPUT_H_
#define INPUT_H_
#include "struct.h"
void input_t(SDL_Event event,char ch[10],pos *p);
int bounding_box(SDL_Rect Personnage,SDL_Rect Ennemi);
_Bool CollisionPixelMasque(image I,AABB box,int curseur_x,int curseur_y);
_Bool CollisionPixelAABB(AABB box,int curseur_x,int curseur_y);
#endif /* FONCTIONS_H_ */
