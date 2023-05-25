#pragma once
#include "myIncludes.h"
#include "myFunctions.h"

// 4 overloading functions below

void EKreyser(int* x, int* y, int* count, ushort arr[][10])
{
	int key = rand() % 4 + 1;
	if (key == 1)
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
	else if (key == 2)
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
	else if (key == 3)
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
	else if (key == 4)
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
void ELinkor(int* x, int* y, int* count, ushort arr[][10])
{
	int key = rand() % 4 + 1;
	if (key == 1)
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
	else if (key == 2)
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
	else if (key == 3)
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
	else if (key == 4)
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
void EEsminec(int* x, int* y, int* count, ushort arr[][10])
{
	int key = rand() % 4 + 1;
	if (key == 1)
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
	else if (key == 2)
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
	else if (key == 3)
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
	else if (key == 4)
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
void EKater(int* x, int* y, int* count, ushort arr[][10])
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

void Movement(int* x, int* y)
{
	int key = rand() % 10;
	*x = key;
	key = rand() % 10;
	*y = key;
}
// 4 overloading functions below

void EMovementAndPlacing(int* x, int* y, int* count, ushort arr[][10], int z)
{
	Movement(x, y);
	int key = rand() % 3 + 1;
	if (key == 1)
	{
		EKreyser(x, y, count, arr);
		*count -= 1;
	}
}
void EMovementAndPlacing(int* x, int* y, int* count, ushort arr[][10], long z)
{
	Movement(x, y);
	int key = rand() % 3 + 1;
	if (key == 1)
	{
		ELinkor(x, y, count, arr);
		*count -= 1;
	}
}
void EMovementAndPlacing(int* x, int* y, int* count, ushort arr[][10], double z)
{
	Movement(x, y);
	int key = rand() % 3 + 1;
	if (key == 1)
	{
		EEsminec(x, y, count, arr);
		*count -= 1;
	}
}
void EMovementAndPlacing(int* x, int* y, int* count, ushort arr[][10], float z)
{
	Movement(x, y);
	int key = rand() % 3 + 1;
	if (key == 1)
	{
		EKater(x, y, count, arr);
		*count -= 1;
	}
}

void EnemyPlacing(int* x, int* y, int* count, ushort arr[][10])
{
	while (*count == 10)
	{
		EMovementAndPlacing(x, y, count, arr, 1);
	}
	
	while (*count > 7)
	{
		EMovementAndPlacing(x, y, count, arr, 1l);

	}
	

	while (*count > 4)
	{
		EMovementAndPlacing(x, y, count, arr, 1e0);

	}
	

	while (*count > 0)
	{
		EMovementAndPlacing(x, y, count, arr, 1e0f);

	}

}
void EnemyFirstTurn(int* x, int* y, ushort arr[][10], int arr2[][10], int* count)
{
	while (true)
	{
		Movement(x, y);
		int key = rand() % 4 + 1;
		if (key == 1)
		{
			if ((arr[*x][*y] == 1))
			{
				arr2[*x][*y] = 1;
				*count -= 1;
				system("cls");
				return;
			}
			else if (arr[*x][*y] != 1)
			{
				system("cls");
				return;
			}
		}
	}
}

