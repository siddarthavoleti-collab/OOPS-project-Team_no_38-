#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <string>
#include <vector>
using namespace std;

class trainer;
class pokemon;

// Creates and owns every trainer and pokemon (frees them in the destructor)
class Environment {
private:
    vector<trainer*> trainers;
    vector<pokemon*> pokemons;
    int nextTrainerId;
public:
    Environment();
    ~Environment();
    trainer* addTrainer(string name, int wallet = 0, int level = 1);
    pokemon* addPokemon(string name, string type = "normal", int level = 1,
                        int hp = 100, int atk = 20,
                        vector<string> attacks = {});
};
#endif
