#include<stdio.h>
#include<SDL.h>
#include<stdbool.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<time.h>
SDL_Window* window = NULL;
SDL_Renderer* render = NULL;
SDL_Surface* face = NULL;
TTF_Font* font = NULL;
SDL_Rect src;
SDL_Rect dst;
void init_sdl() 
{
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
}

void init_graph(int w, int h)
{
	window = SDL_CreateWindow("ttf", 100, 100, w, h, SDL_WINDOW_SHOWN);
	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
}

void render_text(int x, int y, const char* text, SDL_Color color)
{
	font = TTF_OpenFont("./test.ttf", 100);
	SDL_Surface* ts = TTF_RenderText_Blended(font, text, color);
	SDL_Texture* tt = SDL_CreateTextureFromSurface(render, ts);
	dst = (SDL_Rect){x,y,ts->w,ts->h };
	SDL_RenderCopy(render, tt, NULL, &dst);
	SDL_DestroyTexture(tt);
	TTF_CloseFont(font);
}

void event_loop()
{
	bool isRunning = true;
	while (isRunning)
	{
		SDL_Event msg;
		if (SDL_PollEvent(&msg) != 0)
		{
			switch (msg.type)
			{
			case SDL_QUIT:
				isRunning = false;
				break;

			}
		}
		SDL_RenderClear(render);
		SDL_Color color = { 0,255,0,0 };
		render_text(100, 100, "I Love You", color);
		SDL_RenderPresent(render);
	}
}


int main(int argc, char* argv[])
{
	init_sdl();
	init_graph(800, 600);
	event_loop();

	return 0;
}