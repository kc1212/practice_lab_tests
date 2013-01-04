#include <SDL/SDL.h>

int main(void){

  SDL_Surface* hello = NULL;
  SDL_Surface* screen = NULL;

  SDL_Init(SDL_INIT_EVERYTHING);
  screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);

  hello = SDL_LoadBMP("helloworld.bmp");

  //Apply image to screen
  SDL_BlitSurface( hello, NULL, screen, NULL );

  //Update Screen
  SDL_Flip( screen );

  //Pause
  SDL_Delay( 2000 );

  //Free the loaded image
  SDL_FreeSurface( hello );


  SDL_Quit();

  return 0;

}
