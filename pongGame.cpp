#include <iostream>
#include <time.h>
#include <conio.h>
#include <Windows.h>

enum eDir { STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6 };

class Cball
{
private:
	int x, y;
	int originalX, originalY;
	eDir direction;

public:
	Cball(int posX, int posY)
	{
		originalX = posX;
		originalY = posY;
		x = posX; y = posY;
		direction = STOP;
	}

	void reset()
	{
		x = originalX; y = originalY;
		direction = STOP;
	}

	void changeDirection(eDir d)
	{
		direction = d;
	}

	void randomDirection()
	{
		direction = (eDir)((rand() % 6) + 1);
	}

	inline int getX() { return x; }

	inline int getY() { return y; }

	inline eDir getDirection() { return direction; }

	void move()
	{
		switch (direction)
		{
		case STOP:
			break;
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case UPLEFT:
			x--; y--;
			break;
		case DOWNLEFT:
			x--; y++;
			break;
		case UPRIGHT:
			x++; y--;
			break;
		case DOWNRIGHT:
			x++; y++;
			break;
		default:
			break;
		}
	}

	friend std::ostream & operator<<(std::ostream& o, Cball c)
	{
		o << "Ball[" << c.x << "," << c.y << "][" << c.direction << "]";
		return o;
	}
};

class Cpaddle
{
private:
	int x, y;
	int originalX, originalY;

public:
	Cpaddle()
	{
		x = y = 0;
	}

	Cpaddle(int posX, int posY) : Cpaddle()
	{
		originalX = posX;
		originalY = posY;
		x = posX; y = posY;
	}

	inline void reset() { x = originalX, y = originalY; }

	inline int getX() { return x; }

	inline int getY() { return y; }

	inline void moveUp() { y--; }

	inline void moveDown() { y++; }

	friend std::ostream& operator<<(std::ostream& o, Cpaddle c)
	{
		o << "Paddle[" << c.x << "," << c.y << "]";
		return o;
	}

};

class CgameManager
{
private:
	int width, height;
	int score1, score2;
	char up1, down1, up2, down2;
	bool quit;
	Cball* cball;
	Cpaddle* player1;
	Cpaddle* player2;

public:
	CgameManager(int w, int h)
	{
		srand(time(NULL));
		quit = false;
		up1 = 'w'; up2 = 'i'; 
		down1 = 's'; down2 = 'k';
		score1 = score2 = 0;
		width = w; height = h;
		cball = new Cball(w / 2, h / 2);
		player1 = new Cpaddle(1, h / 2 - 3);
		player2 = new Cpaddle(w - 2, h / 2 - 3);
	}

	~CgameManager()
	{
		delete cball, player1, player2;
	}

	void scoreUp(Cpaddle* player)
	{
		if (player == player1)
			score1++;
		
		else if (player == player2)
			score2++;

		cball->reset();
		player1->reset();	
		player2->reset();

	}

	void draw()
	{
		system("cls");
		for (int i = 0; i < width + 2; i++)
			std::cout << "\xB2";
		std::cout << std::endl;
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				int ballX = cball->getX();
				int ballY = cball->getY();
				int player1X = player1->getX();
				int player2X = player2->getX();
				int player1Y = player1->getY();
				int player2Y = player2->getY();
				if(j == 0)
					std::cout << "\xB2";

				if (ballX == j && ballY == i)
					std::cout << "O";  //ball
				else if (player1X == j && player1Y == i)
					std::cout << "\xDB";  //player1
				else if (player2X == j && player2Y == i)
					std::cout << "\xDB";  //player2


				else if (player1X == j && player1Y + 1 == i)
					std::cout << "\xDB";  //player1
				else if (player1X == j && player1Y + 2 == i)
					std::cout << "\xDB";  //player1
				else if (player1X == j && player1Y + 3 == i)
					std::cout << "\xDB";  //player1

				else if (player2X == j && player2Y + 1 == i)
					std::cout << "\xDB";  //player2
				else if (player2X == j && player2Y + 2 == i)
					std::cout << "\xDB";  //player2
				else if (player2X == j && player2Y + 3 == i)
					std::cout << "\xDB";  //player2
				else
					std::cout << " ";

				if (j == width - 1)
					std::cout << "\xB2";
			}
			std::cout << std::endl;
		}
		for (int i = 0; i < width + 2; i++)
			std::cout << "\xB2";
		std::cout << std::endl;

		std::cout << "Score1: " << score1 << std::endl << "Score2: " << score2 << std::endl;
	}

	void input()
	{ 
		cball->move();

		int ballX = cball->getX();
		int ballY = cball->getY();
		int player1X = player1->getX();
		int player2X = player2->getX();
		int player1Y = player1->getY();
		int player2Y = player2->getY();

		if (_kbhit())
		{
			char current = _getch();
				if (current == up1)
					if (player1Y > 0)
						player1->moveUp();
				if (current == down1)
					if (player1Y + 4 < height)
						player1->moveDown();
				if (current == up2)
					if (player2Y > 0)
						player2->moveUp();
			    if (current == down2)
				    if (player2Y + 4 < height)
					    player2->moveDown();

				if (cball->getDirection() == STOP)
					cball->randomDirection();

				if (current == 'q')
					quit = true;

		}

	}

	void logic()
	{
		int ballX = cball->getX();
		int ballY = cball->getY();
		int player1X = player1->getX();
		int player2X = player2->getX();
		int player1Y = player1->getY();
		int player2Y = player2->getY();
		//left paddle
		for (int i = 0; i < 4; i++)
			if (ballX == player1X + 1)
				if (ballY == player1Y + i)
					cball->changeDirection((eDir)((rand() % 3) + 4));

		//right paddle
		for (int i = 0; i < 4; i++)
			if (ballX == player2X - 1)
				if (ballY == player2Y + i)
					cball->changeDirection((eDir)((rand() % 3) + 1));
		//bottom wall
		if (ballY == height - 1)
			cball->changeDirection(cball->getDirection() == DOWNRIGHT ? UPRIGHT : UPLEFT);
		//top wall
		if (ballY == 0)
			cball->changeDirection(cball->getDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);
		//right wall
		if (ballX == width - 1)
			scoreUp(player1);
		//left wall
		if (ballX == 0)
			scoreUp(player2);
	}

	void run()
	{
		while (!quit)
		{
			draw();			
			logic();
			input();
			Sleep(10);
		}
	}

};

int main()
{
	CgameManager c(40, 20);
	c.run();
	return 0;
}