// <2453739>
// Muhammad Raees Dindar

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
#include <windows.h>
#include "gomoku.h"

using namespace std;

int main()
{
    gomoku game;                                                    //Object game of class gomoku

    vector <vector<char>> gameBoard;                                //2D vector for gameboard
    int n;                                                          //Gameboard size
    int winner = 0;                                                 //variable to store which algorithm won
    int moveCounter = 0;                                            //Variable to count how many moves have been played
    int P1winCounter = 0;                                           //Variable to count how many times algorithm 1 wins
    int P2winCounter = 0;                                           //Variable to count how many times algorithm 2 wins

    ifstream inData;                                                //Input file
    ofstream outData;                                               //Output file

    inData.open("input.txt");                                       //Open input file, "input.txt"
    outData.open("gomokuResults.txt");                              //Open output file, "gomokuResults.txt"

    while (!inData.eof())                                           //Continue running the code below as long as a value is being read in from the file
    {
        inData >> n;                                                //Read n in from the file
        outData << "size=" << n <<endl;                             //Output to output file

        winner = 0;                                                 //Set value of "winner" to 0, indicating no winner
        gameBoard.clear();                                          //Clear the gameboard vector of all contents. Erasing the previous game

        //Create the gameboard as a 2D vector of size nxn, with all elements set to B (Blank)
        for (int i=0; i<n; i++)
        {
            vector <char> temp;

            for (int j=0; j<n; j++)
            {
                temp.push_back('B');
            }
            gameBoard.push_back(temp);
        }

        while (winner == 0)                                             //Continue running the code below as long as winner = 0, i.e. no winner
        {
            gameBoard = game.boardReset(gameBoard, n);                  //Set all the elements of the gameboard back to B, so a new game can begin in the case of a draw

            while (winner == 0 && moveCounter != n*n)                   //Continue running the code as long as there is no winner and all spaces on the gameboard are not filled
            {
                if (winner == 0 && moveCounter != n*n)                  //Algorithm 1 can play if there is no winner and and all spaces on the gameboard are not filled
                {
                    gameBoard = game.moveP1(gameBoard, n, outData);     //Algorithm 1 makes a move, using the function moveP1
                    winner = game.P1winChecker(gameBoard, n);           //Check if Algorithm 1 has won using the function P1winChecker
                    moveCounter++ ;                                     //Increment the move counter as a move has been made
                }

                if (winner == 0 && moveCounter != n*n)                  //Algorithm 2 can play if there is no winner and and all spaces on the gameboard are not filled
                {
                    gameBoard = game.moveP2(gameBoard, n, outData);     //Algorithm 2 makes a move, using the function moveP2
                    winner = game.P2winChecker(gameBoard, n);           //Check if Algorithm 2 has won using the function P2winChecker
                    moveCounter++ ;                                     //Increment the move counter as a move has been made
                }

            }

            if (winner == 1)                                            //If winner = 1 (alg 1 is the winner)
            {
                outData << "win=alg1" << endl;                          //print "win=alg1" to output file
                P1winCounter++ ;                                        //Increment P1winCounter as alg 1 has won
            }

            if (winner == 2)                                            //If winner = 2 (alg 2 is the winner)
            {
                outData << "win=alg2" <<endl;                           //print "win=alg2" to output file
                P2winCounter++ ;                                        //Increment P1winCounter as alg 1 has won
            }

            moveCounter = 0;                                            //Reset the move counter as the game is over. It is set to 0 for the next game

            Sleep(1000);                                                //Pause the programme for 1 second. This is done as the random number generator that ransomizes moves
                                                                        //uses the computer's clock, and has a resolution of 1 second. To allow new numbers to generate each game,
                                                                        //a one second delay is added between games
        }

        outData << endl;

    }

    outData << "wins alg1=" << P1winCounter << endl;                    //Outputs number of times alg 1 has won to output file
    outData << "wins alg2=" << P2winCounter << endl;                    //Outputs number of times alg 2 has won to output file

    inData.close();                                                     //Close input file
    outData.close();                                                    //Close output file

    return 0;
}
