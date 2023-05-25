#pragma once
#include "myIncludes.h"
#include "EnemyFunctions.h"

void showAndCheckFields(ushort arr[][10], int* x, int* y)
{
	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			if (*x == i && *y == j)
			{
				printf("\033[34m  X \033[0m");
			}	
			else if (arr[i][j] == 0)
			{
				
				printf("\033[38m  0 \033[0m");
			}
			else if (arr[i][j] == 1)
			{

				printf("\033[33m  1 \033[0m");
			}
		}
		cout << char(186) << '\n';
		for (size_t g = 0; g < 40; g++)
		{
			cout << ' ';
		};
		cout << char(186) << '\n';
	}
	for (size_t g = 0; g < 40; g++)
	{
		cout << char(205);
	}
	cout << char(188);
	cout << '\n' << '\t';
	printf("\033[35m  | Place your ships |\033[0m");
}
void SaveGame(ushort arr[][10], int* PX, int* PY, int* PCount)
{
	FILE* file;
	fopen_s(&file, "save.txt", "w");
	fseek(file, 0, SEEK_SET);
	int count{};

	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			fseek(file, count, SEEK_SET);
			if (arr[i][j] == 1) putc(49, file);
			else if (arr[i][j] == 0) putc(48, file);
			count++;
		}
	}
	fseek(file, 100 , SEEK_SET);
	putc(*PCount, file);
	fclose(file);
}

bool KaterCheck(int* x, int* y, ushort arr[][10])
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			if (arr[*x - 1 + j][*y - i + 1] == 1) return true;
		}
	}
	return false;
}
bool ShipCheck(int* x, int* y, ushort arr[][10], int z)
{
	if (*y < z - 1) return true;
	for (size_t j = 0; j < 3; j++)
	{
		for (size_t i = 0; i < z + 2; i++)
		{
			if (arr[*x - 1 + j][*y - i + 1] == 1) return true;
		}
	}
	return false;
}
bool ShipCheck(int* x, int* y, ushort arr[][10], long z)
{
	if (*y > 10 - z) return true;
	for (size_t j = 0; j < 3; j++)
	{
		for (size_t i = 0; i < z + 2; i++)
		{
			if (arr[*x - 1 + j][*y + i - 1] == 1) return true;
		}
	}
	return false;
}
bool ShipCheck(int* x, int* y, ushort arr[][10], double z)
{
	if (*x > 10 - z) return true;
	for (size_t j = 0; j < 3; j++)
	{
		for (size_t i = 0; i < z + 2; i++)
		{
			if (arr[*x + i - 1][*y - 1 + j] == 1) return true;
		}
	}
	return false;
}
bool ShipCheck(int* x, int* y, ushort arr[][10], float z)
{
	if (*x < z - 1) return true;
	for (size_t j = 0; j < 3; j++)
	{
		for (size_t i = 0; i < z + 2; i++)
		{
			if (arr[*x - i + 1][*y - 1 + j] == 1) return true;
		}
	}
	return false;
}

void Kreyser(int* x, int* y, int* count, ushort arr[][10])
{
	int key = 0;
	key = _getch();
	if (key == 'a' || key == 'A')
	{
		if (ShipCheck(x, y, arr, 4))
		{
			*count += 1;
			return;
		}
		for (size_t i = 0; i < 4; i++)
		{
			arr[*x][*y - i] = 1;
		}
	}
	else if (key == 'd' || key == 'D')
	{
		if (ShipCheck(x, y, arr, 4l))
		{
			*count += 1;
			return;
		}
		for (size_t i = 0; i < 4; i++)
		{
			arr[*x][*y + i] = 1;
		}
	}
	else if (key == 's' || key == 'S')
	{
		if (ShipCheck(x, y, arr, 4e0))
		{
			*count += 1;
			return;
		}
		for (size_t i = 0; i < 4; i++)
		{
			arr[*x + i][*y] = 1;
		}
	}
	else if (key == 'w' || key == 'W')
	{
		if (ShipCheck(x, y, arr, 4e0f))
		{
			*count += 1;
			return;
		}
		for (size_t i = 0; i < 4; i++)
		{
			arr[*x - i][*y] = 1;
		}
	}
	else
		*count += 1;
}
void Linkor(int* x, int* y, int* count, ushort arr[][10])
{
	int key = 0;
	key = _getch();
	if (key == 'a' || key == 'A')
	{
		if (ShipCheck(x, y, arr, 3))
		{
			*count += 1;
			return;
		}
		for (size_t i = 0; i < 3; i++)
		{
			arr[*x][*y - i] = 1;
		}
	}
	else if (key == 'd' || key == 'D')
	{
		if (ShipCheck(x, y, arr, 3l))
		{
			*count += 1;
			return;
		}
		for (size_t i = 0; i < 3; i++)
		{
			arr[*x][*y + i] = 1;
		}
	}
	else if (key == 's' || key == 'S')
	{
		if (ShipCheck(x, y, arr, 3e0))
		{
			*count += 1;
			return;
		}
		for (size_t i = 0; i < 3; i++)
		{
			arr[*x + i][*y] = 1;
		}
	}
	else if (key == 'w' || key == 'W')
	{
		if (ShipCheck(x, y, arr, 3e0f))
		{
			*count += 1;
			return;
		}
		for (size_t i = 0; i < 3; i++)
		{
			arr[*x - i][*y] = 1;
		}
	}
	else
		*count += 1;
}
void Esminec(int* x, int* y, int* count, ushort arr[][10])
{
	int key = 0;
	key = _getch();
	if (key == 'a' || key == 'A')
	{
		if (ShipCheck(x, y, arr, 2))
		{
			*count += 1;
			return;
		}
		for (size_t i = 0; i < 2; i++)
		{
			arr[*x][*y - i] = 1;
		}
	}
	else if (key == 'd' || key == 'D')
	{
		if (ShipCheck(x, y, arr, 2l))
		{
			*count += 1;
			return;
		}
		for (size_t i = 0; i < 2; i++)
		{
			arr[*x][*y + i] = 1;
		}
	}
	else if (key == 's' || key == 'S')
	{
		if (ShipCheck(x, y, arr, 2e0))
		{
			*count += 1;
			return;
		}
		for (size_t i = 0; i < 2; i++)
		{
			arr[*x + i][*y] = 1;
		}
	}
	else if (key == 'w' || key == 'W')
	{
		if (ShipCheck(x, y, arr, 2e0f))
		{
			*count += 1;
			return;
		}
		for (size_t i = 0; i < 2; i++)
		{
			arr[*x - i][*y] = 1;
		}
	}
	else
		*count += 1;
}
void Kater(int* x, int* y, int* count, ushort arr[][10])
{
	if (arr[*x][*y] == 1)
	{
		*count += 1;
		return;
	}
	else if (KaterCheck(x, y, arr))
	{
		*count += 1;
		return;
	}
	arr[*x][*y] = 1;
}
void Movement(int* x, int* y, int* key, ushort arr[][10])
{
	*key = _getch();
	if (*x < 0) *x = 0;
	if (*x > 9) *x = 9;
	if (*y < 0) *y = 0;
	if (*y > 9) *y = 9;
	if (*key == 'w' || *key == 'W') *x -= 1;
	if (*key == 's' || *key == 'S') *x += 1;
	if (*key == 'd' || *key == 'D') *y += 1;
	if (*key == 'a' || *key == 'A') *y -= 1;
}

// 4 overloading functions below

void MovementAndPlacing(int* x, int* y, int* key, int* count, ushort arr[][10], int z)
{
	Movement(x, y, key, arr);
	if (*key == 'f' || *key == 'F')
	{
		Kreyser(x, y, count, arr);
		*count -= 1;
		SaveGame(arr, x, y, count);
	}
}
void MovementAndPlacing(int* x, int* y, int* key, int* count, ushort arr[][10], long z)
{
	Movement(x, y, key, arr);
	if (*key == 'f' || *key == 'F')
	{
		Linkor(x, y, count, arr);
		*count -= 1;
		SaveGame(arr, x, y, count);
	}
}
void MovementAndPlacing(int* x, int* y, int* key, int* count, ushort arr[][10], double z)
{
	Movement(x, y, key, arr);
	if (*key == 'f' || *key == 'F')
	{
		Esminec(x, y, count, arr);
		*count -= 1;
		SaveGame(arr, x, y, count);
	}
}
void MovementAndPlacing(int* x, int* y, int* key, int* count, ushort arr[][10], float z)
{
	Movement(x, y, key, arr);
	if (*key == 'f' || *key == 'F')
	{
		Kater(x, y, count, arr);
		*count -= 1;
		SaveGame(arr, x, y, count);
	}
}

void YourPlacing(int* x, int* y, int* key, int* count, ushort arr[][10], ushort arr2[][10], int ARR[][10], int ARR2[][10])
{
	while (*count == 10)
	{
		showAndCheckFields(arr, x, y);
		MovementAndPlacing(x, y, key, count, arr, 1);
		system("cls");
	}

	while (*count > 7)
	{
		showAndCheckFields(arr, x, y);
		MovementAndPlacing(x, y, key, count, arr, 1l);
		system("cls");
	}


	while (*count > 4)
	{
		showAndCheckFields(arr, x, y);
		MovementAndPlacing(x, y, key, count, arr, 1e0);
		system("cls");
	}

	while (*count > 0)
	{
		showAndCheckFields(arr, x, y);
		MovementAndPlacing(x, y, key, count, arr, 1e0f);
		system("cls");
	}
}
void GameScreen(int arr2[][10], ushort arr[][10], int* x, int* y)
{
	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			if (*x == i && *y == j)
			{
				printf("\033[34m  X \033[0m");
			}
			else if (arr2[i][j] == 1 && arr[i][j] == 0)
			{

				printf("\033[33m  0 \033[0m");
			}
			else if (arr2[i][j] == 1)
			{

				printf("\033[33m  1 \033[0m");
			}
			else if (arr2[i][j] == 0)
			{

				printf("\033[38m  0 \033[0m");
			}
		}
		cout << char(186) << '\n';
		for (size_t g = 0; g < 40; g++)
		{
			cout << ' ';
		};
		cout << char(186) << '\n';
	}
	for (size_t g = 0; g < 40; g++)
	{
		cout << char(205);
	}
	cout << char(188);
	cout << '\n' << '\t';
	printf("\033[35m  | Sink Enemy ships |\033[0m");
}
void YourTurn(int* x, int* y, int* key, ushort arr[][10], int arr2[][10], int* count)
{
	while (true)
	{
		GameScreen(arr2,arr, x, y);
		Movement(x, y, key, arr);
		system("cls");
		if (*key == 'f' || *key == 'F')
		{
			if ((arr[*x][*y] == 1))
			{
				if ((arr2[*x][*y] == 0))
				{
					*count -= 1;
					system("cls");
					continue;
					return;
				}
				else
					continue;
			}
			else
				arr2[*x][*y] = 1;
				return;
		}
	}
}



