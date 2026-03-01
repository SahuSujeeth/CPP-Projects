#include <bits/stdc++.h>
using namespace std;


const int ROWS = 3;
const int COLS = 3;

void runGame();
void initializeGameBoard(string gameBoard[ROWS][COLS]);
void printCurrentBoard(string gameBoard[ROWS][COLS]);
void getuserInput(bool xTurn, string gameBoard[ROWS][COLS]);
bool cellAlreadyOccupied(int row, int col, string gameBoard[ROWS][COLS]);
string getWinner(string gameBoard[ROWS][COLS]);
bool isBoardFull(string gameBoard[ROWS][COLS]);


int main()
{
    cout << "| 00 | 01 |02 "<< endl;
    cout << "--------------"<< endl;
    cout << "| 10 | 11 | 12 "<< endl;
    cout << "--------------"<< endl;
    cout << "| 20 | 21 | 22 "<< endl;
    cout << "Follow this order to play the game and enjoy!!" << endl;

    runGame();

    return 0;
}

void runGame()
{
    string winner = "";
    bool xturn = true ; // start with X's turn 
    int theRow = 0;
    int theCol = 0;
    string gameBoard[ROWS][COLS];
    initializeGameBoard(gameBoard);

    //initial print
    printCurrentBoard(gameBoard);

    while (winner == "")
    {
        if(xturn)
        {
            cout << "It is X's turn" << endl;

        }
        else
        {
            cout << "It is O's turn" << endl;
        }
        getuserInput(xturn, gameBoard);
        cout << endl; // extra spacing
        printCurrentBoard(gameBoard);//reprint the board
        winner = getWinner(gameBoard);// chect the winner
        xturn = !xturn; // flip it

        if(winner == "" && isBoardFull(gameBoard))
        {
            winner = 'C'; //Cat's game... no winner!
        }
    } // end loop

    //Cat's game?
    cout << endl;//add extra space
    if(winner == "C")
    {
      cout << "It was the Cat's game! NO WINNER!! " << winner << endl;
    }
    else
    {
        cout << " The winner is " << winner << endl; // print's x or o
    }
    cout << endl;// add extra space
}

//InitializeBoard
void initializeGameBoard(string gameBoard[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            gameBoard[i][j] = " ";// empty space
        } 
    } 
}// end initialize board
void printCurrentBoard(string gameBoard[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
           cout << gameBoard[i][j];
           if(j < 2)
           {
            cout << " | ";
           }
        }
        cout << endl;
        if(i < 2)
        {
            cout << "- - - - -" << endl;
        }
    }
    cout << endl; //extra spacing   
} //end print the current board


//get the user input and plae symbol
void getuserInput(bool xTurn, string gameBoard[ROWS][COLS])
{
    int row = -1;
    int col = -1;
    bool keepAsking = true ;
    while (keepAsking)
    {
        cout << "Please enter the row THEN the colmn, each from 0,1 or 2, seperatly by a space" << endl;
        cin >> row;
        cin >> col;
        if(row >= 0 && col >= 0 && row <= 2 && col <= 2)
        {
            if(!cellAlreadyOccupied(row,col,gameBoard))
            {
                keepAsking = false;
            }
            else
            {
               cout << "That cell is already occupied!" << endl; 
            }
        }
    }// end while

    // by the timeit gets here , we know it's a VALID row and col,
    // in range . and not aready occupied
    if(xTurn)// must be an X
    {
       gameBoard[row][col] = "X";
    }
    else // msut be an O
    {
        gameBoard[row][col] = "O";
    }
}// end get user input


bool cellAlreadyOccupied(int row, int col, string gameBoard[ROWS][COLS])
{
    return gameBoard[row][col] != " ";//if not a space, then it is occupied
}// end cellalreaddyoccupied

// get winner
string getWinner(string gameBoard[ROWS][COLS])
{
    // check rows
    for (int i = 0; i < ROWS; i++)
    {
        if(gameBoard[i][0] != " " && gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2])
        {
            return gameBoard[i][0];
        }
    }// end for

    // check colmn
    for (int i = 0; i < COLS; i++)
    {
        if(gameBoard[0][i] != " " && gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i])
        {
            return gameBoard[0][i];// we havve a match vertical
        }
    }// end for

    // check diagonals
    //upper-left to bottom right diagonal
    if(gameBoard[0][0] != " " && gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2])
    {
        return gameBoard[0][0];// we have a diagonal match!!
    }
    return "";// not winner yet!   
}// end get wiiner

bool isBoardFull(string gameBoard[ROWS][COLS])
{
    int countFill = 0;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if(gameBoard[i][j] != " ")
            {
                countFill++;
            }
            
        }   
    }
    return countFill == 9; // all 9 cells are full , then the board is full
    
}