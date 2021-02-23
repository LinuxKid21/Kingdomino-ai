#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Tile.h"
#include "CardSet.h"

sf::Font createFont()
{
    sf::Font font;
    if (!font.loadFromFile("../Assets/arial.ttf"))
    {
        // error...
    }

    return font;
}

static sf::Font GLOBAL_FONT = createFont();

sf::Color getTileColor(const Tile & tile)
{
    switch (tile.type)
    {
        case TileType::Wheat:
            return sf::Color::Yellow;
        case TileType::Forest:
            return sf::Color(0, 128, 0);
        case TileType::Water:
            return sf::Color(0, 0, 255);
        case TileType::Grass:
            return sf::Color(0, 255, 0);
        case TileType::Swamp:
            return sf::Color(210, 180, 140);
        case TileType::Mine:
            return sf::Color(75, 75, 75);
        case TileType::Capital:
            return sf::Color(75, 75, 125);
        
        default:
            return sf::Color(255, 255, 255);
    }
}

void drawText(sf::Vector2f pos, std::string str, bool centered, sf::RenderWindow & window)
{
    sf::Text text;

    text.setFont(GLOBAL_FONT);
    text.setString(str);
    text.setFillColor(sf::Color::White);
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(2);
    text.setPosition(pos);

    if(centered)
    {
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width/2.0f,
                    textRect.top  + textRect.height/2.0f);
    }

    window.draw(text);
}

void drawTile(sf::Vector2f pos, float tileSize, const Tile & tile, sf::RenderWindow & window)
{
    sf::RectangleShape rect(sf::Vector2f(tileSize, tileSize));
    rect.setPosition(pos);
    rect.setFillColor(getTileColor(tile));
    window.draw(rect);

    std::string text = std::to_string(tile.crowns);
    if(tile.type == TileType::Capital)
    {
        text = "C";
    }
    else if(tile.type == TileType::Empty)
    {
        text = "";
    }
    drawText(pos + sf::Vector2f(tileSize/2, tileSize/2), text, true, window);
}

void drawCard(sf::Vector2f pos, float tileSize, const Card & card, sf::RenderWindow & window)
{
    drawTile(pos, tileSize, card.tiles[0], window);
    drawTile(pos + sf::Vector2f(tileSize, 0), tileSize, card.tiles[1], window);

    drawText(pos + sf::Vector2f(tileSize*2 + 10, tileSize/2 - 20), std::string("Rank: ") + std::to_string(card.rank), false, window);
}

void drawBoard(sf::Vector2f pos, float tileSize, const Board & board, sf::RenderWindow & window)
{
    int start_row = board.getFirstDrawRow();
    int start_col = board.getFirstDrawCol();
    for(int row = start_row; row < start_row+5; row++)
    {
        for(int col = start_col; col < start_col+5; col++)
        {
            int offset_x = (col - start_col) * tileSize;
            int offset_y = (row - start_row) * tileSize;
            drawTile(pos + sf::Vector2f(offset_x, offset_y), tileSize, board.getTile(row, col), window);
        }
    }
}

int main(int argc, const char **argv)
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");

    CardSet cards;
    CardSet topCards = cards.removeTopFour();

    Board board;
    board.setTile(1, 0, Tile{TileType::Grass, 1});

    Board board2;
    board2.setTile(-1, 0, Tile{TileType::Forest, 1});

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        drawBoard(sf::Vector2f(100, 100), 150, board, window);
        drawBoard(sf::Vector2f(100 + 150*5 + 20, 100), 50, board2, window);
        drawText(sf::Vector2f(100 + 150*5 + 20, 100 + 50*5), "Other Player's Board", false, window);

        for(int i = 0;i < topCards.size(); i++)
        {
            drawCard(sf::Vector2f(1400, 100 + i*160), 150, topCards[i], window);
        }

        drawText(sf::Vector2f(1400, 100 + 4*160), "Remaining Cards: " + std::to_string(cards.size()), false, window);

        window.display();
    }

    return 0;
}