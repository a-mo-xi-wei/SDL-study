#include<SDL.h>
SDL_Window* window1 = NULL;
SDL_Renderer* render1 = NULL;
void sdl_init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		SDL_Log("%s", SDL_GetError());
		return;
	}
}
void render_shape()
{
	//SDL封装的类型
	SDL_Point point = { 100,100 };
	SDL_Color color = { 0,0,0,0 };
	SDL_Rect rect = { 100,100,400,400 };
	//基本绘图函数
	SDL_SetRenderDrawColor(render1, color.r, color.g, color.b, color.a);
	SDL_RenderDrawPoint(render1, point.x, point.y);
	SDL_Point points[] = { 100,200,300,400,500,600 };
	SDL_RenderDrawPoints(render1, points, 3);
	SDL_RenderDrawLine(render1, 100, 100, 300, 300);


}

void SDL_RenderDrawCircle(SDL_Renderer* render1)
{
	SDL_Color color = { 0,0,0,0 };
	SDL_SetRenderDrawColor(render1, color.r, color.g, color.b, color.a);
	//设置圆心
	SDL_Point point = { 300,300 };
	//设置半径
	int len = 200;
	//开始画圆
	for (float angle = 0.0; angle < 360; angle += 0.001)
	{
		SDL_RenderDrawPoint(render1, point.x + len * SDL_cosf(angle), point.y + len * SDL_sinf(angle) / 5);
		SDL_RenderDrawPoint(render1, point.x + len * SDL_cosf(angle) / 5, point.y + len * SDL_sinf(angle));
		SDL_RenderDrawPoint(render1, point.x + len * SDL_cosf(angle), point.y + len * SDL_sinf(angle) / 4);
		SDL_RenderDrawPoint(render1, point.x + len * SDL_cosf(angle) / 4, point.y + len * SDL_sinf(angle));
		SDL_RenderDrawPoint(render1, point.x + len * SDL_cosf(angle), point.y + len * SDL_sinf(angle) / 3);
		SDL_RenderDrawPoint(render1, point.x + len * SDL_cosf(angle) / 3, point.y + len * SDL_sinf(angle));
		SDL_RenderDrawPoint(render1, point.x + len * SDL_cosf(angle), point.y + len * SDL_sinf(angle) / 2);
		SDL_RenderDrawPoint(render1, point.x + len * SDL_cosf(angle) / 2, point.y + len * SDL_sinf(angle));
		SDL_RenderDrawPoint(render1, point.x + len * SDL_cosf(angle), point.y + len * SDL_sinf(angle) / 6);
		SDL_RenderDrawPoint(render1, point.x + len * SDL_cosf(angle) / 6, point.y + len * SDL_sinf(angle));
	}
}

int main(int argc, char* argv[])
{
	sdl_init();
	window1 = SDL_CreateWindow(u8"我的世界", 100, 100, 800, 600, 0);
	//汉字乱码：使用u8
	//SDL_Window* window2 = SDL_CreateWindow("test", 200, 200, 400, 300, 0);
	render1 = SDL_CreateRenderer(window1, -1, SDL_RENDERER_SOFTWARE);
	//设置窗口颜色
	SDL_SetRenderDrawColor(render1, 0, 255, 0, 255);
	SDL_RenderClear(render1);			//刷新
	render_shape();
	SDL_RenderDrawCircle(render1);
	SDL_RenderPresent(render1);			//显示
	//不能用while循环
	SDL_Delay(3000);//延时函数
	SDL_DestroyWindow(window1);//销毁窗口
	return 0;
}