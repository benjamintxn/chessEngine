#ifndef FUNCTIONALITY_HPP
#define FUNCTIONALITY_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <chess.hpp>

using namespace std;
using namespace chess;

class displayBoard {
    
public:
    
    displayBoard(const string& fen);

    // Keep track of the selected piece's texture index and position
    int selectedTextureIndex = -1;
    sf::Vector2i selectedPosition;

    void run() {
        
        while (window.isOpen()) {
            
            sf::Event event;
            while (window.pollEvent(event)) {
                
                if (event.type == sf::Event::Closed) {
                    
                    window.close();
                    
                }
                
                if (event.type == sf::Event::MouseButtonPressed) {
                    
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        
                        sf::Vector2i clickPosition(event.mouseButton.x, event.mouseButton.y);
                        handleMouseClick(clickPosition);
                        
                    }
                    
                }
                
                if (event.type == sf::Event::MouseButtonReleased) {
                    
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        
                        sf::Vector2i releasePosition(event.mouseButton.x, event.mouseButton.y);
                        handleMouseRelease(releasePosition);
                        
                    }
                    
                }
                
            }
            
            render();
            
        }
        
    }

    void handleMouseClick(const sf::Vector2i& clickPosition);
    void handleMouseRelease(const sf::Vector2i& releasePosition);

private:
    
    void loadTextures();
    void setupBoardFromFEN(const string& fen);
    void render();

    sf::RenderWindow window;
    vector<sf::Texture> pieceTextures;
    vector<sf::Sprite> pieceSprites;
    const int squareSize = 64; // Adjust this to your square size
    
};

void displayBoard::handleMouseClick(const sf::Vector2i& clickPosition) {
    
    // Convert pixel position to chessboard coordinates
    int file = clickPosition.x / squareSize;
    int rank = clickPosition.y / squareSize;

    // Check if there's a piece at the clicked position
    for (size_t i = 0; i < pieceSprites.size(); ++i) {
        
        sf::FloatRect bounds = pieceSprites[i].getGlobalBounds();
        if (bounds.contains(static_cast<float>(clickPosition.x), static_cast<float>(clickPosition.y))) {
            
            // Store the selected piece's texture index and position
            selectedTextureIndex = static_cast<int>(i);
            selectedPosition = sf::Vector2i(file, rank);
            break;
            
        }
        
    }
    
}

void displayBoard::handleMouseRelease(const sf::Vector2i& releasePosition) {
    
    if (selectedTextureIndex != -1) {
        
        // Convert pixel position to chessboard coordinates
        int file = releasePosition.x / squareSize;
        int rank = releasePosition.y / squareSize;

        // Check if the release position is a valid square for the selected piece to move
        // Perform the necessary checks for valid moves, update FEN, etc.

        // If the move is valid, update the selected piece's position
        pieceSprites[selectedTextureIndex].setPosition(file * squareSize, rank * squareSize);

        // Clear the selectedTextureIndex and selectedPosition variables
        selectedTextureIndex = -1;
        selectedPosition = sf::Vector2i(-1, -1);

        // Redraw the board
        render();
        
    }
    
}

// Implement the constructor
displayBoard::displayBoard(const string& fen) {
    
    loadTextures();
    setupBoardFromFEN(fen);
    
    // Create the window
    window.create(sf::VideoMode(8 * squareSize, 8 * squareSize), "Chess Board");
    
}

// Implement the setupBoardFromFEN method
void displayBoard::setupBoardFromFEN(const string& fen) {
    // Parse the FEN and position the pieces accordingly

    // Clear existing sprites
    pieceSprites.clear();

    // Tokenize the FEN string to get the piece positions segment
    string piecesFEN = fen.substr(0, fen.find(' '));

    int rank = 7, file = 0;

    // Loop through characters in piecesFEN
    for (char c : piecesFEN) {
        
        if (isdigit(c)) {
            
            // Skip empty squares
            file += c - '0';
            
        } else if (c == '/') {
            
            // Move to the next rank
            rank--;
            file = 0;
            
        } else {
            
            // Map FEN character to piece texture index
            int textureIndex = -1; // Initialize with an invalid value
            
            unordered_map<char, int> pieceTextureIndices = {
                
                {'p', 0}, {'k', 1}, {'q', 2}, {'b', 3}, {'n', 4}, {'r', 5},
                {'P', 6}, {'K', 7}, {'Q', 8}, {'B', 9}, {'N', 10}, {'R', 11}
                
            };

            textureIndex = pieceTextureIndices[c];
            
            // Inside setupBoardFromFEN method
            sf::Sprite sprite(pieceTextures[textureIndex]);
            sprite.setPosition(file * squareSize, rank * squareSize);
            sprite.setScale(static_cast<float>(squareSize) / sprite.getTexture()->getSize().x, static_cast<float>(squareSize) / sprite.getTexture()->getSize().y);
            pieceSprites.push_back(sprite);

            file++;
            
        }
        
    }
    
}

// Implement the loadTextures method
void displayBoard::loadTextures() {
    
    vector<string> pieceNames = {
        
        "w_pawn", "w_king", "w_queen", "w_bishop", "w_knight", "w_rook",
        "b_pawn", "b_king", "b_queen", "b_bishop", "b_knight", "b_rook"
        
    };

    for (const string& pieceName : pieceNames) {
        
        sf::Texture pieceTexture;
        pieceTexture.loadFromFile("/Users/bentan/chessEngine/pieces/" + pieceName + ".png");
        pieceTextures.push_back(pieceTexture);
        
    }
    
}

void displayBoard::render() {
    
    window.clear();
    
    // Render the board squares
    for (int rank = 0; rank < 8; ++rank) {
        
        for (int file = 0; file < 8; ++file) {
            
            sf::RectangleShape square(sf::Vector2f(squareSize, squareSize));
            if ((rank + file) % 2 == 0) {
                
                square.setFillColor(sf::Color(210, 180, 140)); // Light square
                
            } else {
                
                square.setFillColor(sf::Color(110, 80, 20)); // Dark square
                
            }
            
            square.setPosition(file * squareSize, rank * squareSize);
            window.draw(square);
            
        }
        
    }
    
    // Render piece sprites
    for (const auto& sprite : pieceSprites) {
        
        window.draw(sprite);
        
    }

    window.display();
    
}

class displayPiece {
    
public:
    
    displayPiece() : textures(12), sprites(12) {
        
        const string pieceName[12] = {"w_pawn", "w_king", "w_queen", "w_bishop", "w_knight", "w_rook", "b_pawn", "b_king", "b_queen", "b_bishop", "b_knight", "b_rook"};
        
        for (int i = 0; i < 12; i++) {
            
            textures[i].loadFromFile("/Users/bentan/chessEngine/pieces/" + pieceName[i] + ".png");
            textures[i].setSmooth(true);
            sprites[i].setTexture(textures[i]);
            
        }
        
    }

private:
    
    vector<sf::Texture> textures;
    vector<sf::Sprite> sprites;
    
};

#endif // FUNCTIONALITY_HPP
