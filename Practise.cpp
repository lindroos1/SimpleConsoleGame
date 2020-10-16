#include <windows.h> 
#include <stdio.h>
#include <Psapi.h>
HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
class Enemy
{
public:
	void Spawn(COORD Position)
	{
		wchar_t chr = 'x';
		DWORD saver;
		WriteConsoleOutputCharacter(Handle, L"x", 1, Position, &saver);
		
	}
	void CleanEnemy(COORD tl) 
	{
		char fill = ' ';
		CONSOLE_SCREEN_BUFFER_INFO s;
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
		GetConsoleScreenBufferInfo(console, &s);
		DWORD written, cells = tl.X * tl.Y;
		FillConsoleOutputCharacter(console, fill, cells, tl, &written);
	}
};

class  Player
{
public:
	void PlayerCreation(COORD coord)
	{
		
		if (SetConsoleCursorPosition(Handle, coord))
		{
			printf(".");
		}
	}
};

int main()
{
	Enemy NewEnemy; COORD EnemyPosition; EnemyPosition.Y = 10; EnemyPosition.X = 110; //object NewEnemy since it is an instance of Enemy
	Player Human;
	COORD HumanInitilaization; HumanInitilaization.X = 50; HumanInitilaization.Y = 11;
	Human.PlayerCreation(HumanInitilaization);
	
	while (true)
	{
		NewEnemy.CleanEnemy(EnemyPosition);
		if (GetKeyState(VK_F1) & 1)
		{
			NewEnemy.CleanEnemy(HumanInitilaization);
			HumanInitilaization.Y = 9; HumanInitilaization.X = 50;
			Human.PlayerCreation(HumanInitilaization);
			Sleep(45);
		}
		else
		{
			HumanInitilaization.Y = 10;
			Human.PlayerCreation(HumanInitilaization);
			Sleep(45);
		}
		NewEnemy.Spawn(EnemyPosition);
		EnemyPosition.X--;
		if (EnemyPosition.X == 0)
		{
			EnemyPosition.X = 110;
		}
		Sleep(80);
		if (HumanInitilaization.Y == 10 && EnemyPosition.X == 50)
			break;
	}
	printf("You have just lost ");
	getchar();
}