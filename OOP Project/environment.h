#include <vector>

class Trainer;
class pokemon;

class Environment
{
private:
    // Non-owning pointers to existing objects
    std::vector<Trainer *> trainers;
    std::vector<Pokemon *> pokemons;

    int nextTrainerId;
    int nextPokemonId;

public:
    Environment();
    ~Environment();

    Trainer *addTrainer(const std::string &name,
                        int wallet = 0,
                        int level = 0);
    pokemon *addPokemon(const std::string &name,
                        const std::string &type = "normal",
                        int level = 1,
                        int maxHp = 100,
                        int atk = 20,
                        const std::vector<std::string> &attacks = {});
};
