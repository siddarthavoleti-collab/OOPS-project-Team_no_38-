#include "trainer.h"

trainer::trainer(string n, int id, int w, int l) {
    name = n;
    trainerid = id;
    wallet = w;
    level = l;
    experience = 0;
}

ostream& operator<<(ostream& out, const trainer& t) {
    out << "Trainer: " << t.name << " (ID " << t.trainerid
        << "), Wallet: " << t.wallet << ", Level: " << t.level << "\n";
    for (int i = 0; i < t.pokemons.size(); i++)
        out << "  " << *t.pokemons[i] << "\n";
    return out;
}

// Input format: name id wallet level
istream& operator>>(istream& in, trainer& t) {
    in >> t.name >> t.trainerid >> t.wallet >> t.level;
    return in;
}

int trainer::findPokemon(string n) const {
    for (int i = 0; i < pokemons.size(); i++)
        if (pokemons[i]->getname() == n) return i;
    return -1;
}

void trainer::catchPokemon(pokemon& p) {
    if (p.isowned()) return;            // already has a trainer
    p.setowner(trainerid);
    pokemons.push_back(&p);
    cout << name << " caught " << p.getname() << "!\n";
}

bool trainer::releasePokemon(string n) {
    int i = findPokemon(n);
    if (i == -1) return false;
    pokemons[i]->setowner(-1);
    pokemons[i] = pokemons[pokemons.size() - 1];   // move last into the gap
    pokemons.pop_back();
    return true;
}

pokemon* trainer::getPokemon(string n) const {
    int i = findPokemon(n);
    if (i == -1) return NULL;
    return pokemons[i];
}

// Swap one of my pokemon with one of theirs
bool trainer::trade(trainer& other, string mine, string theirs) {
    int i = findPokemon(mine);
    int j = other.findPokemon(theirs);
    if (i == -1 || j == -1) return false;

    pokemon* p1 = pokemons[i];
    pokemon* p2 = other.pokemons[j];

    pokemons[i] = p2;
    other.pokemons[j] = p1;
    p1->setowner(other.trainerid);
    p2->setowner(trainerid);
    return true;
}

void trainer::addItem(string item) {
    items.push_back(item);
}

bool trainer::useItem(string item) {
    for (int i = 0; i < items.size(); i++) {
        if (items[i] == item) {
            items[i] = items[items.size() - 1];
            items.pop_back();
            return true;
        }
    }
    return false;
}

void trainer::showItems() const {
    for (int i = 0; i < items.size(); i++)
        cout << "  " << items[i] << "\n";
}

void trainer::addCoins(int amount) {
    if (amount > 0) wallet = wallet + amount;
}

bool trainer::spendCoins(int amount) {
    if (amount <= 0 || amount > wallet) return false;
    wallet = wallet - amount;
    return true;
}

void trainer::winGym(string badge) {
    if (!hasBadge(badge)) badges.push_back(badge);
}

bool trainer::hasBadge(string badge) const {
    for (int i = 0; i < badges.size(); i++)
        if (badges[i] == badge) return true;
    return false;
}

// Every 100 experience points gives one level
void trainer::gainExperience(int amount) {
    if (amount <= 0) return;
    experience = experience + amount;
    level = level + experience / 100;
    experience = experience % 100;
}

void trainer::showProgress() const {
    cout << "Level: " << level << ", Experience: " << experience << "\nBadges:";
    for (int i = 0; i < badges.size(); i++)
        cout << " " << badges[i];
    cout << "\n";
}
