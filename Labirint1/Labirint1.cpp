// Labirint1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include "iostream"


const int InaltimeLabirint = 20;
const int LatimeLabirint = 20;

char Labirint[InaltimeLabirint][LatimeLabirint + 1] =
{
	"# #############",
	"#     ######  #",
	"# ### ####### #",
	"# #   ####### #",
	"# # # ####### #",
	"#   # # ##### #",
	"# ### # ##### #",
	"#   #   ##### #",
	"####### ##### #",
};

const char Zid = '#';
const char DrumLiber = ' ';
const char Cale = '*';

class COORDONATE
{
public:
	int X;
	int Y;
	COORDONATE(int x = 0, int y = 0) { X = x, Y = y; }
	COORDONATE(const COORDONATE &coordonate) { X = coordonate.X; Y = coordonate.Y; }
};

COORDONATE PunctDeStart(1, 0);
COORDONATE PunctDeSfarsit(7, 8);

void IncarcaLabirint()
{
	for (int Y = 0; Y < InaltimeLabirint; Y++)
	{
		printf("%s\n", Labirint[Y]);
	}
	printf("\n");
}

bool Rezolva(int X, int Y)
{
	// Make the move (if it's wrong, we will backtrack later.
	Labirint[Y][X] = Cale;

	// If you want progressive update, uncomment these lines...
	//IncarcaLabirint();
	//Sleep(50);

	// Check if we have reached our goal.
	if (X == PunctDeSfarsit.X && Y == PunctDeSfarsit.Y)
	{
		return true;
	}

	// Recursively search for our goal.
	if (X > 0 && Labirint[Y][X - 1] == DrumLiber && Rezolva(X - 1, Y))
	{
		return true;
	}
	if (X < LatimeLabirint && Labirint[Y][X + 1] == DrumLiber && Rezolva(X + 1, Y))
	{
		return true;
	}
	if (Y > 0 && Labirint[Y - 1][X] == DrumLiber && Rezolva(X, Y - 1))
	{
		return true;
	}
	if (Y < InaltimeLabirint && Labirint[Y + 1][X] == DrumLiber && Rezolva(X, Y + 1))
	{
		return true;
	}

	// Otherwise we need to backtrack and find another solution.
	Labirint[Y][X] = DrumLiber;

	// If you want progressive update, uncomment these lines...
	//IncarcaLabirint();
	//Sleep(50);
	return false;
}

int main()
{
	printf("Caut solutie la urmatorul labirint \n");
	IncarcaLabirint();
	char raspuns;
	if (Rezolva(PunctDeStart.X, PunctDeStart.Y))
	{
		printf("Solutie optima gasita.Doriti sa afisez solutia? Y/N:");
		scanf("%c", &raspuns);
		if (raspuns == 'Y' || raspuns == 'y') {
			printf("Afisez solutia : \n");
			IncarcaLabirint();
		}
		else {
			printf("OK.Ies din program\n");
		}
		
	}
	else
	{
		printf("Nu exista solutie de iesire din labirint\n");
	}
	system("pause");

	return 0;
}