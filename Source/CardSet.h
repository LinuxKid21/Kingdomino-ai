#pragma once

#include "Card.h"
#include <vector>

class CardSet : public std::vector<Card>
{
public:
    CardSet(bool random = true);

    CardSet removeTopFour();

    static constexpr int MAX_CARDS = 48;

private:
    CardSet(iterator start, iterator end);
};
