#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class pokemon {
private:                       // Encapsulation: data is hidden
    string name;
    string type;
    int level;
    int trainerid;             // -1 means no owner
    int hp;
    int atk;
    vector<string> attacks;
public:
    // Operator overloading (friends can read private data)
    friend ostream& operator<<(ostream&, const pokemon&);
    friend istream& operator>>(istream&, pokemon&);
    // Constructor with default arguments
    pokemon(string, string = "normal", int = 1, int = -1,
            int = 100, int = 20, vector<string> = {});
    // Getters
    string getname() const;
    string gettype() const;
    int getlevel() const;
    int gethp() const;
    int getatk() const;
    int getownerid() const;
    // Battle
    int dodmg(string attack, string target);
    void takedmg(int damage);
    // Ownership
    bool isowned() const;
    void setowner(int);
    // HP
    void sethp(int);
    void heal(int);
};
#endif
