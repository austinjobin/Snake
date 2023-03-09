#pragma once
class Snake
{
private:
	bool GAMEOVER{};
	int score{};
	int length{};
	bool play{};
	int tailarraysize{};
	bool tailflag{};
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
	
public:
	Snake(int x);
	void SNAKE();
	bool gameOver();
	bool playagain();
	void RESTART();
};
