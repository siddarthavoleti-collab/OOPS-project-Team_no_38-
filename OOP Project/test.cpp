
#include "trainer.h"
#include "environment.h"
#include <iostream>
using namespace std;

int main() {
    Environment game;

    // Create two characters and two players.
    pokemon* pika = game.addPokemon("Pikachu", "electric", 5, 90, 25,
                                    {"Quick Attack", "Thunderbolt"});
    pokemon* charmander = game.addPokemon("Charmander", "fire", 5, 100, 20,
                                          {"Scratch", "Ember"});

    trainer* ash = game.addTrainer("Ash", 500);
    trainer* gary = game.addTrainer("Gary", 300);

    cout << "=== TWO-PLAYER BATTLE ===\n";
    cout << "Ash and Gary will take turns attacking.\n";

    // Each player receives one character.
    ash->catchPokemon(*pika);
    gary->catchPokemon(*charmander);

    cout << "\nOOP concept: Objects store their own data.\n";
    cout << "Pikachu's starting HP: " << pika->gethp() << "\n";
    cout << "Charmander's starting HP: " << charmander->gethp() << "\n";

    int turn = 1;

    while (pika->gethp() > 0 && charmander->gethp() > 0) {
        bool ashTurn = (turn % 2 == 1);
        pokemon* attacker = ashTurn ? pika : charmander;
        pokemon* defender = ashTurn ? charmander : pika;

        cout << "\nTurn " << turn << ": "
             << (ashTurn ? "Ash" : "Gary") << "\n";

        cout << "Choose an attack:\n";
        cout << "1. " << (ashTurn ? "Quick Attack" : "Scratch") << "\n";
        cout << "2. " << (ashTurn ? "Thunderbolt" : "Ember") << "\n";
        cout << "Enter 1 or 2: ";

        int choice;
        cout << "Enter 1 or 2: ";
        cin>>choice;
        if(choice>2||choice<1){
            cout<<"enter valid choice between 1 or 2";
            continue;
        }

        string move;
        if (ashTurn)
            move = (choice == 1) ? "Quick Attack" : "Thunderbolt";
        else
            move = (choice == 1) ? "Scratch" : "Ember";

        // Calculate damage, then update the opponent's HP.
        int damage = attacker->dodmg(move, defender->getname());
        defender->takedmg(damage);

        cout << "Damage dealt: " << damage << "\n";
        cout << "Pikachu HP: " << pika->gethp() << "\n";
        cout << "Charmander HP: " << charmander->gethp() << "\n";

        cout << "OOP concept: Member functions perform actions on objects.\n";
        ++turn;
    }

    cout << "\n=== BATTLE RESULT ===\n";
    cout << (pika->gethp() > 0 ? "Ash wins!\n" : "Gary wins!\n");

    // Demonstrate healing.
    cout << "\n=== HEALING ===\n";
    cout << "Pikachu HP before healing: " << pika->gethp() << "\n";
    pika->heal(10);
    cout << "Pikachu HP after healing: " << pika->gethp() << "\n";

    // Demonstrate trading.
    cout << "\n=== TRADING ===\n";
    cout << "Trade Pikachu for Charmander? (1 = yes, 0 = no): ";
    int tradeChoice;
    cin >> tradeChoice;

    if (tradeChoice == 1) {
        bool success = ash->trade(*gary, "Pikachu", "Charmander");
        cout << "Trade successful: " << (success ? "Yes" : "No") << "\n";
        cout << "Ash now owns Charmander: "
             << (ash->getPokemon("Charmander") != nullptr) << "\n";
        cout << "OOP concept: Objects interact through public methods.\n";
    }

    // Demonstrate overloaded output and other trainer methods.
    cout << "\n=== PLAYER INFORMATION ===\n";
    cout << *ash;

    ash->addItem("Potion");
    cout << "\nAsh's inventory:\n";
    ash->showItems();

    ash->winGym("Thunder Badge");
    ash->gainExperience(200);
    cout << "\nAsh's progress:\n";
    ash->showProgress();

    cout << "\nGame finished.\n";
    return 0;
}

