#include "SDL.h"
#include <stdio.h>
#include <stdlib.h>

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
	SDL_Window* window = SDL_CreateWindow("SDL Tutoriall:)",
		SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,//用“100，100”就是自己确定窗口位置
		800, 600,
		SDL_WINDOW_SHOWN);
	SDL_Rect rect;
	rect.x = 100;
	rect.y = 100;
	
	SDL_Surface* surface = SDL_GetWindowSurface(window);
	SDL_Surface* image = SDL_LoadBMP("sample.bmp");
	SDL_BlitSurface(image, NULL, surface, &rect);
	SDL_UpdateWindowSurface(window);
	SDL_Delay(5000);
	SDL_DestroyWindow(window);
	SDL_Quit();
	printf_s("hello world");
	return 0;
	
}
