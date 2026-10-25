#ifndef TRAINER_H
#define TRAINER_H

#include "pokemon.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class trainer {
private:
    string name;
    int trainerid;
    int wallet;
    int level;
    unordered_map<string, pokemon*> pokemons;
    unordered_map<string, int> inventory;
    vector<string> badges;
    int experience;

public:
    friend ostream& operator<<(ostream&, const trainer&);
    friend istream& operator>>(istream&, trainer&);

    trainer(string, int = 0, int = 0, int = 0,
            vector<pokemon*> = {});

    // Pokémon management
    void catchPokemon(pokemon& p);
    bool releasePokemon(const string& name);
    pokemon* getPokemon(const string& name) const;
    void showinv() const;

    // Trading
    bool trade(trainer& other, const string& myPokemon,
               const string& otherPokemon);

    // Inventory
    void addItem(const string& item, int quantity = 1);
    bool useItem(const string& item);
    void showItems() const;

    // Wallet
    void addCoins(int amount);
    bool spendCoins(int amount);

    // Progression
    void winGym(const string& badge);
    bool hasBadge(const string& badge) const;
    void showProgress() const;

    // Experience and levels
    void gainExperience(int amount);
    void levelUp();
};

#endif
