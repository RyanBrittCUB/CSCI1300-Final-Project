#include<iostream>
#include<ctime>

#include"board.h"
#include"character.h"
#include"candyLogic.h"
#include"loadCharacters.h"

using namespace std;

int main() {
    srand(time(0));

    // Create only one instance of the board
    // This way the same board is used throughout the project
    Board gameBoard;

    // An instance of the candyLogic class has been added for you here
    // We recommend you check for the tile's color in gameEngine to trigger a call to one of the four functions in candyLogic
    //candyLogic logic;
    
    Character all_characters[10];

    // loadCharacters arguments: string filename, Character characters[], int max_players
    // Recall that arrays are default pass by reference
    // loaded is the number of characters actually loaded
    int loaded = loadCharacters("characters.txt", all_characters, 10);

    // loadCharacters returns -1 if file not found
    if (loaded <= 0) {
        cout << "Error: Could not load characters." << endl;
        return 1;
    }

    // Select two random characters

    // random index for the first character
    int index1 = rand() % loaded;
    Character p1 = all_characters[index1];

    // random index for the second character
    int index2;
    // we need to make sure it is in the same index as character c1
    do {
        index2 = rand() % loaded;
    } while (index1 == index2);
    Character p2 = all_characters[index2];

    bool gameOver = false;
    int currentPlayer = 0; // 0 for P1, 1 for P2

    cout << "--- Welcome to the CandyLand board game! ---" << endl;
    gameBoard.displayBoard();

    while (!gameOver) {
        // The following code is a short hand way to write a for loop
        // condition ? if true : if false
        string name = (currentPlayer == 0) ? p1.getName() : p2.getName();

        cout << "\nIt is " << name << "'s turn!" << endl;

        cout << "Press Enter to roll the candy-die...";

        cin.get(); // Recall that .get is a way to retrieve one char from the terminal

        // Standard 1-6 dice roll
        int roll = (rand() % 6) + 1;

        cout << "You rolled a " << roll << "!" << endl;

        // Move the player step-by-step to check for a win
        for (int i = 0; i < roll; i++) {
            gameOver = gameBoard.movePlayer(currentPlayer);
            if (gameOver) break;
        }

        gameBoard.displayBoard();

        if (gameOver) {
            cout << "Hooray! " << name << " reached the Candy Castle!" << endl;
        } else {
            // Switch turns
            currentPlayer = (currentPlayer == 0) ? 1 : 0;
        }
    }

    return 0;
}
