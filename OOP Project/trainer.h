#include "pokemon.h"
class trainer{
    private:
    string name;
    int trainerid;
    int wallet;
    int level;
     unordered_map<string,pokemon*> pokemons;
     public:
      friend ostream& operator<<(ostream&,trainer&);
     friend istream& operator>>(istream&,trainer&);
     trainer(string,int=0,int=0,int = 0,vector<pokemon*> = {});
     void catchPokemon(pokemon& p);
     void trade(trainer&,string,string);
     void showinv();
};
