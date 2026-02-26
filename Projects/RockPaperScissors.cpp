#include <bits/stdc++.h>
using namespace std;

int main()
{
    char userMove;
    char computerMove;
    srand(time(nullptr));
    cout << "Welcome to the Rock, Paper, Scissors!" << endl;
    cout << "Enter your move (R, P, or S): ";
    cin >> userMove;

    int randNum = rand() % 3;

    if (randNum == 0)
    {
        computerMove = 'R';
    }
    else if (randNum == 1)
    {
        computerMove = 'P';
    }
    else
    {
        computerMove == 'S';
    }
    cout << "You Played: " << userMove << endl;
    cout << "Computer Played: " << computerMove << endl;

    if (userMove == computerMove)
    {
        cout << "It's a tie!" << endl;
    }
    else if ((userMove == 'R' && computerMove == 'S') || (userMove == 'S' && computerMove == 'P') || (userMove == 'P' && computerMove == 'R'))
    {
        cout << "You Win!" << endl;
    }
    else

    {
        cout << "Computer Wins!!" << endl;
    }

    return 0;
}