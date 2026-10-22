#include "utils.h"

unordered_map<string, int> atkdmg = {
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

pokemon::pokemon(string n, string t, int l, int tid, int h, int a, vector<string> att){
    name = n;
    type = t;
    level = l;
    trainerid = tid;
    hp = h;
    atk = a;
    attacks = att;
}

int pokemon::dodmg(string atkname, string pokemonname) {
    cout<<"you attacked "<<pokemonname<<"with "<<atkname;
    return atkdmg[atkname];
}

int pokemon::takedmg(string atkname, string pokemonname) {
    cout<<pokemonname<<" attacked you with "<<atkname;
    hp -= atkdmg[atkname];
    if (hp < 0) hp = 0;
    return hp;
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


trainer::trainer(string n, int id, int w,int l, vector<pokemon*> p){
    name = n;
    id = id;
    wallet = w;
    level = l;
    pokemons = p;
}

void trainer::catchPokemon(pokemon& p) {
    if (!p.isowned()) {
        p.setowner(trainerid);
        pokemons[p.name] = p;
        cout<<"Congrats you just caught a "<<p.name;
    }
}

void trainer::trade(trainer& other, string pname) {
    if (pokemons.find(pname) != pokemons.end()) {
        pokemon* p = pokemons[pname];

        p->setowner(other.trainerid);
        other.pokemons[pname] = p;
        pokemons.erase(pname);
    }
}

void trainer::showinv() {  //not yet added in header file having confusion how to do
    for (string item : inventory)
        cout << item << endl;

    cout << "Pokemons: " << pokemons.size() << endl;
}