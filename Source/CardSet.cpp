#include "CardSet.h"

#include <algorithm>
#include <random>

CardSet::CardSet(bool random)
{
    reserve(MAX_CARDS);

    push_back({1 , {{TileType::Wheat, 0}, {TileType::Wheat, 0}} });
    push_back({2, {{TileType::Wheat, 0}, {TileType::Wheat, 0}} });

    push_back({3, {{TileType::Forest, 0}, {TileType::Forest, 0}} });
    push_back({4, {{TileType::Forest, 0}, {TileType::Forest, 0}} });
    push_back({5, {{TileType::Forest, 0}, {TileType::Forest, 0}} });
    push_back({6, {{TileType::Forest, 0}, {TileType::Forest, 0}} });

    push_back({7, {{TileType::Water, 0}, {TileType::Water, 0}} });
    push_back({8, {{TileType::Water, 0}, {TileType::Water, 0}} });
    push_back({9, {{TileType::Water, 0}, {TileType::Water, 0}} });

    push_back({10, {{TileType::Grass, 0}, {TileType::Grass, 0}} });
    push_back({11, {{TileType::Grass, 0}, {TileType::Grass, 0}} });

    push_back({12, {{TileType::Swamp, 0}, {TileType::Swamp, 0}} });
    push_back({13, {{TileType::Wheat, 0}, {TileType::Forest, 0}} });
    push_back({14, {{TileType::Wheat, 0}, {TileType::Water, 0}} });
    push_back({15, {{TileType::Wheat, 0}, {TileType::Grass, 0}} });
    push_back({16, {{TileType::Wheat, 0}, {TileType::Swamp, 0}} });
    push_back({17, {{TileType::Forest, 0}, {TileType::Water, 0}} });
    push_back({18, {{TileType::Forest, 0}, {TileType::Grass, 0}} });

    push_back({19, {{TileType::Wheat, 1}, {TileType::Forest, 0}} });
    push_back({20, {{TileType::Wheat, 1}, {TileType::Water, 0}} });
    push_back({21, {{TileType::Wheat, 1}, {TileType::Grass, 0}} });
    push_back({22, {{TileType::Wheat, 1}, {TileType::Swamp, 0}} });
    push_back({23, {{TileType::Wheat, 1}, {TileType::Mine, 0}} });

    push_back({24, {{TileType::Forest, 1}, {TileType::Wheat, 0}} });
    push_back({25, {{TileType::Forest, 1}, {TileType::Wheat, 0}} });
    push_back({26, {{TileType::Forest, 1}, {TileType::Wheat, 0}} });
    push_back({27, {{TileType::Forest, 1}, {TileType::Wheat, 0}} });

    push_back({28, {{TileType::Forest, 1}, {TileType::Water, 0}} });
    push_back({29, {{TileType::Forest, 1}, {TileType::Grass, 0}} });

    push_back({30, {{TileType::Water, 1}, {TileType::Wheat, 0}} });
    push_back({31, {{TileType::Water, 1}, {TileType::Wheat, 0}} });
    
    push_back({32, {{TileType::Water, 1}, {TileType::Forest, 0}} });
    push_back({33, {{TileType::Water, 1}, {TileType::Forest, 0}} });
    push_back({34, {{TileType::Water, 1}, {TileType::Forest, 0}} });
    push_back({35, {{TileType::Water, 1}, {TileType::Forest, 0}} });

    push_back({36, {{TileType::Wheat, 0}, {TileType::Grass, 1}} });
    push_back({37, {{TileType::Water, 0}, {TileType::Grass, 1}} });
    push_back({38, {{TileType::Wheat, 0}, {TileType::Swamp, 1}} });
    push_back({39, {{TileType::Grass, 0}, {TileType::Swamp, 1}} });

    push_back({40, {{TileType::Mine, 1}, {TileType::Wheat, 0}} });
    
    push_back({41, {{TileType::Wheat, 0}, {TileType::Grass, 2}} });
    push_back({42, {{TileType::Water, 0}, {TileType::Grass, 2}} });
    push_back({43, {{TileType::Wheat, 0}, {TileType::Swamp, 2}} });

    push_back({44, {{TileType::Grass, 0}, {TileType::Swamp, 2}} });
    push_back({45, {{TileType::Mine, 2}, {TileType::Wheat, 0}} });
    push_back({46, {{TileType::Swamp, 0}, {TileType::Mine, 2}} });
    push_back({47, {{TileType::Swamp, 0}, {TileType::Mine, 2}} });
    push_back({48, {{TileType::Wheat, 0}, {TileType::Mine, 3}} });

    if(random)
    {
        std::shuffle( begin(), end(), std::mt19937{ std::random_device{}() } ) ;
    }
}

CardSet CardSet::removeTopFour()
{
    if(empty()) return CardSet(begin(), begin());

    CardSet topFour = CardSet(begin(), begin()+4);
    erase(begin(), begin()+4);

    std::sort(topFour.begin(), topFour.end(), [](const Card & a, const Card & b){ return a.rank < b.rank; });

    return topFour;
}

CardSet::CardSet(iterator start, iterator end) : std::vector<Card>(start, end)
{}