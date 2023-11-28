#include "../input/observer.h"
#include "../input/npc.h"

void ConsoleObserver::on_fight(std::shared_ptr<NPC> attacker,std::shared_ptr<NPC> defender, bool win) {
    if (win){
        std::cout << std::endl << "Murder --------" << std::endl;
        attacker->print();
        defender->print();
    }
}

FileObserver::FileObserver(std::string &_filename) : filename(_filename){
    in.open(filename);
}

FileObserver::FileObserver(FileObserver &other) : FileObserver(other.filename){}

FileObserver::FileObserver(FileObserver &&other) : FileObserver(other.filename){}

FileObserver::~FileObserver(){
    in.close();
}

void FileObserver::on_fight(std::shared_ptr<NPC> attacker,std::shared_ptr<NPC> defender, bool win) {
    if(in.is_open()){
        if (win){
            in << std::endl << "Murder --------" << std::endl;
            attacker->save(in);
            defender->save(in);
        }
    }
    
}