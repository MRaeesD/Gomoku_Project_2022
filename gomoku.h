// <2453739>
//  Muhammd Raees Dindar

#ifndef GOMOKU_H
#define GOMOKU_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
#include "gomoku.h"

using namespace std;
class gomoku
{
    public:

        vector<vector<char>> boardReset (vector<vector<char>> gameBoard, int n);                    //Sets all the elements of the gameboard to B (blank)
        vector<vector<char>> moveP1 (vector<vector<char>> gameBoard, int n, ofstream& outData);     //Algorithm 1's move
        vector<vector<char>> moveP2 (vector<vector<char>> gameBoard, int n, ofstream& outData);     //Algorithm 2's move
        int P1winChecker (vector<vector<char>> gameBoard, int n);                                   //Checks if algorithm 1 won
        int P2winChecker (vector<vector<char>> gameBoard, int n);                                   //Checks if algorithm 2 won

    protected:

    private:
};

vector<vector<char>> gomoku::boardReset (vector<vector<char>> gameBoard, int n)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            gameBoard[i][j] = 'B' ;         //Sets the element i,j of gameboard to B
        }
    }
    return gameBoard;
}

vector<vector<char>> gomoku::moveP1 (vector<vector<char>> gameBoard, int n, ofstream& outData)
{
    //Check all sets of 4 consecutive horizontal elements. If they are all X, play an X in the next element (where possible)
    for (int a=0; a<n; a++)
    {
        for (int b=0; b<n-4; b++)
        {
            if (gameBoard[a][b] == 'X' && gameBoard[a][b+1] == 'X' && gameBoard[a][b+2] == 'X' && gameBoard[a][b+3] == 'X' && gameBoard[a][b+4] == 'B')
            {
                gameBoard[a][b+4] = 'X';
                outData << "r" << a << "c" << b+4 << " alg1" << endl;       //Print position of move to output file
                return gameBoard;
            }


        }
    }

    //Check all sets of 4 consecutive vertical elements. If they are all X, play an X in the next element (where possible)
    for (int c=0; c<n; c++)
    {
        for (int d=0; d<n-4; d++)
        {
            if (gameBoard[d][c] == 'X' && gameBoard[d+1][c] == 'X' && gameBoard[d+2][c] == 'X' && gameBoard[d+3][c] == 'X' && gameBoard[d+4][c] == 'B')
            {
                gameBoard[d+4][c] = 'X';
                outData << "r" << d+4 << "c" << c << " alg1" << endl;
                return gameBoard;
            }

        }
    }

   //Check all sets of 4 consecutive diagonal elements (downwards from left to right, below the leading diagonal). If they are all X, play an X in the next element (where possible)
   for (int e=0; e<n-4; e++)
    {
        for (int f=0; f<n-4-e; f++)
        {
            if (gameBoard[e+f][f] == 'X' && gameBoard[e+f+1][f+1] == 'X' && gameBoard[e+f+2][f+2] == 'X' && gameBoard[e+f+3][f+3] == 'X' && gameBoard[e+f+4][f+4] == 'B')
            {
                gameBoard[e+f+4][f+4] = 'X';
                outData << "r" << e+f+4 << "c" << f+4 << " alg1" << endl;       //Print position of move to output file
                return gameBoard;
            }

        }
    }


    //Check all sets of 4 consecutive diagonal elements (downwards from left to right, above the leading diagonal). If they are all X, play an X in the next element (where possible)
    for (int g=0; g<n-4; g++)
    {

        for (int h=0; h<n-4-g; h++)
        {
            if(gameBoard[h][g+h] == 'X' && gameBoard[h+1][g+h+1] == 'X' && gameBoard[h+2][g+h+2] == 'X' && gameBoard[h+3][g+h+3] == 'X' && gameBoard[h+4][g+h+4] == 'B')
            {
                gameBoard[h+4][g+h+4] = 'X';
                outData << "r" << h+4 << "c" << g+h+4 << " alg1" << endl;       //Print position of move to output file
                return gameBoard;
            }
        }
    }

    //Check all sets of 4 consecutive diagonal elements (upwards from left to right, above the leading diagonal). If they are all X, play an X in the next element (where possible)
    for (int i=n-1; i>=4; i--)
    {
        for (int j=0; j<i-3; j++)
        {
            if(gameBoard[i-j][j] == 'X' && gameBoard[i-j-1][j+1] == 'X' && gameBoard[i-j-2][j+2] == 'X' && gameBoard[i-j-3][j+3] == 'X' && gameBoard[i-j-4][j+4] == 'B')
            {
                gameBoard[i-j-4][j+4] = 'X';
                outData << "r" << i-j-4 << "c" << j+4 << " alg1" << endl;       //Print position of move to output file
                return gameBoard;
            }
        }
    }

    //Check all sets of 4 consecutive diagonal elements (upwards from left to right, below the leading diagonal). If they are all X, play an X in the next element (where possible)
    for (int k=0; k<n-4; k++)
    {
        for (int l=n-1; l>=4+k; l--)
        {
            if(gameBoard[l][k+n-1-l] == 'X' && gameBoard[l-1][k+n-l-1+1] == 'X' && gameBoard[l-2][k+n-l-1+2] == 'X' && gameBoard[l-3][k+n-l-1+3] == 'X' && gameBoard[l-4][k+n-l-1+4] == 'B')
            {
                 gameBoard[l-4][k+n-l-1+4] = 'X';
                outData << "r" << l-4 << "c" << k+n-l-1+4 << " alg1" << endl;       //Print position of move to output file
                return gameBoard;
            }
        }
    }

    //Check all sets of 4 consecutive horizontal elements. If they are all X, play an X in the previous element (where possible)
    for (int a=0; a<n; a++)
    {
        for (int b=0; b<n-4; b++)
        {
            if (gameBoard[a][b] == 'B' && gameBoard[a][b+1] == 'X' && gameBoard[a][b+2] == 'X' && gameBoard[a][b+3] == 'X' && gameBoard[a][b+4] == 'X')
            {
                gameBoard[a][b] = 'X';
                outData << "r" << a << "c" << b << " alg1" << endl;         //Print position of move to output file
                return gameBoard;
            }
        }
    }

    //Check all sets of 4 consecutive vertical elements. If they are all X, play an X in the previous element (where possible)
    for (int c=0; c<n; c++)
    {
        for (int d=0; d<n-4; d++)
        {
            if (gameBoard[d][c] == 'B' && gameBoard[d+1][c] == 'X' && gameBoard[d+2][c] == 'X' && gameBoard[d+3][c] == 'X' && gameBoard[d+4][c] == 'X')
            {
                gameBoard[d][c] = 'X';
                outData << "r" << d << "c" << c << " alg1" << endl;         //Print position of move to output file
                return gameBoard;
            }

        }
    }

   //Check all sets of 4 consecutive diagonal elements (downwards from left to right, below the leading diagonal). If they are all X, play an X in the previous element (where possible)
   for (int e=0; e<n-4; e++)
    {
        for (int f=0; f<n-4-e; f++)
        {
            if (gameBoard[e+f][f] == 'B' && gameBoard[e+f+1][f+1] == 'X' && gameBoard[e+f+2][f+2] == 'X' && gameBoard[e+f+3][f+3] == 'X' && gameBoard[e+f+4][f+4] == 'X')
            {
                gameBoard[e+f][f] = 'X';
                outData << "r" << e+f << "c" << f << " alg1" << endl;           //Print position of move to output file
                return gameBoard;
            }

        }
    }


    //Check all sets of 4 consecutive diagonal elements (downwards from left to right, above the leading diagonal). If they are all X, play an X in the previous element (where possible)
    for (int g=0; g<n-4; g++)
    {

        for (int h=0; h<n-4-g; h++)
        {
            if(gameBoard[h][g+h] == 'B' && gameBoard[h+1][g+h+1] == 'X' && gameBoard[h+2][g+h+2] == 'X' && gameBoard[h+3][g+h+3] == 'X' && gameBoard[h+4][g+h+4] == 'X')
            {
                gameBoard[h][g+h] = 'X';
                outData << "r" << h << "c" << g+h << " alg1" << endl;        //Print position of move to output file
                return gameBoard;
            }
        }
    }

    //Check all sets of 4 consecutive diagonal elements (upwards from left to right, above the leading diagonal). If they are all X, play an X in the previous element (where possible)
    for (int i=n-1; i>=4; i--)
    {
        for (int j=0; j<i-3; j++)
        {
            if(gameBoard[i-j][j] == 'B' && gameBoard[i-j-1][j+1] == 'X' && gameBoard[i-j-2][j+2] == 'X' && gameBoard[i-j-3][j+3] == 'X' && gameBoard[i-j-4][j+4] == 'X')
            {
                gameBoard[i-j][j] = 'X';
                outData << "r" << i-j << "c" << j << " alg1" << endl;           //Print position of move to output file
                return gameBoard;
            }
        }
    }

    //Check all sets of 4 consecutive diagonal elements (upwards from left to right, below the leading diagonal). If they are all X, play an X in the previous element (where possible)
    for (int k=0; k<n-4; k++)
    {
        for (int l=n-1; l>=4+k; l--)
        {
            if(gameBoard[l][k+n-1-l] == 'B' && gameBoard[l-1][k+n-l-1+1] == 'X' && gameBoard[l-2][k+n-l-1+2] == 'X' && gameBoard[l-3][k+n-l-1+3] == 'X' && gameBoard[l-4][k+n-l-1+4] == 'X')
            {
                 gameBoard[l][k+n-l-1] = 'X';
                outData << "r" << l << "c" << k+n-l-1 << " alg1" << endl;       //Print position of move to output file
                return gameBoard;
            }
        }
    }

    srand(time(NULL));                                      //Seed the random number generator using the computer's clock

    int checker = 0;
    int randRow;
    int randCol;

    while (checker !=1)                                     //Loop as long as checker != 1, i.e. no move has been made
    {
        randRow = rand()%n;                                 //Select a random number for the row
        randCol = rand()%n;                                 //Select a random number for the column

        if (gameBoard[randRow][randCol] == 'B')             //If the element is a B (blank)
        {
            gameBoard[randRow][randCol] = 'X' ;             //Set that element to X

            checker = 1;                                    //Checker = 1, as a move has been made
        }
    }
    outData << "r" << randRow << "c" << randCol << " alg1" <<endl;      //Print position of move to output file

    return gameBoard;
}

vector<vector<char>> gomoku::moveP2 (vector<vector<char>> gameBoard, int n, ofstream& outData)
{
    //Check all sets of 4 consecutive horizontal elements. If they are all X, play an O in the next element (where possible)
    for (int a=0; a<n; a++)
    {
        for (int b=0; b<n-4; b++)
        {
            if (gameBoard[a][b] == 'X' && gameBoard[a][b+1] == 'X' && gameBoard[a][b+2] == 'X' && gameBoard[a][b+3] == 'X' && gameBoard[a][b+4] == 'B')
            {
                gameBoard[a][b+4] = 'O';
                outData << "r" << a << "c" << b+4 << " alg2" << endl;           //Print position of move to output file
                return gameBoard;
            }


        }
    }

    //Check all sets of 4 consecutive vertical elements. If they are all X, play an O in the next element (where possible)
    for (int c=0; c<n; c++)
    {
        for (int d=0; d<n-4; d++)
        {
            if (gameBoard[d][c] == 'X' && gameBoard[d+1][c] == 'X' && gameBoard[d+2][c] == 'X' && gameBoard[d+3][c] == 'X' && gameBoard[d+4][c] == 'B')
            {
                gameBoard[d+4][c] = 'O';
                outData << "r" << d+4 << "c" << c << " alg2" << endl;           //Print position of move to output file
                return gameBoard;
            }

        }
    }

   //Check all sets of 4 consecutive diagonal elements (downwards from left to right, below the leading diagonal). If they are all X, play an O in the next element (where possible)
   for (int e=0; e<n-4; e++)
    {
        for (int f=0; f<n-4-e; f++)
        {
            if (gameBoard[e+f][f] == 'X' && gameBoard[e+f+1][f+1] == 'X' && gameBoard[e+f+2][f+2] == 'X' && gameBoard[e+f+3][f+3] == 'X' && gameBoard[e+f+4][f+4] == 'B')
            {
                gameBoard[e+f+4][f+4] = 'O';            //Print position of move to output file
                return gameBoard;
            }

        }
    }

    //Check all sets of 4 consecutive diagonal elements (downwards from left to right, above the leading diagonal). If they are all X, play an O in the next element (where possible)
    for (int g=0; g<n-4; g++)
    {

        for (int h=0; h<n-4-g; h++)
        {
            if(gameBoard[h][g+h] == 'X' && gameBoard[h+1][g+h+1] == 'X' && gameBoard[h+2][g+h+2] == 'X' && gameBoard[h+3][g+h+3] == 'X' && gameBoard[h+4][g+h+4] == 'B')
            {
                gameBoard[h+4][g+h+4] = 'O';
                outData << "r" << h+4 << "c" << g+h+4 << " alg2" << endl;           //Print position of move to output file
                return gameBoard;
            }
        }
    }

    //Check all sets of 4 consecutive diagonal elements (upwards from left to right, above the leading diagonal). If they are all X, play an O in the next element (where possible)
    for (int i=n-1; i>=4; i--)
    {
        for (int j=0; j<i-3; j++)
        {
            if(gameBoard[i-j][j] == 'X' && gameBoard[i-j-1][j+1] == 'X' && gameBoard[i-j-2][j+2] == 'X' && gameBoard[i-j-3][j+3] == 'X' && gameBoard[i-j-4][j+4] == 'B')
            {
                gameBoard[i-j-4][j+4] = 'O';
                outData << "r" << i-j-4 << "c" << j+4 << " alg2" << endl;           //Print position of move to output file
                return gameBoard;
            }
        }
    }

    //Check all sets of 4 consecutive diagonal elements (upwards from left to right, below the leading diagonal). If they are all X, play an O in the next element (where possible)
    for (int k=0; k<n-4; k++)
    {
        for (int l=n-1; l>=4+k; l--)
        {
            if(gameBoard[l][k+n-1-l] == 'X' && gameBoard[l-1][k+n-l-1+1] == 'X' && gameBoard[l-2][k+n-l-1+2] == 'X' && gameBoard[l-3][k+n-l-1+3] == 'X' && gameBoard[l-4][k+n-l-1+4] == 'B')
            {
                 gameBoard[l-4][k+n-l-1+4] = 'O';
                outData << "r" << l-4 << "c" << k+n-l-1+4 << " alg2" << endl;       //Print position of move to output file
                return gameBoard;
            }
        }
    }

    //Check all sets of 4 consecutive horizontal elements. If they are all X, play an O in the previous element (where possible)
    for (int a=0; a<n; a++)
    {
        for (int b=0; b<n-4; b++)
        {
            if (gameBoard[a][b] == 'B' && gameBoard[a][b+1] == 'X' && gameBoard[a][b+2] == 'X' && gameBoard[a][b+3] == 'X' && gameBoard[a][b+4] == 'X')
            {
                gameBoard[a][b] = 'O';
                outData << "r" << a << "c" << b << " alg2" << endl;             //Print position of move to output file
                return gameBoard;
            }
        }
    }

    //Check all sets of 4 consecutive vertical elements. If they are all X, play an O in the previous element (where possible)
    for (int c=0; c<n; c++)
    {
        for (int d=0; d<n-4; d++)
        {
            if (gameBoard[d][c] == 'B' && gameBoard[d+1][c] == 'X' && gameBoard[d+2][c] == 'X' && gameBoard[d+3][c] == 'X' && gameBoard[d+4][c] == 'X')
            {
                gameBoard[d][c] = 'O';
                outData << "r" << d << "c" << c << " alg2" << endl;             //Print position of move to output file
                return gameBoard;
            }
        }
    }

   //Check all sets of 4 consecutive diagonal elements (downwards from left to right, below the leading diagonal). If they are all X, play an O in the previous element (where possible)
   for (int e=0; e<n-4; e++)
    {
        for (int f=0; f<n-4-e; f++)
        {
            if (gameBoard[e+f][f] == 'B' && gameBoard[e+f+1][f+1] == 'X' && gameBoard[e+f+2][f+2] == 'X' && gameBoard[e+f+3][f+3] == 'X' && gameBoard[e+f+4][f+4] == 'X')
            {
                gameBoard[e+f][f] = 'O';
                outData << "r" << e+f << "c" << f << " alg2" << endl;           //Print position of move to output file
                return gameBoard;
            }
        }
    }

    //Check all sets of 4 consecutive diagonal elements (downwards from left to right, above the leading diagonal). If they are all X, play an O in the previous element (where possible)
    for (int g=0; g<n-4; g++)
    {

        for (int h=0; h<n-4-g; h++)
        {
            if(gameBoard[h][g+h] == 'B' && gameBoard[h+1][g+h+1] == 'X' && gameBoard[h+2][g+h+2] == 'X' && gameBoard[h+3][g+h+3] == 'X' && gameBoard[h+4][g+h+4] == 'X')
            {
                gameBoard[h][g+h] = 'O';
                outData << "r" << h << "c" << g+h << " alg2" << endl;           //Print position of move to output file
                return gameBoard;
            }
        }
    }

    //Check all sets of 4 consecutive diagonal elements (upwards from left to right, above the leading diagonal). If they are all X, play an O in the previous element (where possible)
    for (int i=n-1; i>=4; i--)
    {
        for (int j=0; j<i-3; j++)
        {
            if(gameBoard[i-j][j] == 'B' && gameBoard[i-j-1][j+1] == 'X' && gameBoard[i-j-2][j+2] == 'X' && gameBoard[i-j-3][j+3] == 'X' && gameBoard[i-j-4][j+4] == 'X')
            {
                gameBoard[i-j][j] = 'O';
                outData << "r" << i-j << "c" << j << " alg2" << endl;           //Print position of move to output file
                return gameBoard;
            }
        }
    }

    //Check all sets of 4 consecutive diagonal elements (upwards from left to right, below the leading diagonal). If they are all X, play an O in the previous element (where possible)
    for (int k=0; k<n-4; k++)
    {
        for (int l=n-1; l>=4+k; l--)
        {
            if(gameBoard[l][k+n-1-l] == 'B' && gameBoard[l-1][k+n-l-1+1] == 'X' && gameBoard[l-2][k+n-l-1+2] == 'X' && gameBoard[l-3][k+n-l-1+3] == 'X' && gameBoard[l-4][k+n-l-1+4] == 'X')
            {
                 gameBoard[l][k+n-l-1] = 'O';
                outData << "r" << l << "c" << k+n-l-1 << " alg2" << endl;       //Print position of move to output file
                return gameBoard;
            }
        }
    }

    srand(time(NULL));

    int checker = 0;
    int randRow;
    int randCol;

    while (checker !=1)                                 //Loop as long as checker != 1, i.e. no move has been made
    {
        randRow = rand()%n;                             //Select a random number for the row
        randCol = rand()%n;                             //Select a random number for the column

        if (gameBoard[randRow][randCol] == 'B')         //If the element is a B (blank)
        {
            gameBoard[randRow][randCol] = 'O' ;         //Set that element to O

            checker = 1;                                //Checker = 1, as a move has been made
        }
    }

    outData << "r" << randRow << "c" <<randCol << " alg2" <<endl;       //Print position of move to output file


    return gameBoard;
}

int gomoku::P1winChecker (vector<vector<char>> gameBoard, int n)
{
    //Check all sets of 5 consecutive horizontal elements. If they are all X, alg 1 wins
    for (int a=0; a<n; a++)
    {
        for (int b=0; b<n-4; b++)
        {
            if (gameBoard[a][b] == 'X' && gameBoard[a][b+1] == 'X' && gameBoard[a][b+2] == 'X' && gameBoard[a][b+3] == 'X' && gameBoard[a][b+4] == 'X')
            {
                return 1;           //Alg 1 wins
            }
        }
    }

    //Check all sets of 5 consecutive vertical elements. If they are all X, alg 1 wins
    for (int c=0; c<n; c++)
    {
        for (int d=0; d<n-4; d++)
        {
            if (gameBoard[d][c] == 'X' && gameBoard[d+1][c] == 'X' && gameBoard[d+2][c] == 'X' && gameBoard[d+3][c] == 'X' && gameBoard[d+4][c] == 'X')
            {
                return 1;           //Alg 1 wins
            }
        }
    }

   //Check all sets of 5 consecutive diagonal elements (downwards from left to right, below the leading diagonal) . If they are all X, alg 1 wins
   for (int e=0; e<n-4; e++)
    {
        for (int f=0; f<n-4-e; f++)
        {
            if (gameBoard[e+f][f] == 'X' && gameBoard[e+f+1][f+1] == 'X' && gameBoard[e+f+2][f+2] == 'X' && gameBoard[e+f+3][f+3] == 'X' && gameBoard[e+f+4][f+4] == 'X')
            {
                return 1;           //Alg 1 wins
            }
        }
    }

    //Check all sets of 5 consecutive diagonal elements (downwards from left to right, above the leading diagonal) . If they are all X, alg 1 wins
    for (int g=0; g<n-4; g++)
    {

        for (int h=0; h<n-4-g; h++)
        {
            if(gameBoard[h][g+h] == 'X' && gameBoard[h+1][g+h+1] == 'X' && gameBoard[h+2][g+h+2] == 'X' && gameBoard[h+3][g+h+3] == 'X' && gameBoard[h+4][g+h+4] == 'X')
            {
                return 1;           //Alg 1 wins
            }
        }
    }

    //Check all sets of 5 consecutive diagonal elements (upwards from left to right, above the leading diagonal) . If they are all X, alg 1 wins
    for (int i=n-1; i>=4; i--)
    {
        for (int j=0; j<i-3; j++)
        {
            if(gameBoard[i-j][j] == 'X' && gameBoard[i-j-1][j+1] == 'X' && gameBoard[i-j-2][j+2] == 'X' && gameBoard[i-j-3][j+3] == 'X' && gameBoard[i-j-4][j+4] == 'X')
            {
                return 1;           //Alg 1 wins
            }
        }
    }

    //Check all sets of 5 consecutive diagonal elements (upwards from left to right, below the leading diagonal) . If they are all X, alg 1 wins
    for (int k=0; k<n-4; k++)
    {
        for (int l=n-1; l>=4+k; l--)
        {
            if(gameBoard[l][k+n-1-l] == 'X' && gameBoard[l-1][k+n-l-1+1] == 'X' && gameBoard[l-2][k+n-l-1+2] == 'X' && gameBoard[l-3][k+n-l-1+3] == 'X' && gameBoard[l-4][k+n-l-1+4] == 'X')
            {
                return 1;           //Alg 1 wins
            }
        }
    }

    return 0;
}

int gomoku::P2winChecker (vector<vector<char>> gameBoard, int n)
{
    //Check all sets of 5 consecutive horizontal elements. If they are all O, alg 2 wins
    for (int a=0; a<n; a++)
    {
        for (int b=0; b<n-4; b++)
        {
            if (gameBoard[a][b] == 'O' && gameBoard[a][b+1] == 'O' && gameBoard[a][b+2] == 'O' && gameBoard[a][b+3] == 'O' && gameBoard[a][b+4] == 'O')
            {
                return 2;
            }
        }
    }

    //Check all sets of 5 consecutive vertical elements. If they are all O, alg 2 wins
    for (int c=0; c<n; c++)
    {
        for (int d=0; d<n-4; d++)
        {
            if (gameBoard[d][c] == 'O' && gameBoard[d+1][c] == 'O' && gameBoard[d+2][c] == 'O' && gameBoard[d+3][c] == 'O' && gameBoard[d+4][c] == 'O')
            {
                return 2;
            }
        }
    }

   //Check all sets of 5 consecutive diagonal elements (downwards from left to right, below the leading diagonal) . If they are all O, alg 2 wins
   for (int e=0; e<n-4; e++)
    {
        for (int f=0; f<n-4-e; f++)
        {
            if (gameBoard[e+f][f] == 'O' && gameBoard[e+f+1][f+1] == 'O' && gameBoard[e+f+2][f+2] == 'O' && gameBoard[e+f+3][f+3] == 'O' && gameBoard[e+f+4][f+4] == 'O')
            {
                return 2;
            }
        }
    }

    //Check all sets of 5 consecutive diagonal elements (downwards from left to right, above the leading diagonal) . If they are all O, alg 2 wins
    for (int g=0; g<n-4; g++)
    {

        for (int h=0; h<n-4-g; h++)
        {
            if(gameBoard[h][g+h] == 'O' && gameBoard[h+1][g+h+1] == 'O' && gameBoard[h+2][g+h+2] == 'O' && gameBoard[h+3][g+h+3] == 'O' && gameBoard[h+4][g+h+4] == 'O')
            {
                return 2;
            }
        }
    }

    //Check all sets of 5 consecutive diagonal elements (upwards from left to right, above the leading diagonal) . If they are all O, alg 2 wins
    for (int i=n-1; i>=4; i--)
    {
        for (int j=0; j<i-3; j++)
        {
            if(gameBoard[i-j][j] == 'O' && gameBoard[i-j-1][j+1] == 'O' && gameBoard[i-j-2][j+2] == 'O' && gameBoard[i-j-3][j+3] == 'O' && gameBoard[i-j-4][j+4] == 'O')
            {
                return 2;
            }
        }
    }

    //Check all sets of 5 consecutive diagonal elements (upwards from left to right, below the leading diagonal) . If they are all O, alg 2 wins
    for (int k=0; k<n-4; k++)
    {
        for (int l=n-1; l>=4+k; l--)
        {
            if(gameBoard[l][k+n-1-l] == 'O' && gameBoard[l-1][k+n-l-1+1] == 'O' && gameBoard[l-2][k+n-l-1+2] == 'O' && gameBoard[l-3][k+n-l-1+3] == 'O' && gameBoard[l-4][k+n-l-1+4] == 'O')
            {
                return 2;
            }
        }
    }

    return 0;
}
#endif // GOMOKU_H
