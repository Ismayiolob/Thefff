#pragma once
#include "myIncludes.h"
#include "Menu.h"

int main()
{
	srand(time(NULL));
	const ushort ArrLength = 10;

	ushort Field[ArrLength][ArrLength]{};
	int FieldArrCheck[ArrLength][ArrLength]{};


	auto X = 4, Y = 4, Key = 0, Count = 10;  //PlayerInit
	int* PX = &X, * PY = &Y;
	int* Pkey = &Key, * PCount = &Count;


	int EnemyCount = 10, * PEnemyCount = &EnemyCount;  //EnemyInit

	
	ushort EnemyField[ArrLength][ArrLength]{};
	int EnemyFieldArrCheck[ArrLength][ArrLength]{};
	Menu(Field, FieldArrCheck, EnemyField, EnemyFieldArrCheck, PX, PY, Pkey, PCount, PEnemyCount);

	return 0;
}