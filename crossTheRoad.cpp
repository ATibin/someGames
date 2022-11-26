#include <iostream>
#include <conio.h>
#include <deque>
#include <vector>
#include <time.h>


class Cplayer
{
public:
	int x, y;
	Cplayer(int width) { x = width / 2, y = 0; }
};

class Clane
{
private:
	bool right;
	std::deque<bool> cars;

public:
	Clane(int width)
	{
		for (int i = 0; i < width; i++)
		{
			cars.push_front(true);
		}
		right = rand() % 2;
	}

	void move()
	{
		if (right)
		{
			(rand() % 10 == 1 ? cars.push_front(true) : cars.push_front(false));
			cars.pop_back();
		}
		else
		{
			(rand() % 10 == 1 ? cars.push_back(true) : cars.push_back(false));
			cars.pop_front();
		}
	}

	bool checkPos(int pos)
	{
		return cars[pos];
	}

	void changeDirexion()
	{
		right != right;
	}
};

class Cgame
{
private:
	bool quit;
	int numberOfLanes;
	int width;
	int score;
	Cplayer* player;
	std::vector<Clane*> map;

public:
	Cgame(int w = 20, int h = 10)
	{
		numberOfLanes = h;
		width = w;
		quit = false;
		for (int i = 0; i < numberOfLanes; i++)
		{
			map.push_back(new Clane(width));
		}
		player = new Cplayer(width);
	}

	~Cgame()
	{
		delete player;
		for (int i = 0; i < map.size(); i++)
		{
			Clane* current = map.back();
				map.pop_back();
				delete current;
		}
	}

	void draw()
	{
		system("cls");
		for (int i = 0; i < numberOfLanes; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (i == 0 && (j == 0 || j == width - 1))
					std::cout << "S";
				if (i == numberOfLanes - 1 && (j == 0 || j == width - 1))
					std::cout << "F";
				if (map[i]->checkPos(j) && i != 0 && i != numberOfLanes - 1)
					std::cout << "#";
				else if (player->x == j && player->y == i)
					std::cout << "V";
				else
					std::cout << " ";
			}
			std::cout << std::endl;
		}
		std::cout << "Score: " << score << std::endl;
	}

	void input()
	{
		if (_kbhit())
		{
			char current = _getch();
			if (current == 'a')
			{
				player->x--;
			}
			if (current == 'd')
			{
				player->x++;
			}
			if (current == 'w')
			{
				player->y--;
			}
			if (current == 's')
			{
				player->y++;
			}
			if (current == 'q')
			{
				quit = true;
			}
		}
	}

	void logic()
	{
		for (int i = 1; i < numberOfLanes - 1; i++)
		{
			if (rand() % 10 == 1)
			{
				map[i]->move();
			}
			if (map[i]->checkPos(player->x) && player->y == i)
			{
				quit = true;
			}
		}
		if (player->y == numberOfLanes - 1)
		{
			score++;
			player->y = 0;
			std::cout << "\x07";
			map[rand() % numberOfLanes]->changeDirexion();
		}
	}
	
	void run()
	{
		while (!quit)
		{
			input();
			draw();
			logic();
		}
	}
};
int main()
{
	srand(time(NULL));
	Cgame game(30, 10);
	game.run();
	std::cout << "Game is over!" << std::endl;
	getchar();
	return 0;
}