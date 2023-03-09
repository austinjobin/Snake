#include "Snake.h"
#include <iostream>
#include <conio.h>
#include<windows.h>
Snake::Snake(int x) {
	
	GAMEOVER = 0;
	length = 0;
	play = 0;
	tailflag = 0;
	tailarraysize = 5;
	size(x);
	dir = eDirection::STOP;
	Hpos.x = SIZE.width/2;
	Hpos.y = SIZE.height/2;
	Fpos.frX = rand() % (SIZE.width-2)+1;
	Fpos.frY = rand() % (SIZE.height-2)+1;
	score = 0;
	srand(time(NULL));
	Tpos.Tx = new int[tailarraysize] {};
	Tpos.Ty = new int[tailarraysize] {};

}
void Snake::SNAKE()
{
	draw();
	input();
	logic();
	Sleep(100);
}
void Snake::size(int x) 
{
	switch (x) {
	case 0:
		SIZE.height = 20;
		SIZE.width = 20;
		break;

	case 1:
		SIZE.height = 40;
		SIZE.width = 40;
		break;

	case 2:
		SIZE.height = 80;
		SIZE.width = 80;
		break;

	case 3:
		SIZE.height = 160;
		SIZE.width = 160;
		break;
	}
}


void Snake::draw()
{
	system("cls");
	for (int i = 0; i < SIZE.width; i++) {
		std::cout << "# ";
	}
	std::cout << std::endl;
	for (int i = 1; i < SIZE.height - 1; i++) {
		for (int j = 0; j< SIZE.width; j++) {
			if (((j == 0) || (j == SIZE.width-1 )))
				std::cout << "# ";
			else if ((j == Hpos.x) && (i == Hpos.y))
				std::cout << "0 ";
			else if ((j == Fpos.frX) && (i == Fpos.frY))
				std::cout << "F ";
			else
			{
				for (int p=0; p < length; p++) {
					if((Tpos.Tx[p]==j)&&(Tpos.Ty[p]==i))
					{
						std::cout << "o ";
						tailflag = 1;
						break;
					}
				}
				if(!tailflag)
				std::cout << "  ";
				tailflag = 0;
			}
		}
		std::cout << std::endl;
	}
	for (int i = 0; i < SIZE.width; i++) {
		std::cout << "# ";
	}
	std::cout << std::endl << "Score: " << score;
}

void Snake::input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			if ((dir != eDirection::RIGHT) || (length == 0))
				dir = eDirection::LEFT;
			break;

		case 's':
			if ((dir != eDirection::FORWARD) || (length == 0))
				dir = eDirection::BACKWARDS;
			break;

		case 'd':
			if ((dir != eDirection::LEFT)||(length==0))
			dir = eDirection::RIGHT;
			break;

		case 'w':
			if ((dir != eDirection::BACKWARDS)||(length==0))
			dir = eDirection::FORWARD;
			break;
		case 27:
			GAMEOVER = 1;
			break;

		case 0xE0:
		case 0:
			switch (_getch())
			{
			case 75:
				if ((dir != eDirection::RIGHT) || (length == 0))
				dir = eDirection::LEFT;
				break;

			case 80:
				if ((dir != eDirection::FORWARD) || (length == 0))
				dir = eDirection::BACKWARDS;
				break;

			case 77:
				if ((dir != eDirection::LEFT) || (length == 0))
				dir = eDirection::RIGHT;
				break;

			case 72:
				if ((dir != eDirection::BACKWARDS) || (length == 0))
				dir = eDirection::FORWARD;
				break;

			}
			break;
	}
	}
}

void Snake::logic()
{
	grow();
	movment();
	colision();
	eat();
	game_over_screen();
}
void Snake::grow()
{
	if (length - 1 == tailarraysize) {
		tailarraysize *= 3;
		int* new_table = new int[tailarraysize];
		int* new_table2 = new int[tailarraysize];

		for (int i = 0; i < length; i++)
		{
			new_table[i] = Tpos.Tx[i];
			new_table2[i] = Tpos.Ty[i];
		}
		for (int i = length; i < tailarraysize; i++) {
			new_table[i] = 0;
			new_table2[i] = 0;
		}
		delete[] Tpos.Tx;
		delete[] Tpos.Ty;
		Tpos.Tx = new_table;
		Tpos.Ty = new_table2;
	}
	for (int i = length-1; i >=0; i--)
	{
		if (i == 0)
		{
			Tpos.Tx[i] = Hpos.x;
			Tpos.Ty[i] = Hpos.y;
		}
		if ((i > 0))
		{
			
			Tpos.Tx[i] = Tpos.Tx[i-1];
			Tpos.Ty[i] = Tpos.Ty[i-1];
		}
		
		

	}
}
void Snake::movment()
{
	switch (dir)
	{
	case eDirection::FORWARD:
		Hpos.y--;
		break;

	case eDirection::BACKWARDS:
		Hpos.y++;
		break;

	case eDirection::LEFT:
		Hpos.x--;
		break;

	case eDirection::RIGHT:
		Hpos.x++;
		break;
	}
}
void Snake::colision()
{
	if (Hpos.x >= SIZE.width - 1)
		Hpos.x = 1;
	if (Hpos.y >= SIZE.height - 1)
		Hpos.y = 1;
	if (Hpos.x <= 0)
		Hpos.x = SIZE.width - 2;
	if (Hpos.y <= 0)
		Hpos.y = SIZE.height - 2;
	for (int i = 0; i < length; i++)
	{
		if ((Hpos.x == Tpos.Tx[i]) && (Hpos.y == Tpos.Ty[i])) {
			GAMEOVER = 1;
			break;
		}
	}
}
void Snake::eat()
{
	if ((Hpos.x == Fpos.frX) && (Hpos.y == Fpos.frY))
	{
		score += 10;
		Fpos.frX = rand() % (SIZE.width - 2) + 1;
		Fpos.frY = rand() % (SIZE.height - 2) + 1;
		++length;
	}
}
void Snake::game_over_screen()
{
	if (GAMEOVER) {
		system("cls");
		std::cout << "GAME OVER\nSCORE: "<<score<<"\nWould you like to play again ? Y / N\n";
		char responce{};
		std::cin >> responce;
		if ((responce == 'y') || (responce == 'Y')) {
			play = 1;
		}
}
}
bool Snake::gameOver()
{
	return GAMEOVER;
}
bool Snake::playagain()
{
	return play;
}
void Snake::RESTART()
{
	GAMEOVER = 0;
	length = 0;
	play = 0;
	tailflag = 0;
	tailarraysize = 5;
	size(0);
	dir = eDirection::STOP;
	Hpos.x = SIZE.width / 2;
	Hpos.y = SIZE.height / 2;
	Fpos.frX = rand() % (SIZE.width - 2) + 1;
	Fpos.frY = rand() % (SIZE.height - 2) + 1;
	score = 0;
	srand(time(NULL));
	Tpos.Tx = new int[tailarraysize] {};
	Tpos.Ty = new int[tailarraysize] {};
}