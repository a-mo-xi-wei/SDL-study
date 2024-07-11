#include<stdio.h>
#include<SDL.h>
#include<stdbool.h>
#include<SDL_image.h>
#include<time.h>
SDL_Window* window = NULL;
SDL_Renderer* render = NULL;
SDL_Surface* face = NULL;
SDL_Rect src;
SDL_Rect dst;
IMG_Animation* action = NULL;
void init_sdl()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG); 
}

void init_graph(int w, int h)
{
	window = SDL_CreateWindow("img", 100, 100, w, h, SDL_WINDOW_SHOWN);
	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
}
//图像加载
void load_images()
{
	face = IMG_Load("./test.png");
	action = IMG_LoadAnimation("./test.gif");
	printf("帧数：%d\n", action->count);
	printf("宽度：%d  高度：%d\n", action->w,action->h);
	printf("频率：%d\n", *action->delays);
}
//显示图像
void render_face()
{
	SDL_Texture* temp = SDL_CreateTextureFromSurface(render, face);
	src = (SDL_Rect){ 0,0,face->w,face->h };
	dst = (SDL_Rect){ 0,0,face->w,face->h };
	SDL_RenderCopy(render, temp, &src, &dst);
	SDL_DestroyTexture(temp);
}
//定时器
bool on_timer(int duration)
{
	static int start = 0;
	if (start == 0)start = clock();

	int end = clock();
	if (end - start >= duration)
	{
		start = end;
		return true;
	}
	return false;
}
void render_action()
{
	static int frameNum = 0;
	SDL_Texture* temp = SDL_CreateTextureFromSurface(render, action->frames[frameNum]);
	src = (SDL_Rect){ 0,0,action->w,action->h};
	dst = (SDL_Rect){ 0,0,action->w,action->h};
	SDL_RenderCopy(render, temp, &src, &dst);
	SDL_DestroyTexture(temp);
	if (on_timer(*action->delays))
	{
		frameNum++;
		frameNum %= action->count;
	}
}
void event_loop()
{
	bool isRunning = true;
	while(isRunning)
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
		//绘图
		//render_face();
		render_action();
		SDL_RenderPresent(render);
	}
}


int main(int argc,char *argv[])
{
	init_sdl();
	load_images();
	init_graph(800, 600);
	event_loop();

	return 0;
}