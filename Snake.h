#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
class Snake
{
private:
	bool GAMEOVER{};
	int score_int{};
	int length{};
	bool play{};
	int tailarraysize{};
	bool tailflag{};
	std::string first_name_str;
	std::string rank_str;
	std::string last_name_str;
	std::string Sscore;
	std::stringstream ss;
	std::string outstr;
	struct GameSize {
		int width{};
		 int height{};
	};
	GameSize SIZE;
	struct Head {
		int x{};
		int y{};
	};
	struct tail {
	 int* Tx;
	 int* Ty;
	};
	Head Hpos;
	tail Tpos;
	struct Fruit {
		int frX{};
		int frY{};
	};
	Fruit Fpos;
	struct HIGHSCORE {
		std::vector<std::string> rank;
		std::vector<std::string> first_name;
		std::vector<std::string> last_name;
		std::vector<std::string> score;
	};
	HIGHSCORE Hlist;
	HIGHSCORE NHlist;
	enum class eDirection {
		STOP,
		FORWARD,
		BACKWARDS,
		LEFT,
		RIGHT,
	};
	eDirection dir;
	void size(int x);
	void draw();
	void input();
	void logic();
	void movment();
	void colision();
	void eat();
	void grow();
	void game_over_screen();
	void writeHighScore();
	int stringtoint(std::string str);
	std::string inttostring(int num);
	std::string HighScore();
	std::string getfirst_name();
	std::string getrank();
	std::string getlast_name();
	std::string getSscore();
	std::stringstream getstream();
	std::string getoutstr();
public:
	Snake(int x);
	void SNAKE();
	bool gameOver();
	bool playagain();
	void RESTART();
};
