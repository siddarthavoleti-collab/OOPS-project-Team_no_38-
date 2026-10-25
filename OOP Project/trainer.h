#include "pokemon.h"

class pokemon;
class Trainer {
private:
    std::string name;
    int trainerId;
    int wallet;
    int level;

    // Non-owning pointers to Pokémon owned by this trainer.
    std::vector<Pokemon*> pokemons;

public:
    Trainer(const std::string& name, int trainerId,
            int wallet = 0, int level = 0);

    int getId() const;
    const std::string& getName() const;
};
