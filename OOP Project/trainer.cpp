#include "trainer.h"

trainer::trainer(string n, int id, int w, int l, vector<pokemon*> p)
    : name(n), trainerid(id), wallet(w), level(l), experience(0) {
    for (pokemon* mon : p) {
        if (mon != nullptr) {
            pokemons[mon->getname()] = mon;
            mon->setowner(trainerid);
        }
    }
}

ostream& operator<<(ostream& out, const trainer& t) {
    out << "Name: " << t.name
        << "\nTrainer ID: " << t.trainerid
        << "\nWallet: " << t.wallet
        << "\nLevel: " << t.level << "\nPokemons:\n";

    for (const auto& p : t.pokemons) {
        if (p.second != nullptr)
            out << *p.second << "\n";
    }

    return out;
}

istream& operator>>(istream& in, trainer& t) {
    in >> t.name >> t.trainerid >> t.wallet >> t.level;
    return in;
}

void trainer::catchPokemon(pokemon& p) {
    if (!p.isowned() && !pokemons.count(p.getname())) {
        p.setowner(trainerid);
        pokemons[p.getname()] = &p;
        cout << "Congrats! You caught " << p.getname() << "\n";
    }
}

bool trainer::releasePokemon(const string& name) {
    if (pokemons.count(name) == 0)
        return false;

    pokemons[name]->setowner(-1);
    pokemons.erase(name);
    return true;
}

pokemon* trainer::getPokemon(const string& name) const {
    if (pokemons.count(name) == 0)
        return nullptr;

    return pokemons.at(name);
}

void trainer::showinv() const {
    cout << *this;
}

bool trainer::trade(trainer& other, const string& mine,
                    const string& theirs) {
    if (pokemons.count(mine) == 0 ||
        other.pokemons.count(theirs) == 0)
        return false;

    pokemon* p1 = pokemons[mine];
    pokemon* p2 = other.pokemons[theirs];

    if (p1 == nullptr || p2 == nullptr)
        return false;

    pokemons.erase(mine);
    other.pokemons.erase(theirs);

    p1->setowner(other.trainerid);
    p2->setowner(trainerid);

    other.pokemons[p1->getname()] = p1;
    pokemons[p2->getname()] = p2;

    return true;
}

void trainer::addItem(const string& item, int quantity) {
    if (quantity > 0)
        inventory[item] += quantity;
}

bool trainer::useItem(const string& item) {
    if (inventory.count(item) == 0 || inventory[item] <= 0)
        return false;

    inventory[item]--;

    if (inventory[item] == 0)
        inventory.erase(item);

    return true;
}

void trainer::showItems() const {
    for (const auto& item : inventory)
        cout << item.first << ": " << item.second << "\n";
}

void trainer::addCoins(int amount) {
    if (amount > 0)
        wallet += amount;
}

bool trainer::spendCoins(int amount) {
    if (amount <= 0 || wallet < amount)
        return false;

    wallet -= amount;
    return true;
}

void trainer::winGym(const string& badge) {
    if (!hasBadge(badge))
        badges.push_back(badge);
}

bool trainer::hasBadge(const string& badge) const {
    return find(badges.begin(), badges.end(), badge) != badges.end();
}

void trainer::showProgress() const {
    cout << "Trainer level: " << level << "\nBadges:\n";

    for (const string& badge : badges)
        cout << badge << "\n";
}

void trainer::gainExperience(int amount) {
    if (amount <= 0)
        return;

    experience += amount;

    while (level > 0 && experience >= level * 100) {
        experience -= level * 100;
        level++;
    }
}

void trainer::levelUp() {
    level++;
}
