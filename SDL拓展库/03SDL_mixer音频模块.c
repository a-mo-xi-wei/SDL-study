#include<stdio.h>
#include<SDL.h>
#include<stdbool.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<SDL_mixer.h>
#include<time.h>
SDL_Window* window = NULL;
SDL_Renderer* render = NULL;
Mix_Music* music = NULL;		//背景特效
Mix_Chunk* chunk = NULL;		//音效 
int volume = MIX_MAX_VOLUME;
void init_sdl()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2,1024);
}

void init_graph(int w, int h)
{
	window = SDL_CreateWindow("music", 100, 100, w, h, SDL_WINDOW_SHOWN);
	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
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
			case SDL_KEYDOWN:
				if (msg.key.keysym.sym =='=')//加号不行
				{
					printf("音量： %d\n", Mix_GetMusicVolume(music));
					volume < MIX_MAX_VOLUME-5 ? volume+=5 : volume;
					Mix_VolumeMusic(volume);
				}
				if (msg.key.keysym.sym == '-')
				{
					printf("音量： %d\n", Mix_GetMusicVolume(music));
					volume >5? volume-=5 : volume;
					Mix_VolumeMusic(volume);
				}
			case SDL_MOUSEBUTTONDOWN:
				/*if (msg.button.button == SDL_BUTTON_LEFT)
				{
					printf("音量： %d\n", Mix_GetMusicVolume(music));
					volume < MIX_MAX_VOLUME - 5 ? volume += 5 : volume;
					Mix_VolumeMusic(volume);
				}
				if (msg.button.button == SDL_BUTTON_RIGHT)
				{
					printf("音量： %d\n", Mix_GetMusicVolume(music));
					volume > 5 ? volume -= 5 : volume;
					Mix_VolumeMusic(volume);
				}*/
				if (msg.button.button == SDL_BUTTON_LEFT)
				{
					puts("左键按下\n");
					Mix_Pause(1);
				}
				if (msg.button.button == SDL_BUTTON_RIGHT)
				{
					puts("右键按下\n");
					Mix_Resume(1);
				}
			}
		}
		SDL_RenderClear(render);
		

		SDL_RenderPresent(render);
	}
}


int main(int argc, char* argv[])
{
	init_sdl();
	init_graph(800, 600);
	//音乐加载
	//music = Mix_LoadMUS("./1.mp3");
	//Mix_PlayMusic(music, -1);		//-1为无限循环
	//printf("音量： %d\n", Mix_GetMusicVolume(music));
	//printf("最大值： %d\n", MIX_MAX_VOLUME);
	chunk = Mix_LoadWAV("./2.mp3");
	Mix_PlayChannel(1, chunk, 0);

	event_loop();

	return 0;
}