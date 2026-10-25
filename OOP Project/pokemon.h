#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class pokemon {
private:
    string name;
    string type;
    int level;
    int trainerid;
    int hp;
    int atk;
    vector<string> attacks;

public:
    friend ostream& operator<<(ostream&, const pokemon&);
    friend istream& operator>>(istream&, pokemon&);

    pokemon(string, string = "normal", int = 0, int = -1,
            int = 100, int = 20, vector<string> = {});

    // Getters
    string getname() const;
    string gettype() const;
    int getlevel() const;
    int gethp() const;
    int getatk() const;
    int getownerid() const;
    vector<string> getattacks() const;

    // Battle
    int dodmg(string, string);
    int takedmg(string, string);
    bool isowned() const;

    // Ownership
    void setowner(int);

    // Stats and progression
    void sethp(int);
    void heal(int);
    void gainExperience(int);
    void levelUp();
};

#endif
