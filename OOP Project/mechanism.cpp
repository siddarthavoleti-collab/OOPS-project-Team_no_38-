#include "trainer.h"
#include "pokemon.h"
const std::unordered_map<std::string, int> pokemon::atkdmg = {
    {"Tackle", 20},
    {"Scratch", 15},
    {"Flamethrower", 40},
    {"Water Gun", 25},
    {"Razor Leaf", 30},
    {"Thunderbolt", 40},
    {"Quick Attack", 20},
    {"Vine Whip", 25},
    {"Ember", 20},
    {"Bubble Beam", 30},
    {"Iron Tail", 35},
    {"Bite", 25},
    {"Hyper Beam", 60},
    {"Ice Beam", 40},
    {"Earthquake", 50},
    {"Shadow Ball", 35},
    {"Psychic", 45},
    {"Rock Throw", 25},
    {"Dragon Claw", 40},
    {"Aerial Ace", 30}
};



ostream& operator<<(ostream& out, pokemon& p) {
    out << "Name: " << p.name
        << "\nType: " << p.type
        << "\nLevel: " << p.level
        << "\nHP: " << p.hp
        << "\nAttack: " << p.atk
        << "\nAttacks: ";

    for (string a : p.attacks)
        out << a << " ";

    return out;
}

istream& operator>>(istream& in, pokemon& p) {
    in >> p.name >> p.type >> p.level >> p.hp >> p.atk;

    int n;
    in >> n;
    p.attacks.clear();

    for (int i = 0; i < n; i++) {
        string attack;
        in >> attack;
        p.attacks.push_back(attack);
    }

    return in;
}





string pokemon::
 getname() {
    return name;
}


bool pokemon::isowned() {
    return trainerid != -1;
}

void pokemon::setowner(int id) {
    trainerid = id;
}

void pokemon::getownerid() {
    cout << trainerid << endl;
}



//trainer class defenitions 
ostream& operator<<(ostream& out, trainer& t) {
    out << "Name: " << t.name
        << "\nTrainer ID: " << t.trainerid
        << "\nWallet: " << t.wallet
        << "\nLevel: " << t.level
        << "\nPokemons:\n";

    for (auto p : t.pokemons) {
        out << *(p.second) << "\n";
    }

    return out;
}

istream& operator>>(istream& in, trainer& t) {
    in >> t.name >> t.trainerid >> t.wallet >> t.level;
    return in;
}




void trainer::catchPokemon(pokemon& p) {
    if (!p.isowned()) {
        p.setowner(trainerid);
        pokemons[p.getname()] = &p;
        cout<<"Congrats you just caught a "<<p.getname();
    }
}

void trainer::trade(trainer& other, string recieving, string pname) {
    if (pokemons.find(pname) != pokemons.end() &&
        other.pokemons.find(recieving) != other.pokemons.end()) {
        pokemon* p = pokemons[pname];

        p->setowner(other.trainerid);
        other.pokemons[pname] = p;
        pokemons.erase(pname);
    }

    if (other.pokemons.find(pname) != other.pokemons.end() &&
        pokemons.find(recieving) != pokemons.end()) {
        pokemon* p = other.pokemons[recieving];

        p->setowner(trainerid);
        pokemons[recieving] = p;
        other.pokemons.erase(recieving);
    }
}
