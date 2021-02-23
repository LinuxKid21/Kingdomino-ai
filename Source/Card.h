#pragma once
#include "Tile.h"

struct Card
{
    int rank;
    Tile tiles[2];
};

static const int ALL_CARDS_COUNT = 48;
static const Card ALL_CARDS[ALL_CARDS_COUNT] = 
{
    {1 , {{TileType::Wheat, 0}, {TileType::Wheat, 0}}},
    {2 , {{TileType::Wheat, 0}, {TileType::Wheat, 0}}},

    {3 , {{TileType::Forest, 0}, {TileType::Forest, 0}}},
    {4 , {{TileType::Forest, 0}, {TileType::Forest, 0}}},
    {5 , {{TileType::Forest, 0}, {TileType::Forest, 0}}},
    {6 , {{TileType::Forest, 0}, {TileType::Forest, 0}}},

    {7 , {{TileType::Water, 0}, {TileType::Water, 0}}},
    {8 , {{TileType::Water, 0}, {TileType::Water, 0}}},
    {9 , {{TileType::Water, 0}, {TileType::Water, 0}}},

    {10, {{TileType::Grass, 0}, {TileType::Grass, 0}}},
    {11, {{TileType::Grass, 0}, {TileType::Grass, 0}}},

    {12, {{TileType::Swamp, 0}, {TileType::Swamp, 0}}},
    {13, {{TileType::Wheat, 0}, {TileType::Forest, 0}}},
    {14, {{TileType::Wheat, 0}, {TileType::Water, 0}}},
    {15, {{TileType::Wheat, 0}, {TileType::Grass, 0}}},
    {16, {{TileType::Wheat, 0}, {TileType::Swamp, 0}}},
    {17, {{TileType::Forest, 0}, {TileType::Water, 0}}},
    {18, {{TileType::Forest, 0}, {TileType::Grass, 0}}},

    {19, {{TileType::Wheat, 1}, {TileType::Forest, 0}}},
    {20, {{TileType::Wheat, 1}, {TileType::Water, 0}}},
    {21, {{TileType::Wheat, 1}, {TileType::Grass, 0}}},
    {22, {{TileType::Wheat, 1}, {TileType::Swamp, 0}}},
    {23, {{TileType::Wheat, 1}, {TileType::Mine, 0}}},

    {24, {{TileType::Forest, 1}, {TileType::Wheat, 0}}},
    {25, {{TileType::Forest, 1}, {TileType::Wheat, 0}}},
    {26, {{TileType::Forest, 1}, {TileType::Wheat, 0}}},
    {27, {{TileType::Forest, 1}, {TileType::Wheat, 0}}},

    {28, {{TileType::Forest, 1}, {TileType::Water, 0}}},
    {29, {{TileType::Forest, 1}, {TileType::Grass, 0}}},

    {30, {{TileType::Water, 1}, {TileType::Wheat, 0}}},
    {31, {{TileType::Water, 1}, {TileType::Wheat, 0}}},
    
    {32, {{TileType::Water, 1}, {TileType::Forest, 0}}},
    {33, {{TileType::Water, 1}, {TileType::Forest, 0}}},
    {34, {{TileType::Water, 1}, {TileType::Forest, 0}}},
    {35, {{TileType::Water, 1}, {TileType::Forest, 0}}},

    {36, {{TileType::Wheat, 0}, {TileType::Grass, 1}}},
    {37, {{TileType::Water, 0}, {TileType::Grass, 1}}},
    {38, {{TileType::Wheat, 0}, {TileType::Swamp, 1}}},
    {39, {{TileType::Grass, 0}, {TileType::Swamp, 1}}},

    {40, {{TileType::Mine, 1}, {TileType::Wheat, 0}}},
    
    {41, {{TileType::Wheat, 0}, {TileType::Grass, 2}}},
    {42, {{TileType::Water, 0}, {TileType::Grass, 2}}},
    {43, {{TileType::Wheat, 0}, {TileType::Swamp, 2}}},

    {44, {{TileType::Grass, 0}, {TileType::Swamp, 2}}},
    {45, {{TileType::Mine, 2}, {TileType::Wheat, 0}}},
    {46, {{TileType::Swamp, 0}, {TileType::Mine, 2}}},
    {47, {{TileType::Swamp, 0}, {TileType::Mine, 2}}},
    {48, {{TileType::Wheat, 0}, {TileType::Mine, 3}}},
};