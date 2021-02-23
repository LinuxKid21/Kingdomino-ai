#include "Board.h"

#include <algorithm>

Board::Board()
{
    for(int index0 = 0; index0 < SIZE; index0++)
    {
        for(int index1 = 0; index1 < SIZE; index1++)
        {
            tiles[index0][index1].crowns = 0;
            tiles[index0][index1].type = TileType::Empty;
        }
    }

    tiles[4][4].type = TileType::Capital;
}

Tile Board::getTile(int row, int col) const
{
    if(row < -4 || row > 4) throw "BAD!";
    if(col < -4 || col > 4) throw "BAD!";
    
    return tiles[col + 4][row + 4];
}

void Board::setTile(int row, int col, Tile tile)
{
    getTile(row, col);
    
    tiles[col + 4][row + 4] = tile;
}

int Board::getFirstDrawRow() const
{
    int first_row = 9999;
    int last_row = -9999;
    for(int row = 0; row < 9; row++)
    {
        for(int col = 0; col < 9; col++)
        {
            if(tiles[col][row].type != TileType::Empty)
            {
                first_row = std::min(first_row, row);
                last_row = std::max(last_row, row);
            }
        }
    }

    int distance = last_row - first_row;
    int center = first_row + distance / 2;

    return std::max(center - 2, 0) - 4;
}

int Board::getFirstDrawCol() const
{
    int first_col = 9999;
    int last_col = -9999;
    for(int col = 0; col < 9; col++)
    {
        for(int row = 0; row < 9; row++)
        {
            if(tiles[col][row].type != TileType::Empty)
            {
                first_col = std::min(first_col, col);
                last_col = std::max(last_col, col);
            }
        }
    }

    int distance = last_col - first_col;
    int center = first_col + distance / 2;

    return std::max(center - 2, 0) - 4;
}
