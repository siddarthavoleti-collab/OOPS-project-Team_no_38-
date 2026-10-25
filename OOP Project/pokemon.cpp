#include "trainer.h"

unordered_map<string, int> atkdmg = {
    {"Tackle", 20}, {"Scratch", 15}, {"Flamethrower", 40},
    {"Water Gun", 25}, {"Razor Leaf", 30}, {"Thunderbolt", 40},
    {"Quick Attack", 20}, {"Vine Whip", 25}, {"Ember", 20},
    {"Bubble Beam", 30}, {"Iron Tail", 35}, {"Bite", 25},
    {"Hyper Beam", 60}, {"Ice Beam", 40}, {"Earthquake", 50},
    {"Shadow Ball", 35}, {"Psychic", 45}, {"Rock Throw", 25},
    {"Dragon Claw", 40}, {"Aerial Ace", 30}
};

// Pokemon definitions
pokemon::pokemon(string n, string t, int l, int tid, int h, int a,
                 vector<string> att)
    : name(n), type(t), level(l), trainerid(tid),
      hp(h), atk(a), attacks(att) {}

ostream& operator<<(ostream& out, const pokemon& p) {
    out << "Name: " << p.name
        << "\nType: " << p.type
        << "\nLevel: " << p.level
        << "\nHP: " << p.hp
        << "\nAttack: " << p.atk
        << "\nAttacks: ";

    for (const string& a : p.attacks)
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

// Getters
string pokemon::getname() const {
    return name;
}

string pokemon::gettype() const {
    return type;
}

int pokemon::getlevel() const {
    return level;
}

int pokemon::gethp() const {
    return hp;
}

int pokemon::getatk() const {
    return atk;
}

int pokemon::getownerid() const {
    return trainerid;
}

vector<string> pokemon::getattacks() const {
    return attacks;
}

// Battle
int pokemon::dodmg(string attack, string target) {
    cout << this->name << " attacked " << target
         << " with " << attack << "\n";

    if (atkdmg.find(attack) != atkdmg.end()) {
        return atkdmg[attack];
    }

    return 0;
}

int pokemon::takedmg(string attack, string attacker) {
    int damage = 0;

    if (atkdmg.find(attack) != atkdmg.end()) {
        damage = atkdmg[attack];
    }

    cout << this->name << " took " << damage
         << " damage from " << attacker
         << "'s " << attack << "!\n";

    this->hp -= damage;

    if (this->hp < 0) {
        this->hp = 0;
    }

    return this->hp;
}

bool pokemon::isowned() const {
    return trainerid != -1;
}

void pokemon::setowner(int id) {
    trainerid = id;
}

void pokemon::sethp(int h) {
    hp = max(0, h);
}

void pokemon::heal(int amount) {
    if (amount > 0)
        hp += amount;
}

void pokemon::gainExperience(int amount) {
    if (amount > 0)
        level += amount / 100;
}

void pokemon::levelUp() {
    level++;
    atk += 2;
    hp += 5;
}


