#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

bool gameOfNim(vector<int> v)
{
    int player = 0;
    int turn = 0;
    srand((int)time(NULL));
    cout << "Welcome to the game of Nim, there are 21 matchsticks in the pile." << endl << endl;
    while (v.size())
    {
        if (v.size() <= 3)
        {
            if(turn == 0 && v.size()== 3)
            {
                cout << "Computer's turn:" << endl;
                int r= rand() % 3 + 1;
                cout << "The computer removed " << r << " matchstick(s)" << endl << endl;
                while (r)
                {
                    v.pop_back();
                    r--;
                }
                if(v.size()== 0 && turn == 0)
                    return true;
                turn++;
            }
            else if(turn == 0 && v.size()== 2)
            {
                cout << "Computer's turn:" << endl;
                int r= rand() % 2 + 1;
                cout << "The computer removed " << r << " matchstick(s)" << endl << endl;
                while (r)
                {
                    v.pop_back();
                    r--;
                }
                if(v.size()== 0 && turn == 0)
                    return true;
                turn++;
            }
            else if (turn == 0 && v.size() == 1)
            {
                cout << "Computer's turn:" << endl;
                cout << "The computer removed the last matchstick" << endl << endl;
                v.pop_back();
                if (v.size() == 0 && turn == 0)
                    return true;
            }
            else
            {
                cout << v.size() << " matchstick(s) left!" << endl << endl;
                while (player > v.size() || player < 1)
                {
                    cout << "Remove 1 - 3 matchsticks" << endl;
                    cin >> player;
                }
                while (player)
                {
                    v.pop_back();
                    player--;
                }
                if (v.size() == 0)
                    return false;
                turn--;
            }
        }
        else if (turn == 0) //the computer plays first
        {
            cout << "Computer's turn:" << endl;
            int r = rand() % 3 + 1;
            cout << "The computer removed " << r << " matchstick(s)" << endl << endl;
            while (r)
            {
                v.pop_back();
                r--;
            }
            turn++;
        }
        else
        {
            cout << v.size() << " matchsticks left!" << endl << endl;
            while (player > 3 || player < 1)
            {
                cout << "Remove 1 - 3 matchsticks" << endl;
                cin >> player;
            }
            while (player)
            {
                v.pop_back();
                player--;
            }
            turn--;
        }
    }
}

int main()
{
    vector<int> v(21,1);
    if (!gameOfNim(v))
        cout << "The computer won the game" << endl;
    else
        cout << "You won the game" << endl;
}

//pobjeda je sigurna ako igrac uvijek oduzme -> 4 - koliko je racunalo uzelo
