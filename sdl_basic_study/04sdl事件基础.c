#include<SDL.h>
#include<stdbool.h>
#include<stdio.h>
SDL_Window* window = NULL;
SDL_Renderer* render = NULL;

void init_sdl()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		SDL_Log("%s", SDL_GetError());
		return;
	}
}

void initgraph(int w, int h)
{
	window = SDL_CreateWindow("event", 100, 100, w, h, SDL_WINDOW_SHOWN);
	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

}

void event_loop()
{
	bool isRunning = true;
	while (isRunning)
	{
		SDL_Event msg;
		if (/*SDL_WaitEvent*/SDL_PollEvent(&msg) != 0)
		{
			switch (msg.type)
			{
			case SDL_QUIT:			//窗口关闭  （×号）
				isRunning = false;
				break;
			case SDL_KEYDOWN:		//按键事件
				//按ESC关闭窗口
				printf("KeyDown: %c\n", msg.key.keysym.sym);
				if (msg.key.keysym.sym == SDLK_ESCAPE)
					isRunning = false;

				break;
			case SDL_MOUSEMOTION:
				//printf("鼠标移动-------\n");
				break;
			case SDL_MOUSEBUTTONDOWN:
				if (msg.button.button == SDL_BUTTON_LEFT)
				{
					printf("左键按下坐标：%d  %d\n", msg.motion.x, msg.motion.y);
				}
				if (msg.button.button == SDL_BUTTON_RIGHT)
				{
					printf("右键按下坐标：%d  %d\n", msg.motion.x, msg.motion.y);
				}
				break;
			case SDL_MOUSEBUTTONUP:
				break;
			}
		}
	}
}

int main(int argc, char* argv[])
{
	init_sdl();
	initgraph(800, 600);
	//SDL_Delay(4000);
	event_loop();
	return 0;
}