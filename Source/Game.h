#pragma once

#include "Board.h"
#include "CardSet.h"

class Game
{
public:
    Game();

private:
    Board board;
    CardSet cards;
};