#include "../input/dragon.h"
#include "../input/knight.h"
#include "../input/princess.h"
#include <algorithm>

Princess::Princess(int x, int y) : NPC(PrincessType, x, y) {}

Princess::Princess(std::ifstream &is) : NPC(PrincessType, is) {}

void Princess::print()
{
    std::cout << *this;
}

void Princess::save(std::ofstream &os)
{
    os << PrincessType << std::endl;
    NPC::save(os);
}

void Princess::attach(std::shared_ptr<IObserver> observer) {
    NPC::observers.push_back(observer);
}
void Princess::detach(std::shared_ptr<IObserver> observer) {
    NPC::observers.erase(std::find(NPC::observers.begin(), NPC::observers.end(), observer));
}

std::ostream &operator<<(std::ostream &os, Princess &princess)
{
    os << "princess: " << *static_cast<NPC*>(&princess) << std::endl;
    return os;
}