#include "../input/dragon.h"
#include "../input/knight.h"
#include "../input/princess.h"
#include <algorithm>

Knight::Knight(int x, int y) : NPC(KnightType, x, y) {}

Knight::Knight(std::ifstream &is) : NPC(KnightType, is) {}

void Knight::print()
{
    std::cout << *this;
}

void Knight::save(std::ofstream &os)
{
    os << KnightType << std::endl;
    NPC::save(os);
}

void Knight::attach(std::shared_ptr<IObserver> observer) {
    NPC::observers.push_back(observer);
}
void Knight::detach(std::shared_ptr<IObserver> observer) {
    NPC::observers.erase(std::find(NPC::observers.begin(), NPC::observers.end(), observer));
}

std::ostream &operator<<(std::ostream &os, Knight &knight)
{
    os << "knight: " << *static_cast<NPC *>(&knight) << std::endl;
    return os;
}