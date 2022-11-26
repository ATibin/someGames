#include <iostream>

char matrix[3][3] = { '1', '2', '3',
                      '4', '5', '6',
                      '7', '8', '9' };
char player = 'X';
int cnt;

void draw()
{
    system("cls");
    std::cout << "Tic Tac Toe game v1.0" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
}

void input()
{
    int xo;
    std::cout << "It's " << player << " turn." << "Press the number of the field: ";
    std::cin >> xo;

    if (xo == 1)
    {
        if (matrix[0][0] == '1')
        {
            matrix[0][0] = player;
        }            
        else
        {
            std::cout << "Field is already in use try again!" << std::endl;
            input();
        }            
    }
    else if (xo == 2)
    {
        if (matrix[0][1] == '2')
        {
            matrix[0][1] = player;
        }
        else
        {
            std::cout << "Field is already in use try again!" << std::endl;
            input();
        }
    }
    else if (xo == 3)
    {
        if (matrix[0][2] == '3')
        {
            matrix[0][2] = player;
        }
        else
        {
            std::cout << "Field is already in use try again!" << std::endl;
            input();
        }
    }
    else if (xo == 4)
    {
        if (matrix[1][0] == '4')
        {
            matrix[1][0] = player;
        }
        else
        {
            std::cout << "Field is already in use try again!" << std::endl;
            input();
        }
    }
    else if (xo == 5)
    {
        if (matrix[1][1] == '5')
        {
            matrix[1][1] = player;
        }
        else
        {
            std::cout << "Field is already in use try again!" << std::endl;
            input();
        }
    }
    else if (xo == 6)
    {
        if (matrix[1][2] == '6')
        {
            matrix[1][2] = player;
        }
        else
        {
            std::cout << "Field is already in use try again!" << std::endl;
            input();
        }
    }
    else if (xo == 7)
    {
        if (matrix[2][0] == '7')
        {
            matrix[2][0] = player;
        }
        else
        {
            std::cout << "Field is already in use try again!" << std::endl;
            input();
        }
    }
    else if (xo == 8)
    {
        if (matrix[2][1] == '8')
        {
            matrix[2][1] = player;
        }
        else
        {
            std::cout << "Field is already in use try again!" << std::endl;
            input();
        }
    }
    else if (xo == 9)
    {
        if (matrix[2][2] == '9')
        {
            matrix[2][2] = player;
        }
        else
        {
            std::cout << "Field is already in use try again!" << std::endl;
            input();
        }
    }
}

void togglePlayer()
{
    (player == 'X' ? player = 'O' : player = 'X');
}

char winLogic()
{
    //first player
    if (matrix[0][0] == 'X' && matrix[0][1] == 'X' && matrix[0][2] == 'X')
        return 'X';
    if (matrix[1][0] == 'X' && matrix[1][1] == 'X' && matrix[1][2] == 'X')
        return 'X';
    if (matrix[2][0] == 'X' && matrix[2][1] == 'X' && matrix[2][2] == 'X')
        return 'X';

    if (matrix[0][0] == 'X' && matrix[1][0] == 'X' && matrix[2][0] == 'X')
        return 'X';
    if (matrix[0][1] == 'X' && matrix[1][1] == 'X' && matrix[2][1] == 'X')
        return 'X';
    if (matrix[0][2] == 'X' && matrix[1][2] == 'X' && matrix[2][2] == 'X')
        return 'X';

    if (matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X')
        return 'X';
    if (matrix[0][2] == 'X' && matrix[1][1] == 'X' && matrix[2][0] == 'X')
        return 'X';

    //second player
    if (matrix[0][0] == 'O' && matrix[0][1] == 'O' && matrix[0][2] == 'O')
        return 'O';
    if (matrix[1][0] == 'O' && matrix[1][1] == 'O' && matrix[1][2] == 'O')
        return 'O';
    if (matrix[2][0] == 'O' && matrix[2][1] == 'O' && matrix[2][2] == 'O')
        return 'O';

    if (matrix[0][0] == 'O' && matrix[1][0] == 'O' && matrix[2][0] == 'O')
        return 'O';
    if (matrix[0][1] == 'O' && matrix[1][1] == 'O' && matrix[2][1] == 'O')
        return 'O';
    if (matrix[0][2] == 'O' && matrix[1][2] == 'O' && matrix[2][2] == 'O')
        return 'O';

    if (matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O')
        return 'O';
    if (matrix[0][2] == 'O' && matrix[1][1] == 'O' && matrix[2][0] == 'O')
        return 'O';

    return '/';
}

int main()
{
    cnt = 0;

    draw();
    while (1)
    {
        cnt++;
        input();
        draw();
        if (winLogic() == 'X')
        {
            std::cout << "X winer!" << std::endl;
                break;
        }
        else if (winLogic() == 'O')
        {
            std::cout << "O winer!" << std::endl;
                break;           
        }
        else if (winLogic() == '/' && cnt == 9)
        {
            std::cout << "It's a draw";
                break;
        }
        togglePlayer();
    }
    system("pause");

    return 0;
}