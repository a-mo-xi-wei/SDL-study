#include<SDL.h>

/*
		1.包含目录配置  也就是头文件配置
		2.库目录配置，  lib库目录配置
		3.链接输入，	添加lib文件进去
		4.DLL环境变量配置 
*/


int main(int argc,char* argv[])
{
	//初始化资源
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		//错误获取
		SDL_Log("%s", SDL_GetError());
		return 0;
	}
	return 0;
}