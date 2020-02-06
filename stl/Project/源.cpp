#include "SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include<SDL_image.h>

int main(int argc, char* argv[]) {

	/*SDL_Init(SDL_INIT_VIDEO);
	// windows title , pos_x, pos_y, windows_size,windows mod.
	SDL_Window* window = SDL_CreateWindow("你好房辉", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		800, 600,
		SDL_WINDOW_FULLSCREEN);//全屏拉伸
	SDL_Delay(3000);
	SDL_DestroyWindow(window);//销毁窗口
	SDL_Quit();//退出
	return 0;*/

	SDL_Init(SDL_INIT_VIDEO);
	// windows title , pos_x, pos_y, windows_size,windows mod.
	/*SDL_Window* window = SDL_CreateWindow("Lana Del Ray", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		782, 900,
		SDL_WINDOW_SHOWN);
	SDL_Surface* surface = SDL_GetWindowSurface(window);

	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;
		SDL_Surface* image = SDL_LoadBMP("sample.bmp");

		SDL_BlitSurface(image, NULL, surface, &rect);

	SDL_UpdateWindowSurface(window);
	SDL_Delay(30000);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;*/
	SDL_Window* window = SDL_CreateWindow("fanghui",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		600, 800, SDL_WINDOW_SHOWN);
	SDL_Surface* surface = SDL_GetWindowSurface(window);
	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;
	SDL_Surface* image = SDL_LoadBMP("Pap.bmp");
	int i;
	for (i = 0; i < 10; i++)
	{
		SDL_BlitSurface(image, NULL, surface, &rect);
		rect.x = rect.x + 100;
		rect.y = rect.y + 100;
	}
	SDL_UpdateWindowSurface(window);
	SDL_Delay(5000);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}

	
