#include "SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include<SDL_image.h>
#include<stdbool.h>
#define Window_height 800
#define Window_width 600
SDL_Rect rect;
bool moveright = true;
bool movedown = true;
void updatepostion() {
	if (moveright == true) {
		rect.x++;
		if (rect.x + rect.w>= Window_width)
			moveright = false;
	}
	else
	{
		rect.x--;
		if (rect.x <= 0) {
			moveright = true;
		}
	}
	if (movedown == true) {
		rect.y++;
		if (rect.y + rect.h>= Window_height)
			movedown = false;
	}
	else
	{
		rect.y--;
		if (rect.y <= 0) {
			movedown = true;
		}
	}
}

int main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("gula", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		Window_width, Window_height,SDL_WINDOW_SHOWN);
	SDL_Renderer* rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_Surface* surface = SDL_LoadBMP("sample.bmp");
	SDL_Surface* black = SDL_LoadBMP("black.bmp");
	SDL_Texture* image = SDL_CreateTextureFromSurface(rend, surface);
	SDL_Texture* blackimage = SDL_CreateTextureFromSurface(rend,black);
	SDL_SetTextureBlendMode(image, SDL_BLENDMODE_BLEND);
	SDL_SetTextureBlendMode(blackimage, SDL_BLENDMODE_BLEND);
	SDL_SetTextureAlphaMod(blackimage, 50);
	rect.h = surface->h;
	rect.w = surface->w;
	rect.x = 0;
	rect.y = 0;
	SDL_Rect rectblack;
	rectblack.x = 0;
	rectblack.y = 0;
	rectblack.w = Window_width;
	rectblack.h = Window_height;
	SDL_Event event;
	bool desc = true;
	int alpha = 255;
	bool quit = false;
	while (!quit) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
			else if (event.type == SDL_MOUSEMOTION) {
				rect.x = event.motion.x - rect.w / 2;
				rect.y = event.motion.y - rect.h / 2;
			}
		}
		SDL_RenderClear(rend);
		SDL_SetTextureAlphaMod(image, alpha);
		SDL_RenderCopy(rend, image, NULL, &rect);
		SDL_RenderPresent(rend);
	/*	if (desc == true)
		{
			alpha--;
			if (alpha == 0) {
				desc = false;
			}
		}
		else
		{
			alpha++;
			if (alpha == 255) {
				desc = true;
			}
		}*/
		SDL_Delay(50);
	}
		SDL_DestroyWindow(window);
		return 0;

	/*SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* window = SDL_CreateWindow("never give up",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		Window_width, Window_height, SDL_WINDOW_SHOWN);
	SDL_Renderer* rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_Surface* image = SDL_LoadBMP("hywj.bmp");
	SDL_SetColorKey(image, SDL_TRUE, SDL_MapRGB(image->format, 6, 6, 6));
	SDL_Texture*texture= SDL_CreateTextureFromSurface(rend, image);
	int i;
	int imgwidth = image->w;
	int imgheight = image->h/5;
	SDL_Rect postion ;
	postion.x = 0;
	postion.y = 0;
	postion.w = imgwidth;
	postion.h = imgheight;
	SDL_Rect clips[5];
	bool quit = false;
	for (i = 0; i < 5; i++)
	{
		i = i % 5;
		clips[i].x = 0;
		clips[i].y = i * imgheight;
		clips[i].h = imgheight;
		clips[i].w = imgwidth;
		SDL_Event event;
		while (quit == false) {
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
					quit = true;
			}
		}
		SDL_Delay(100);
		SDL_RenderClear(rend);
		SDL_RenderCopy(rend, texture, &clips[i], &postion);
		SDL_RenderPresent(rend);
	}
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 0;*/
	/*// windows title , pos_x, pos_y, windows_size,windows mod.
	SDL_Window* window = SDL_CreateWindow("你好房辉", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		800, 600,
		SDL_WINDOW_FULLSCREEN);//全屏拉伸
	SDL_Delay(3000);
	SDL_DestroyWindow(window);//销毁窗口
	SDL_Quit();//退出
	return 0;*/
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
	/*SDL_Window* window = SDL_CreateWindow("fanghui",
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
	return 0;*/
	/*SDL_Window* window = SDL_CreateWindow("hello world",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		800, 600, SDL_WINDOW_SHOWN);
	SDL_Surface* surface = SDL_GetWindowSurface(window);
	SDL_Surface* image1 = SDL_LoadBMP("Pap.bmp");
	SDL_Surface* image2 = SDL_LoadBMP("sample.bmp");
	SDL_Surface* currentimage = image1;
	SDL_Event event;
	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;
	bool quit=false;

	while (quit==false)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				quit=true;
			}
			else if(event.type==SDL_MOUSEBUTTONDOWN)
			{
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					printf_s("left\n");
					currentimage = image1;
					SDL_FillRect(surface, NULL, 0);
					SDL_BlitSurface(currentimage, NULL, surface, &rect);
				}
				else if (event.button.button == SDL_BUTTON_RIGHT)
				{
					printf_s("right\n");
					currentimage = image2;
					SDL_FillRect(surface, NULL, 0);
					SDL_BlitSurface(currentimage, NULL, surface, &rect);
					SDL_UpdateWindowSurface(window);
					SDL_Delay(10);
				}
			}
			else if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_UP) {
					printf_s("keyup\n");
					rect.y = rect.y - 10;
				}
				else if (event.key.keysym.sym == SDLK_DOWN) {
					printf_s("keydown\n");
					rect.y = rect.y + 10;
				}
				else if (event.key.keysym.sym == SDLK_LEFT) {
					printf_s("keyleft\n");
					rect.x = rect.x - 10;
				}
				else if (event.key.keysym.sym == SDLK_RIGHT) {
					printf_s("keyright\n");
					rect.x = rect.x + 10;
				}
			}
			SDL_FillRect(surface, NULL, 0);
			SDL_BlitSurface(currentimage, NULL, surface, &rect);
			SDL_UpdateWindowSurface(window);
			SDL_Delay(10);
		}
	}
	SDL_FreeSurface(surface);
	SDL_DestroyWindow(window);
	SDL_Quit();*/
    /*SDL_Window* window = SDL_CreateWindow("hello darkness", 100, 100,
	Window_width,Window_height, SDL_WINDOW_SHOWN);
SDL_Renderer* rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
SDL_RenderClear(rend);
SDL_Surface* lanasurface = SDL_LoadBMP("sample.bmp");
SDL_Texture* lana = SDL_CreateTextureFromSurface(rend, lanasurface);
SDL_Surface* surface = SDL_GetWindowSurface(window);
SDL_Event event;
rect.x = 0;
rect.y = 0;
rect.h = lanasurface->h/2;
rect.w = lanasurface->w/2;
bool quit = false;
while (quit == false)
{
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT) {
			quit = true;
		}
	}
	updatepostion();
	SDL_Delay(5);
	SDL_RenderClear(rend);
	SDL_RenderCopy(rend, lana, NULL, &rect);
	SDL_RenderPresent(rend);
}
	SDL_DestroyWindow(window);
	SDL_Quit();*/

	
}




	
