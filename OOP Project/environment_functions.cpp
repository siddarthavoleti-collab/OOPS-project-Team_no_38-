#include "environment.h"
#include "trainer.h"
#include "pokemon.h"

Environment::Environment() : nextTrainerId(1) {}

Environment::~Environment() {
    for (trainer* t : trainers)
        delete t;

    for (pokemon* p : pokemons)
        delete p;
}

trainer* Environment::addTrainer(const std::string& name,
                                 int wallet,
                                 int level) {
    trainer* t = new trainer(name, nextTrainerId, wallet, level);
    trainers.push_back(t);
    ++nextTrainerId;
    return t;
}

pokemon* Environment::addPokemon(
    const std::string& name,
    const std::string& type,
    int level,
    int hp,
    int atk,
    const std::vector<std::string>& attacks) {

    pokemon* p = new pokemon(name, type, level, -1, hp, atk, attacks);
    pokemons.push_back(p);
    return p;
}
