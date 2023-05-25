#pragma once
#include "myIncludes.h"
#include "EnemyFunctions.h"
#include "myFunctions.h"

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

void WaitAnimation()
{
	cout << "Wait";
	Sleep(1000);
	cout << '.';
	Sleep(1000);
	cout << '.';
	Sleep(1000);
	cout << '.';
	system("cls");
}
void LoadGame(ushort arr[][10], int ARR[][10], ushort arr2[][10], int ARR2[][10], int* PX, int* PY, int* PKey, int* PCount, int* PEnemyCount)
{
	FILE* file;
	fopen_s(&file, "save.txt", "r");
	fseek(file, 0, SEEK_SET);
	int count{};

	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			fseek(file, count, SEEK_SET);
			arr[i][j] = (char)getc(file);
			count++;
		}
	}
	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			if (arr[i][j] == 48) arr[i][j] = 0;
			else if (arr[i][j] == 49) arr[i][j] = 1;
		}
	}
	fseek(file, 100, SEEK_SET);
	*PCount = int(getc(file));
	fclose(file);
	if (*PCount <= 10)
	{
		YourPlacing(PX, PY, PKey, PCount, arr, arr2, ARR, ARR2);
		EnemyPlacing(PX, PY, PEnemyCount, arr2);
		*PX = 4, * PY = 4;
		WaitAnimation();

		*PCount = 1, * PEnemyCount = 20;

		while (true)
		{
			*PX = 4, * PY = 4;
			YourTurn(PX, PY, PKey, arr, ARR2, PCount);
			if (*PCount <= 0)
			{
				system("cls");
				cout << "You won";
				Sleep(5000);
				system("cls");
				return;
			}
			WaitAnimation();
			*PX = 4, * PY = 4;
			EnemyFirstTurn(PX, PY, arr2, ARR, PEnemyCount);
			if (*PEnemyCount <= 0)
			{
				system("cls");
				cout << "You lost";
				Sleep(5000);
				system("cls");
				return;
			}
		}
	}

}
void NewGame(ushort arr[][10], int ARR[][10], ushort arr2[][10], int ARR2[][10], int* PX, int* PY, int* PKey, int* PCount, int* PEnemyCount)
{
	YourPlacing(PX, PY, PKey, PCount, arr, arr2, ARR, ARR2);
	EnemyPlacing(PX, PY, PEnemyCount, arr2);

	*PX = 4, * PY = 4;
	WaitAnimation();
	*PCount = 1, *PEnemyCount = 1;
	while (*PEnemyCount > 0 && *PCount > 0)
	{
		*PX = 4, * PY = 4;
		YourTurn(PX, PY, PKey, arr2, ARR, PCount);
		WaitAnimation();
		*PX = 4, * PY = 4;
		EnemyFirstTurn(PX, PY, arr, ARR2, PEnemyCount);
	}
}
void Menu(ushort arr[][10], int ARR[][10], ushort arr2[][10], int ARR2[][10], int* PX, int* PY, int* PKey, int* PCount, int* PEnemyCount)
{
	auto count = 1;
	int key;
	while (true)
	{
		if (count == 1) SetConsoleTextAttribute(console, 2);
		cout << "New Game\n";
		SetConsoleTextAttribute(console, 15);
		if (count == 2) SetConsoleTextAttribute(console, 2);
		cout << "Load Game\n";
		SetConsoleTextAttribute(console, 15);
		if (count == 3) SetConsoleTextAttribute(console, 2);
		cout << "Exit\n";
		SetConsoleTextAttribute(console, 15);

		key = _getch();
		if (key == 'w' || key == 'W') count--;
		if (key == 's' || key == 'S') count++;
		if (count == 4) count = 3;
		if (count == 0) count = 1;
		if ((key == 'f' || key == 'F') && count == 1)
		{
			system("cls");
			WaitAnimation();
			NewGame(arr, ARR, arr2, ARR2, PX, PY, PKey, PCount, PEnemyCount);
		}
		if ((key == 'f' || key == 'F') && count == 2)
		{
			system("cls");
			WaitAnimation();
			LoadGame(arr, ARR, arr2, ARR2, PX, PY, PKey, PCount, PEnemyCount);
		}
		if ((key == 'f' || key == 'F') && count == 3)
		{
			system("cls");
			return;
		}

		Sleep(50);
		system("cls");
	}
}