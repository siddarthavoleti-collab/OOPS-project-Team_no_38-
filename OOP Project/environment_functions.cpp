#include "environment.h"


Environment::Environment(){
    nextTrainerId=1;
    nextPokemonId=1;
}

Environment::~Environment() {
    for (Trainer* t : trainers) {
        delete t;
    }

    for (pokemon* p : pokemons) {
        delete p;
    }
}

Trainer* Environment::addTrainer(
    const std::string& name,
    int wallet,
    int level
) {
    Trainer* t = new Trainer(
        name,
        nextTrainerId,
        wallet,
        level
    );

    trainers.push_back(t);
    nextTrainerId++;

    return t;
}