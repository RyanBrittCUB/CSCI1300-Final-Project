#include <iostream>
#include <ctime>
#include "board.h"

using namespace std;

/* =========================== Function Prototypes =========================== */

// Recall that we can avoid having main at the bottom of the class by using function prototypes
// What is '&' and why do we use it? 
// Note that spacing for & does not matter as long as it is between the type and name

/*
bool testInitialization(Board & b);
void runVisualCheck(Board& b);
bool testMovement(Board &b);
bool testWinCondition(Board&b);
*/

bool testInitialization(Board &b) {
    cout << "TEST ONE" << endl;
    // Calls one of the public member functions
    if (b.getPlayerPosition(0) == 0 && b.getPlayerPosition(1) == 0) {
        cout << "\tPassed." << endl;
        return true;
    }
    cout << "\tFailed." << endl;
    return false;
}

void runVisualCheck(Board &b) {
    cout << endl << "TEST TWO" << endl << endl;
    b.displayBoard(); // One of the public member funcs - also calls 'displayTrack'
    cout << endl;
}

bool testMovement(Board &b) {
    cout << "TEST THREE (P1 moves to pos 5, P2 moves to pos 2)" << endl;
    
    // This loops allow for five 1 space movements
    for(int i = 0; i < 5; i++) {
        b.movePlayer(0); // Calls one of the public member functions
    }

    // Whereas, this allow for two 1 space movements
    b.movePlayer(1);
    b.movePlayer(1);

    // This should look similar to test one
    if (b.getPlayerPosition(0) == 5 && b.getPlayerPosition(1) == 2) {
        cout << "\tPassed." << endl;
        b.displayBoard(); 
        return true;
    }
    cout << "\tFailed." << endl;
    return false;
}

bool testWinCondition(Board &b) {
    cout << "TEST FOUR" << endl;
    
    bool won = false;
    int safetyCounter = 0;

    // Continue moving Player 1 from where they left off (pos 5)
    while (!won && safetyCounter < 100) {
        won = b.movePlayer(0);
        safetyCounter++;
    }

    // Since P1 started at pos 5, they should need 46 more moves to hit pos 51
    if (won && b.getPlayerPosition(0) == 51) {
        cout << "\tPassed." << endl;
        b.displayBoard();
        return true;
    }
    cout << "\tFailed." << endl;
    return false;
}

/* =========================== MAIN =========================== */



// Our test files will have a main but so will gameEngine.cpp
// We cannot have two main functions in the compile line
// Refer to the written instructions for how to compile/execute test files
int main() {
    srand(time(0));

    // We have four tests to successfully test all public member functions

    // In this test file, we only want to use one board - so we only create one instance
    // By calling the constructor, this also calls 'initializeBoard'
    Board mainBoard;

    // Step 1: Initial State
    if (!testInitialization(mainBoard)) { 
        // What does it mean to return 1 from the main function?
        return 1;
    }

    // Step 2: Visual Check
    runVisualCheck(mainBoard);

    // Step 3: Movement
    if (!testMovement(mainBoard)) {
        return 1;
    }

    // Step 4: Win Condition
    if (!testWinCondition(mainBoard)) {
        return 1;
    }

    cout << endl << "ALL STEPS PASSED" << endl;
    
    return 0;
}

/* =========================== Initialize Functions =========================== */

