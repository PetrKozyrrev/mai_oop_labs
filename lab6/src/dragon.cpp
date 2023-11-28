#include "../input/dragon.h"
#include "../input/knight.h"
#include "../input/princess.h"
#include <algorithm>

Dragon::Dragon(int x, int y) : NPC(DragonType, x, y) {}

Dragon::Dragon(std::ifstream &is) : NPC(DragonType, is) {}

void Dragon::print()
{
    std::cout << *this;
}

void Dragon::attach(std::shared_ptr<IObserver> observer) {
    NPC::observers.push_back(observer);
}
void Dragon::detach(std::shared_ptr<IObserver> observer) {
    NPC::observers.erase(std::find(NPC::observers.begin(), NPC::observers.end(), observer));
}

void Dragon::save(std::ofstream &os) 
{
    os << DragonType << std::endl;
    NPC::save(os);
}

std::ostream &operator<<(std::ostream &os, Dragon &dragon)
{
    os << "dragon: " << *static_cast<NPC *>(&dragon) << std::endl;
    return os;
}