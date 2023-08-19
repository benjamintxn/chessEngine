#include <iostream>
#include <SFML/Graphics.hpp>
#include <chess.hpp>
#include "functionality.hpp"
#include <string>
#include <cctype>

using namespace std;
using namespace chess;

int main() {

    string startPosition = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";  // Replace with an actual FEN string
    displayBoard board(startPosition);
    board.run();

    return 0;
    
}




