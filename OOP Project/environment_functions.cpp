#include "environment.h"
#include "trainer.h"
#include "pokemon.h"

Environment::Environment() {
    nextTrainerId = 1;
}

Environment::~Environment() {
    for (int i = 0; i < trainers.size(); i++)
        delete trainers[i];
    for (int i = 0; i < pokemons.size(); i++)
        delete pokemons[i];
}

trainer* Environment::addTrainer(string name, int wallet, int level) {
    trainer* t = new trainer(name, nextTrainerId, wallet, level);
    trainers.push_back(t);
    nextTrainerId++;
    return t;
}

pokemon* Environment::addPokemon(string name, string type, int level,
                                 int hp, int atk, vector<string> attacks) {
    pokemon* p = new pokemon(name, type, level, -1, hp, atk, attacks);
    pokemons.push_back(p);
    return p;
}
