/* Class: TicTacToe
 * Author: Lauren Childers
 * Description: A program that implements the game Tic-Tac-Toe
 */

#include <iostream>
#include "time.h"
#include "TicTacToe.h"
using namespace std;

int main() {

    // FINISH ME
    TicTacToe game;
    int row, col, players;
    srand(time(NULL));

    // user input number of players, must be 1 or 2 otherwise invalid
    while (true) {
        cout << "One-player or Two-player (1 or 2): ";
        cin >> players;
        if (players != 1 && players != 2) {
            cout << "Invalid entry." << endl;
        }
        else {
            break;
        }
    }

    game.initializeBoard();
    game.printBoard(); // print empty board to begin

    // game for two players
    if (players == 2) {
        // game loop, runs until there is a win or the board is full
        while (!game.checkForWin() && !game.isBoardFull()) {
            cout << "Player: " << game.getCurrentPlayerNumber() << endl;
            cout << "Enter row and column: ";
            cin >> row >> col;
            if (row > 3 || row < 1 || col > 3 || col < 1) { // if statement checks to see that the user row and col are within range
                cout << "Invalid entry." << endl;
            }
            else {
                game.placeMark(row-1, col-1);
                game.printBoard();
                game.changePlayer();
            }
        }
    }

    // game for one player versus the computer
    if (players == 1) {
        int p = rand()%2;
        if (p == 1) { // randomize who begins
            game.changePlayer();
        }
        // game loop runs until there is a win or the board is full
        while (!game.checkForWin() && !game.isBoardFull()) {
            // user turn = Player 1
            if (game.getCurrentPlayerNumber() == 1) {
                cout << "Player: " << game.getCurrentPlayerNumber() << endl;
                cout << "Enter row and column: ";
                cin >> row >> col;
                if (row > 3 || row < 1 || col > 3 || col < 1) { // if statement checks to see that the user row and col are within range
                    cout << "Invalid entry." << endl;
                }
                else {
                    game.placeMark(row-1, col-1);
                    game.printBoard();
                    game.changePlayer();
                }
            }
            // computer turn = Player 2
            else {
                cout << "Player: " << game.getCurrentPlayerNumber() << endl;
                cout << "Enter row and column: ";
                row = rand() % 3 + 1;
                col = rand() % 3 + 1;
                cout << row << " " << col << endl;
                game.placeMark(row - 1, col - 1);
                game.printBoard();
                game.changePlayer();
            }
        }
    }

    // the case that there is a winner
    if(game.checkForWin()) {
        game.changePlayer(); // changes the player number back to the player with winning move
        cout << "Player " << game.getCurrentPlayerNumber() << " wins!" << endl;
    }

    // the case that the board is full, i.e. no winner
    if(game.isBoardFull()) {
        cout << "Board is full, its a tie!" << endl;
    }

    return 0;
}