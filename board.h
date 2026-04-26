/* TODO: Debug this board.h file */

#include "Tile.h"
#include "path.h"

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
        void initializeTiles(int player_index, Path lanePath);
        bool isPlayerOnTile(int player_index, int pos);
        void displayTile(int player_index, int pos);

    public:
        // Default Constructor
        Board(Path paths[2]);
        void initializeBoard(Path paths[2]);
        void displayTrack(int player_index);
        void displayBoard();
        bool movePlayer(int player_index);
        int getPlayerPosition(int player_index) const ;
        Tile getPlayerPositionTile(int player_index);
};