#include <stdio.h>
#include <SDL/SDL.h>
int main()
{
#ifdef __DEGUG
	printf("Debug\n");
#endif
	SDL_Delay(100);
	return 0;
};
