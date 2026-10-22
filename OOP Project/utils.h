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
   pokemon(string,string= 'normal',int=0,int=-1,int=100,int=20,vector<string>);
   int dodmg(string,string);
   int takedmg(string,string);
   bool isowned();
   void setowner(int);
   void getownerid();

}


class trainer{
    private:
    string name;
    int trainerid;
    int wallet;
    int level;
     unordered_map<string,pokemon*> pokemons;
     public:
     trainer(string,int=0,int=0,vector<pokemon*>);
     void catchPokemon(Pokemon& p);
     void trade(trainer&);
     void showinv();
}