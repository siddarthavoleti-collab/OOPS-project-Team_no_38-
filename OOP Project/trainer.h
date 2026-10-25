#ifndef TRAINER_H
#define TRAINER_H

#include "pokemon.h"

class trainer {
private:
    string name;
    int trainerid;
    int wallet;
    int level;
    int experience;
    vector<pokemon*> pokemons;   // Association: trainer uses pokemon objects
    vector<string> items;
    vector<string> badges;

    int findPokemon(string name) const;   // helper: index or -1

public:
    friend ostream& operator<<(ostream&, const trainer&);
    friend istream& operator>>(istream&, trainer&);

    trainer(string, int = 0, int = 0, int = 1);

    // Pokemon management
    void catchPokemon(pokemon& p);
    bool releasePokemon(string name);
    pokemon* getPokemon(string name) const;
    bool trade(trainer& other, string mine, string theirs);

    // Inventory
    void addItem(string item);
    bool useItem(string item);
    void showItems() const;

    // Wallet
    void addCoins(int amount);
    bool spendCoins(int amount);

    // Progression
    void winGym(string badge);
    bool hasBadge(string badge) const;
    void gainExperience(int amount);
    void showProgress() const;
};

#endif
