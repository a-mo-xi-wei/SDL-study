#include<SDL.h>
SDL_Window* window = NULL;
SDL_Renderer* render1 = NULL;
void init_sdl()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		SDL_Log("%s", SDL_GetError());
		return;
	}
}

void render_shap()
{
	//SDL已经封装过了
	SDL_Point point = { 12,23 };
	SDL_Color color = { 0,0,0,0 };
	SDL_Rect rect = { 100,100,400,400 };
	//基本绘图函数
	SDL_SetRenderDrawColor(render1, color.r, color.g, color.b, color.a);
	SDL_RenderDrawPoint(render1, point.x,point.y);
	SDL_Point points[] = { 100,200,100,100,200,100,200,200 };
	SDL_RenderDrawPoints(render1, points,3);

	//SDL_RenderDrawLine(render1, 100, 100, 300, 300);
	SDL_RenderDrawLines(render1, points, 4);//逐一连接
	SDL_RenderDrawRect(render1, &rect);

	SDL_Rect fillrect = {0,0,100,100};
	SDL_SetRenderDrawColor(render1, 255, 0, 0, 0);
	SDL_RenderFillRect(render1, &fillrect);

	SDL_Rect rects[] = { 200,300,10,20,250,350,20,20 };
	SDL_RenderFillRects(render1, rects, 2);
}



int main(int argc,char *argv[])
{
	init_sdl();
	//创建窗口
	window = SDL_CreateWindow(u8"你干嘛，哎哟",200,200,800,800,SDL_WINDOW_SHOWN);
	//汉字乱码  ----->   使用u8;
	// 可创建多窗口
	//SDL_Window* window2 = SDL_CreateWindow(u8"你干嘛，哎哟", 500, 500, 400, 400, SDL_WINDOW_SHOWN);
	
	render1 = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);//默认设备为-1；

	//设置窗口颜色
	SDL_SetRenderDrawColor(render1, 0, 255, 0, 255);
	SDL_RenderClear(render1);

	//render_shap();

	SDL_RenderPresent(render1);


	//不能使用while死循环
	SDL_Delay(5000);//延时函数

	SDL_DestroyWindow(window);//销毁窗口

	return 0;
}