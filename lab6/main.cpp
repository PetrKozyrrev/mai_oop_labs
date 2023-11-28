#include "input/npc.h"
#include "input/dragon.h"
#include "input/knight.h"
#include "input/princess.h"

bool success;

// Фабрики -----------------------------------
std::shared_ptr<NPC>factory(std::ifstream &is)
{
    std::shared_ptr<NPC> result;
    int type{0};
    if (is >> type)
    {
        switch (type)
        {
        case DragonType:
            result = std::make_shared<Dragon>(is);
            break;
        case KnightType:
            result = std::make_shared<Knight>(is);
            break;
        case PrincessType:
            result = std::make_shared<Princess>(is);
            break;
        }
    }
    else
        std::cerr << "unexpected NPC type:" << type << std::endl;

    return result;
}

std::shared_ptr<NPC> factory(NpcType type, int x, int y)
{
    std::shared_ptr<NPC> result;
    switch (type)
    {
    case DragonType:
        result = std::make_shared<Dragon>(x, y);
        break;
    case KnightType:
        result = std::make_shared<Knight>(x, y);
        break;
    case PrincessType:
        result = std::make_shared<Princess>(x, y);
        break;
    default:
        break;
    }
    return result;
}

// save array to file
void file_save(const set_t &array, const std::string &filename)
{
    std::ofstream fs;
    fs.open(filename);
    if(fs.is_open()){
        fs << array.size() << std::endl;
        for (auto &n : array)
            n->save(fs);
        fs.close();
    }
    else{
        std::cerr << "FILE NOT OPEN" << std::endl;
    }
}

set_t load(const std::string &filename)
{
    set_t result;
    std::ifstream is;
    is.open(filename);
    if (is.good() && is.is_open())
    {
        int count;
        is >> count;
        for (int i = 0; i < count; ++i)
            result.insert(factory(is));
        is.close();
    }
    else
        std::cerr << "Error: " << std::strerror(errno) << std::endl;
    return result;
}

// print to screen
std::ostream &operator<<(std::ostream &os, const set_t &array)
{
    for (auto &n : array)
        n->print();
    return os;
}

class Visitor{
public:
    virtual int visit(Princess* element) = 0;
    virtual int visit(Dragon* element) = 0;
    virtual int visit(Knight* element) = 0;
};

class ConcreteVisitor1 : public Visitor {
public:

    int visit(Princess* element) override {
        //std::cout << "VisitPrincess\n";
        return 1;
    }
    
    int visit(Dragon* element) override {
        //std::cout << "visitDragon\n";
        return 2;
    }

    int visit(Knight* element) override {
        //std::cout << "visitKinght\n";
        return 3;
    }
};

void Princess::accept(std::shared_ptr<NPC> attacker, Visitor& visitor) {
    int res = 0;
    if(dynamic_cast<Dragon*>(attacker.get()))
        res = visitor.visit(dynamic_cast<Dragon*>(attacker.get()));
    
    if(res == 2) success = true;
}

void Dragon::accept(std::shared_ptr<NPC> attacker,Visitor& visitor) {
    int res = 0;
    if(dynamic_cast<Knight*>(attacker.get()))
        res = visitor.visit(dynamic_cast<Knight*>(attacker.get()));
    
    if(res == 3) success = true;
}

void Knight::accept(std::shared_ptr<NPC> attacker,Visitor& visitor) {}

set_t fight(const set_t &array, size_t distance,Visitor& visitor)
{
    set_t dead_list;

    for (const auto &attacker : array)
        for (const auto &defender : array)
            if ((attacker != defender) && (attacker->is_close(defender, distance)))
            {
                success = false;
                defender->accept(attacker,visitor);
                if (success){
                    defender->notify(attacker,true);
                    dead_list.insert(defender);
                }
            }

    return dead_list;
}

int main()
{
    srand(time(NULL));
    std::string START_FILENAME = "../npc.txt"; 
    std::string LOG_FILENAME = "../log.txt";

    set_t array; // монстры

    // Гененрируем начальное распределение монстров
    std::cout << "Generating ..." << std::endl;
    for (size_t i = 0; i < 20; ++i)
        array.insert(factory(NpcType(std::rand() % 3 + 1),std::rand() % 500,std::rand() % 500));
    
    std::cout << "Saving ..." << std::endl;
    file_save(array, START_FILENAME);

    std::cout << "Loading ..." << std::endl;
    array = load(START_FILENAME);

    ConsoleObserver consObserv;
    std::shared_ptr<ConsoleObserver> ob = std::make_shared<ConsoleObserver>(consObserv);

    FileObserver fileObserv(LOG_FILENAME);
    std::shared_ptr<FileObserver> fb = std::make_shared<FileObserver>(fileObserv);

    for(auto& elem: array){
        elem->attach(ob);
        elem->attach(fb);
    }

    ConcreteVisitor1 visitor;

    std::cout << "Fighting ..." << std::endl << array;

    for (size_t distance = 20; (distance <= 500) && !array.empty(); distance += 50)
    {
        auto dead_list = fight(array, distance,visitor);
        for (auto &d : dead_list)
            array.erase(d);
        
        std::cout << "Fight stats ----------" << std::endl
                  << "distance: " << distance << std::endl
                  << "killed: " << dead_list.size() << std::endl
                  << std::endl << std::endl;

    }

    std::cout << "Survivors:" << array;

    return 0;
}