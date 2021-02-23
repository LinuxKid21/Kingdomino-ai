#pragma once

enum class TileType
{
    Empty = -1,
    Capital = -2,
    Wheat = 0,
    Forest,
    Water,
    Grass,
    Swamp,
    Mine
};

struct Tile
{
    TileType type;
    int crowns;
};
