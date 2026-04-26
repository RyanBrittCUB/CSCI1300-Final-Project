#include <string>
#include <iostream>

#include "character.h"
#include "path.h"
#include "board.h"
#include "loadCharacters.h"

using namespace std;

int main()
{
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
    cout << "///////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//                                                                                              //" << endl;
    cout << "//       //\\\\  /\\\\        //\\\\  |||||||| ||   ||  ||        //\\\\        //\\\\      //  ||\\\\      //" << endl;
    cout << "//      //  \\\\/  \\\\      //  \\\\    ||    ||___||  ||       //  \\\\      //  \\\\    //   ||  \\\\    //"<< endl;
    cout << "//     //         \\\\    //====\\\\   ||    ||   ||  ||      //====\\\\    //    \\\\  //    ||  //    //" << endl;
    cout << "//    //           \\\\  //      \\\\  ||    ||   ||  |||||  //      \\\\  //      \\\\//     ||//      //" << endl;
    cout << "//                                                                                             //" << endl;
    cout << "////////////////////////////////////////////////////////////////////////////////////////////////" << endl;

    cout << endl << endl << endl;
    cout << "welcome to the game of candyland!" << endl;
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
    while (!(stoi(player2CharacterSelection)>0 && stoi(player2CharacterSelection) < 10 && !(stoi(player2CharacterSelection) == stoi(player1CharacterSelection)))){
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

    Path paths[2] = {player1.getPath(), player2.getPath()};
    Board gameBoard(paths);

    char input = '5';
    int charInt = 0;

    Character *currentPlayerCharacter = &player1;


    cout << "What would you like to do?" << endl;
    cout << "1: review Character status" <<endl;
    cout << "2: print character's name" <<endl;
    cout << "3: display the board" << endl;
    cout << "4: display Path" << endl;
    cout << "5: move forward" << endl;


    while (!(charInt == '5'))
    {
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
            case '6': return -1;
            default: 
                cout << "default ran " << endl;
                break;
        }
    }


        
}