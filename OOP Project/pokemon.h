#include<string>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class pokemon{
    private:
    string name;
    string type;
    int level;
    int trainerid;
    int hp;
    int atk;
    vector<string> attacks;
   public:
   friend ostream& operator<<(ostream&,pokemon&);
   friend istream& operator>>(istream&,pokemon&);
   string getname();
   pokemon(string,string= "normal",int=0,int=-1,int=100,int=20,vector<string> = {});
   int dodmg(string,string);
   int takedmg(string,string);
   bool isowned();
   void setowner(int);
   void getownerid();

};
