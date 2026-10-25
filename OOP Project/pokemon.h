#include<string>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class pokemon{
    private:
    int pokemonId,
    string name;
    string type;
    int level;
    int trainerid;
    int maxHp;
    int atk;
    vector<string> attacks;
   public:
   friend ostream& operator<<(ostream&,pokemon&);
   friend istream& operator>>(istream&,pokemon&);
   string getname();
   pokemon(string,string= "normal",int=0,int=-1,int=100,int=20,vector<string> = {});
   bool isFainted() const;
   int calculateDamage(const std::string& move) const;
   int attack(pokemon& target, const std::string& move) const;
   int takeDamage(int damage);
   bool isowned();
   void setowner(int);
   void getownerid();

};
