#ifndef ENIGMES_H_INCLUDED
#define ENIGMES_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h> 

typedef struct enigme
{
    char * Question1, * Answer1, *Answer2 , * Answer3;
	SDL_Surface *Question,*Reponse1,*Reponse2,*Reponse3;
    SDL_Rect QuestionPos, Answer1Pos, Answer2Pos, Answer3Pos ;
    TTF_Font *Font;
	
    int InputUser, solution;
} enigme;

enigme Init_Enigme();

enigme Generate_Enigme(enigme e);

int Resolution(enigme e,int x);

void affichage_Enigme(enigme e,SDL_Surface *ecran);

char * Replace_Hyphen(char *str);



#endif // ENIGMES_H_INCLUDED
