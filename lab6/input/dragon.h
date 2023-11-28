#pragma once

#include "npc.h"

struct Dragon : public NPC
{
    Dragon(int x, int y);
    Dragon(std::ifstream &is);

    void print() override;

    void accept(std::shared_ptr<NPC> attacker,Visitor& visitor);

    void attach(std::shared_ptr<IObserver> observer) override;
    void detach(std::shared_ptr<IObserver> observer) override;

    void save(std::ofstream &os) override;

    friend std::ostream &operator<<(std::ostream &os, Dragon &dragon);
};