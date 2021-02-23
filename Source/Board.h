#pragma once

#include "Tile.h"

class Board
{
public:
    Board();

    Tile getTile(int row, int col) const;
    void setTile(int row, int col, Tile tile);

    int getFirstDrawRow() const;
    int getFirstDrawCol() const;

private:
    static constexpr int SIZE = 9; // can only contain tiles inside 5x5 grid, but there is more room that the 5x5 can fit into

    Tile tiles[SIZE][SIZE];
};
