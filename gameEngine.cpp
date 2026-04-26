#include<iostream>
#include<ctime>

#include"board.h"
#include"character.h"
#include"candyLogic.h"
#include"loadCharacters.h"
#include"path.h"

using namespace std;

//Compile code g++ -std=c++17 -Wall -Werror -Wpedantic gameEngine.cpp candyLogic.cpp board.cpp character.cpp loadCharacters.cpp -o game.exe

int main() {
    srand(time(0));

    

    // Create only one instance of the board
    Board gameBoard;

    // An instance of the candyLogic class has been added for you here
    // We recommend you check for the tile's color in gameEngine to trigger a call to one of the four functions in candyLogic
    //candyLogic logic;
    
    // creating character list from characters file:
    string fileName = "characters.txt";
    const int test_numberOfPlayers = 10;
    Character all_characters[test_numberOfPlayers];

    int loaded = loadCharacters(fileName, all_characters, test_numberOfPlayers);
    // loadCharacters arguments: string filename, Character characters[], int max_players
    // Recall that arrays are default pass by reference
    // loaded is the number of characters actually loaded

    // loadCharacters returns -1 if file not found
    if (loaded <= 0) {
        cout << "Error: Could not load characters." << endl;
        return -1;
    }

    cout << all_characters[0].getName() << endl;

    // main Menue:
    cout << endl;
    cout << "///////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//                                                                                              //" << endl;
    cout << "//       //\\\\  /\\\\        //\\\\  |||||||| ||   ||  ||        //\\\\        //\\\\      //  ||\\\\      //" << endl;
    cout << "//      //  \\\\/  \\\\      //  \\\\    ||    ||___||  ||       //  \\\\      //  \\\\    //   ||  \\\\    //"<< endl;
    cout << "//     //         \\\\    //====\\\\   ||    ||   ||  ||      //====\\\\    //    \\\\  //    ||  //    //" << endl;
    cout << "//    //           \\\\  //      \\\\  ||    ||   ||  |||||  //      \\\\  //      \\\\//     ||//      //" << endl;
    cout << "//                                                                                             //" << endl;
    cout << "////////////////////////////////////////////////////////////////////////////////////////////////" << endl;

    cout << endl << endl << endl;
    cout << "welcome to the game of MandyLand!" << endl;
    cout << "This is a text based two player game." << endl;
    cout << "To start, each player will choose their character and some atributes." << endl;

    // player 1 start menue:

    cout << "player 1 please enter your name: ";
    string player1Name;
    cin >> player1Name;
    cout << player1Name << endl;

    cout << player1Name << " Please select your character! your options are: " << endl;
    for (int i = 0; i < 10; i ++) cout << i << ": " << all_characters[i].getName() << endl;
    cout << "enter the number of the character you wish to select: ";
    
    string player1CharacterSelection;
    cin >> player1CharacterSelection;
    while (!(stoi(player1CharacterSelection)>=0 && stoi(player1CharacterSelection) < 10)){
        cout << "ops... Thats not a valid input! Please enter a number corresponding to one of the characters above (with no spaces): ";
        cin >> player1CharacterSelection;
    }
    Character player1 = all_characters[stoi(player1CharacterSelection)];

    cout << player1Name << " enter a number for the path you would like to choose! Your options are:" << endl;
    cout << " - The abstract path: this gives +10 agility, +5 luck, and -10 focus" << endl;
    cout << "- The applied path: this gives -10 agility, -5 luck, and +15 focus" << endl;
    cout << "type A for the abstract path and B for the applied path: ";

    string player1PathType;
    cin >> player1PathType;
    while (!(player1PathType == "A" or player1PathType == "B")){
        cout << "ops, that's not a valid input. please enter 'A' or 'B' ";
        cin >> player1PathType;
    }
    if (player1PathType == "A") player1.setCharacterPath(ABSTRACT_PATH);
    else                        player1.setCharacterPath(APPLIED_PATH);

    cout << "player 1 has choosen player " << player1.getName() << "and the " << player1.getPathName() << endl;

    cout << endl;
    // player 2 selection menue:

    cout << "player 2 please enter your name: ";
    string player2Name;
    cin >> player2Name;

    cout << player2Name << " Please select your character! your options are: " << endl;
    cout << all_characters[0].printCharacterArray(all_characters, 10);
    cout << "enter the number of the character you wish to select: ";
    
    string player2CharacterSelection;
    cin >> player2CharacterSelection;
    while (!(stoi(player1CharacterSelection)>0 && stoi(player2CharacterSelection) < 10)){
        cout << "ops... Thats not a valid input! Please enter a number corresponding to one of the characters above (with no spaces): ";
        cin >> player2CharacterSelection;
    }
    Character player2 = all_characters[stoi(player1CharacterSelection)];

    cout << player2Name << " enter a number for the path you would like to choose! Your options are:" << endl;
    cout << " - The abstract path: this gives +10 agility, +5 luck, and -10 focus" << endl;
    cout << "- The applied path: this gives -10 agility, -5 luck, and +15 focus" << endl;
    cout << "type A for the abstract path and B for the applied path: ";

    string player2PathType;
    cin >> player2PathType;
    while (!(player2PathType == "A" or player2PathType == "B")){
        cout << "ops, that's not a valid input. please enter 'A' or 'B' ";
        cin >> player2PathType;
    }
    if (player2PathType == "A") player2.setCharacterPath(ABSTRACT_PATH);
    else                        player2.setCharacterPath(APPLIED_PATH);

    cout << "player 1 has choosen player " << player2.getName() << "and the " << player2.getPathName() << endl;

    cout << endl;



/*
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
*/

    bool gameOver = false;
    int currentPlayer = 0; // 0 for P1, 1 for P2

    cout << "--- Welcome to the MathLand board game! ---" << endl;
    gameBoard.displayBoard();

    while (!gameOver) {
        // The following code is a short hand way to write a for loop
        // condition ? if true : if false
        string name = (currentPlayer == 0) ? player1Name : player2Name;

        cout << "\nIt is " << name << "'s turn!" << endl;

        cout << "Press Enter to roll the probablity theory-die...";

        cin.get(); // Recall that .get is a way to retrieve one char from the terminal

        // Standard 1-6 dice roll
        int roll = (rand() % 6) + 1;

        cout << "You rolled a " << roll << "!" << endl;

        // Move the player step-by-step to check for a win
        for (int i = 0; i < roll; i++) {
            gameOver = gameBoard.movePlayer(currentPlayer);
            if (gameOver) break;
            /*else if (If orange run mathematical expression sort){
                give string of mathematical expressions
                find Laplace
                if number correct +5 points
                }
            else if(tile is blue){
                
            }
            */
            
        }

        gameBoard.displayBoard();

        if (gameOver) {
            cout << "Hooray! " << name << " reached the End of the Semester!" << endl;
        } else {
            // Switch turns
            currentPlayer = (currentPlayer == 0) ? 1 : 0;
        }
    }

    return 0;
}
