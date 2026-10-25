#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <string>
#include <vector>

class trainer;
class pokemon;

class Environment {
private:
    std::vector<trainer*> trainers;
    std::vector<pokemon*> pokemons;
    int nextTrainerId;

public:
    Environment();
    ~Environment();

    trainer* addTrainer(const std::string& name,
                        int wallet = 0,
                        int level = 1);

    pokemon* addPokemon(const std::string& name,
                        const std::string& type = "normal",
                        int level = 1,
                        int hp = 100,
                        int atk = 20,
                        const std::vector<std::string>& attacks = {});
};

#endif
