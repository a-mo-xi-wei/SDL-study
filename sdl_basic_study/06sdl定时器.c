#include<SDL.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
SDL_Window* window = NULL;
SDL_Renderer* render = NULL;


void init_sdl()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		SDL_Log("%s", SDL_GetError());
	}
}

void init_graph(int w,int h)
{
	window = SDL_CreateWindow(u8"哦嗨哟学妹！", 100, 100, w, h, SDL_WINDOW_SHOWN);
	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
}

void event_loop()
{
	bool isRunning = true;
	while (isRunning)
	{
		SDL_Event msg;
		if (SDL_WaitEvent(&msg) != 0)
		{
			switch (msg.type)
			{
			case SDL_QUIT:
				isRunning = false;
				break;

			}
		}
	}
}
Uint32 print_test(Uint32 interval, void* param)
{
	printf("定时器触发！。。。\n");
	return interval;
}
int main(int argc, char* argv[])
{
	init_sdl();
	init_graph(800, 600);
	//定时器
	SDL_TimerID time_id = SDL_AddTimer(100, print_test, NULL);
	event_loop();
	SDL_RemoveTimer(time_id);
	 
	return 0;
}