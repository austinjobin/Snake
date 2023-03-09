// Snake-V1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Snake.h"
#include "conio.h"
int main()
{
	Snake game(0);
	std::cout << "welcome to snake press any key to continue or escape to restart anytime";
	while (!game.gameOver()||game.playagain()) {
		if (game.playagain())
		{
			system("cls");
			std::cout << "welcome to snake press any key to continue or escape to restart anytime";
			game.RESTART();

		}
		if (_kbhit()) {

			while (!game.gameOver()) {
				game.SNAKE();
			}
		}
	}
}
