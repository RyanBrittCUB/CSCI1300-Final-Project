//g++ -std=c++17 -Wall -Werror -Wpedantic board.cpp candyLogic.cpp character.cpp gameEngine.cpp loadCharacters.cpp

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

    cout << all_characters[2].getName() << endl;

    // main Menue:
    cout << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//                                                                                              //" << endl;
    cout << "//       //\\\\  /\\\\        //\\\\  |||||||| ||   ||  ||        //\\\\        //\\\\      //  ||\\\\      //" << endl;
    cout << "//      //  \\\\/  \\\\      //  \\\\    ||    ||___||  ||       //  \\\\      //  \\\\    //   ||  \\\\    //"<< endl;
    cout << "//     //         \\\\    //====\\\\   ||    ||   ||  ||      //====\\\\    //    \\\\  //    ||  //    //" << endl;
    cout << "//    //           \\\\  //      \\\\  ||    ||   ||  |||||  //      \\\\  //      \\\\//     ||//      //" << endl;
    cout << "//                                                                                              //" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////////////////////////" << endl;

    cout << endl << endl << endl;
    cout << "welcome to the game of mathland!" << endl;
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

    string Player1SecretWord = "";
    cout << player1Name << " enter a secret word :";
    cin >> Player1SecretWord;
    player1.setSecretWord(Player1SecretWord);

    cout << "player 1 has choosen player " << player1.getName() << " and the " << player1.getPathName() << endl;

    cout << endl;
    // player 2 selection menue:

    cout << "player 2 please enter your name: ";
    string player2Name;
    cin >> player2Name;

    cout << player2Name << " Please select your character! your options are: " << endl;
    //cout << all_characters[0].printCharacterArray(all_characters, 10);
    for (int i = 0; i < 10; i ++) cout << i << ": " << all_characters[i].getName() << endl;
    cout << "enter the number of the character you wish to select: ";
    
    string player2CharacterSelection;
    cin >> player2CharacterSelection;
    while (!(stoi(player2CharacterSelection)>0 && stoi(player2CharacterSelection) < 10)){
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

    string Player2SecretWord = "";
    cout << player2Name << " enter a secret word :";
    cin >> Player2SecretWord;
    player1.setSecretWord(Player2SecretWord);

    cout << "player 1 has choosen player " << player2.getName() << " and the " << player2.getPathName() << endl;

    cout << endl;

    Path paths[2] = {player1.getPath(), player2.getPath()};
    Board gameBoard(paths);
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
        Character* currentPlayerCharacter = (currentPlayer == 0) ? &player1 : &player2;
        Character* otherPlayerCharacter = (currentPlayer == 0) ? &player2 : &player1;

        cout << "\nIt is " << name << "'s turn!" << endl;

        char input = '5';
        int charInt = 0;
        
        while (!(charInt == '5'))
        {
            cout << "What would you like to do?" << endl;
            cout << "1: review Character status" <<endl;
            cout << "2: print character's name" <<endl;
            cout << "3: display the board" << endl;
            cout << "4: display Path" << endl;
            cout << "5: move forward" << endl;
            cout << "6: display Points" << endl;

            cin >> input; // Recall that .get is a way to retrieve one char from the terminal
            cout << "your Input is: " << input << endl;
            charInt = 0 + input;

            switch (charInt)
            {
                case '1': 
                    cout << (*currentPlayerCharacter).getCharacterString() << endl;
                    break;
                case '2': 
                    cout << (*currentPlayerCharacter).getName() << endl;
                    break;
                case '3': 
                    gameBoard.displayBoard(); 
                    break;
                case '4': 
                    cout << (*currentPlayerCharacter).getPathName() << endl; 
                    break;
                case '5': 
                    break;
                case '6': 
                    cout << player1Name << " has " << player1.getPoints() << " points" << endl;
                    cout << player2Name << " has " << player2.getPoints() << " points" << endl;
                    break;
                case '7': return -1;
                default: 
                    cout << "default ran " << endl;
                    break;
            }
        }
        // Standard 1-6 dice roll
        int roll = (rand() % 6) + 1;

        cout << "You rolled a " << roll << "!" << endl;

        // Move the player step-by-step to check for a win
        for (int i = 0; i < roll; i++) {
            gameOver = gameBoard.movePlayer(currentPlayer);
            if (gameOver) break;
        }

        gameBoard.displayBoard();

        //candyLogic functions:

        Tile currentTile = gameBoard.getPlayerPositionTile(currentPlayer);
        candyLogic tileLogic;
        switch (currentTile.color)
        {
            case 'B': // Blue: candy jar sort -> slove Differential equation
                cout << "you landed on a Blue tile! If your lucky you will be able to sort a Math Exam!" << endl;
                cout << "your Luck is " << (*currentPlayerCharacter).getLuck() << endl;

                if (rand() % 100 < 10*(*currentPlayerCharacter).getLuck()){
                    cout << "Congrats! your luck is high enough! " << endl;
                    string jarString = "Derivative,Theorem,Addition,Integral,Multiplication,Subtraction,Derivative,Derivative";
                    string target = "Derivative";
                    char c = 'a';
                    cout << "you sort the expression with the string " << jarString << endl;
                    cout << "you correctly find the index of " << target << " to be " << tileLogic.candyJarSort(c, jarString, target) << endl;
                    cout << "because you successfully sorted the Exam, you gain 100 points!" << endl;
                    (*currentPlayerCharacter).gainPoints(10);
                } else {
                    cout << "you were not lucky enough this time. you do not gain any points." << endl;
                }
                break;
            case 'P': // Pink: Inventory scramble
                cout << "uh oh you landed on a pink scramble. your focus will be tested and you may loose some points" << endl;

                if (rand() % 100 > 10*(*currentPlayerCharacter).getFocus())
                {
                    string inventory = (*currentPlayerCharacter).getSecretWord();
                    char c2='a';
                    string scramble= tileLogic.inventoryScrambler(c2, inventory);
                    cout << "looks like you werent focused enough. The string " << inventory << "was scrambled into " << scramble << "and you loose 100 points" << endl;
                    (*currentPlayerCharacter).gainPoints(-100);
                } else {
                    cout << "your luck is unmatched! you survive this inventory scrambler!" << endl;
                }
                break;
            case 'T': // Brown: Find Golden ticket
                cout << "You landed on a Brown Tile. you get to look for the Solution to the ODE! this takes a lot of luck!" << endl;
                if ((rand() % 100) -50 < 10*(*currentPlayerCharacter).getLuck())
                {
                    char c4='a';
                    string goldenString= "TheSchroedingerEquationIsAPartialDifferentialEquationThatModelsThePositionOfCertainSubatomicParticlesAsAProbabilityCurve";
                    string goldenTarget= "Models";
                    int PWRBAL= tileLogic.findGoldenTicket(c4, goldenString, goldenTarget);
                    cout << "Congradulations! you found the Solution to the ODE " << goldenTarget << " in the string" << goldenString << " at index " << PWRBAL;
                    cout << " you win 500 points!" << endl;
                    (*currentPlayerCharacter).gainPoints(500);
                } else {
                    cout << "ooooh, looks like you are not lucky enough this time. better luck next time!" << endl;
                }

                break;
            case 'R': // Red: Combine Candies
                cout << "You landed on a red Tile! you get to steel some points from your competition!" << endl;
                cout << "if your ajile enough!" << endl;
                if (rand() % 100 < 10*(*currentPlayerCharacter).getAgility()){
                    string secretWord1 = (*currentPlayerCharacter).getSecretWord();
                    string secretWord2 = (*otherPlayerCharacter).getSecretWord();
                    char c3='a';
                    string wombo_combo= tileLogic.combineCandies(c3, secretWord1, secretWord2);
                    cout << "you successfully combine your secret phrase " << secretWord1 << " and your competitions secret phrase " << secretWord2 << " and combine them into your new phrase: " << wombo_combo << endl;
                    cout << "You sucessfully steal 750 points from the competition!" << endl;
                    (*currentPlayerCharacter).gainPoints(750);
                    (*otherPlayerCharacter).gainPoints(-750);
                } else {
                    cout << "looks like you were not ajile enough. Better luck next time!" << endl;
                }

                break;
            case 'U': // Purple
            cout << "you landed on a Purple tile! If your lucky you will be able to earn the amount of points in an equation!" << endl;
                cout << "your Luck is " << (*currentPlayerCharacter).getLuck() << endl;

                if (rand() % 100 < 10*(*currentPlayerCharacter).getLuck()){
                    cout << "Congrats! your luck is high enough!" << endl;
                    int Var1= rand() % 20;
                    int Var2= rand() % 20;
                    int Var3=rand() % 20;
                    double Sol= Var1/Var2 + Var3;
                    double playerSol;
                    cout << "Your problem is :" << Var1 <<"/"<<Var2<<"+"<<Var3<< endl;
                    cout<< "Enter your answer here!:" << endl;
                    cin >> playerSol;

                    if(playerSol==Sol){
                        cout<<"That's Correct! You Gained " << playerSol<< " Points!" << endl;
                    (*currentPlayerCharacter).gainPoints(Sol);
                    }
                    else{
                        cout << "Whoops! That is incorrect! You lost " << playerSol << " Points!" << endl;
                        (*currentPlayerCharacter).gainPoints(-playerSol);
                    }
                } else {
                    cout << "you were not lucky enough this time. you do not gain or lose any points." << endl;
                }
                break;

                break;
            default:
                cout << "You landed on a green tile. Nothing happens." << endl;
                break;
        }

        if (gameOver) {
            cout << "Hooray! " << name << " reached the End of the Semester!" << endl;
            (*currentPlayerCharacter).gainPoints(1000);
        } else {
            // Switch turns
            currentPlayer = (currentPlayer == 0) ? 1 : 0;
        }
    }

    cout << "Final Scores:" << endl; //Sorting Algorythm
    if(player1.getPoints()>player2.getPoints()){
    cout << player1Name << " recieved " << player1.getPoints() << " Points!" << endl;
    cout << player2Name << " recieved " << player2.getPoints() << " Points!" << endl;
    }
    else if(player1.getPoints()<player2.getPoints()){
    cout << player2Name << " recieved " << player2.getPoints() << " Points!" << endl;
    cout << player1Name << " recieved " << player1.getPoints() << " Points!" << endl;
    }
    else{
        cout << "Both Players recieved " << player1.getPoints() << " Points" << endl;
    }

    if       (player1.getPoints() < player2.getPoints())  cout << player1Name << "wins!" << endl;
    else if  (player1.getPoints() == player2.getPoints()) cout << "it is a tie!" << endl;
    else                                                  cout << player2Name << "wins!" << endl;

    return 0;
}
