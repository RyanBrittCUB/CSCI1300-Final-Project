/* TODO: Debug this board.h file */

#include "Tile.h"

class Board {
    private:
        // What does it mean to have variable static and const?
        // What happens if these variables are not static nor const?
        static const int _BOARD_SIZE = 52;
        static const int _MAX_PLAYERS = 2;

        // Composition!
        Tile _tiles[2][_BOARD_SIZE];

        int _player_position[_MAX_PLAYERS];

        // Private member functions --> Helper functions
        void initializeTiles(int player_index) {}
        bool isPlayerOnTile(int player_index, int pos) {}
        void displayTile(int player_index, int pos) {}

    public:
        // Default Constructor

        void initializeBoard() {}
        void displayTrack(int player_index) {}
        void displayBoard() {}
        bool movePlayer(int player_index) {}
        int getPlayerPosition(int player_index) const {}
}