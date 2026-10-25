#include "pokemon.h"

pokemon::pokemon(string n, string t, int l, int tid, int h, int a,
                 vector<string> att) {
    this->name = n.empty() ? "Unknown" : n;
    this->type = t.empty() ? "normal" : t;
    this->level = (l < 0) ? 0 : l;
    this->trainerid = (tid < -1) ? -1 : tid;
    this->hp = (h < 0) ? 0 : h;
    this->atk = (a < 0) ? 0 : a;
    this->attacks = att;
}

ostream& operator<<(ostream& out, const pokemon& p) {
    out << "Name: " << p.name << ", Type: " << p.type
        << ", Level: " << p.level << ", HP: " << p.hp
        << ", Attack: " << p.atk << ", Attacks:";
    for (int i = 0; i < p.attacks.size(); i++)
        out << " " << p.attacks[i];
    return out;
}

// Input format: name type level hp atk
istream& operator>>(istream& in, pokemon& p) {
    string n, t;
    int l, h, a;
    in >> n >> t >> l >> h >> a;
        p.name = n;
        p.type = t;
        p.level = l;
        p.hp = h;
        p.atk = a;
    return in;
}

string pokemon::getname() const {
    return this->name;
}

string pokemon::gettype() const {
    return this->type;
}

int pokemon::getlevel() const {
    return this->level;
}

int pokemon::gethp() const {
    return this->hp;
}

int pokemon::getatk() const {
    return this->atk;
}

int pokemon::getownerid() const {
    return this->trainerid;
}

int pokemon::dodmg(string attack, string target) {
    if (attack.empty() || target.empty())
        return 0;
    bool found = false;
    for (int i = 0; i < this->attacks.size(); i++) {
        if (this->attacks[i] == attack) {
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Invalid attack: " << attack << "\n";
        return 0;
    }
    cout << this->name << " used " << attack
         << " on " << target << "\n";
    return this->atk;
}

void pokemon::takedmg(int damage) {
    if (damage <= 0)
        return;
    this->hp -= damage;
    if (this->hp < 0)
        this->hp = 0;
}

bool pokemon::isowned() const {
    return this->trainerid != -1;
}

void pokemon::setowner(int id) {
    if (id >= -1)
        this->trainerid = id;
}

void pokemon::sethp(int h) {
    if (h < 0)
        h = 0;
    this->hp = h;
}

void pokemon::heal(int amount) {
    if (amount > 0)
        this->hp += amount;
}
