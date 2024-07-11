#include<SDL.h>
#include<stdio.h>
#include<stdbool.h>
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
	window = SDL_CreateWindow("img", 100, 100, w, h, SDL_WINDOW_SHOWN);
	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
}

void event_loop()
{
	bool isRunning = true;
	//加载图像不要写到循环中去
	SDL_Surface* img = SDL_LoadBMP("./girl.bmp");
	printf("w: %d  h: %d\n", img->w, img->h);
	SDL_Rect srcrect = { 0,0,img->w,img->h };
	SDL_Rect dstrect = { 0,0,300,300 };
	SDL_Texture* mm = SDL_CreateTextureFromSurface(render, img);
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
			case SDL_MOUSEBUTTONDOWN:
				if (msg.button.button == SDL_BUTTON_LEFT)
				{
					if (dstrect.w > 2 && dstrect.h > 2)
					{
						dstrect.w /= 2;
						dstrect.h /= 2;
					}
				}
				if (msg.button.button == SDL_BUTTON_RIGHT)
				{
					dstrect.w *= 2;
					dstrect.h *= 2;
				}
			}

		}
		//绘图不要写到消息处理中
		SDL_RenderCopy(render, mm,NULL,&dstrect);
		SDL_RenderPresent(render);
	}
}


int main(int argc,char* argv[])
{
	init_sdl();
	initgraph(619, 700);
	event_loop();
	return 0;
}




