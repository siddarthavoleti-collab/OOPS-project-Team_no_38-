#include "trainer.h"
#include "environment.h"
#include <iostream>
using namespace std;

int main() {
    Environment game;

    pokemon* pikachu = game.addPokemon(
        "Pikachu", "electric", 5, 90, 25,
        {"Quick Attack", "Thunderbolt"}
    );

    pokemon* charmander = game.addPokemon(
        "Charmander", "fire", 5, 100, 20,
        {"Scratch", "Ember"}
    );

    trainer* ash = game.addTrainer("Ash", 500, 1);
    trainer* gary = game.addTrainer("Gary", 300, 1);

    // 1. Catch Pokemon
    cout << "\n========== CATCH TEST ==========\n";

    cout << "Before catching:\n";
    cout << "Pikachu owned: " << pikachu->isowned() << "\n";
    cout << "Charmander owned: " << charmander->isowned() << "\n";

    ash->catchPokemon(*pikachu);
    gary->catchPokemon(*charmander);

    cout << "\nAfter catching:\n";
    cout << "Pikachu owned: " << pikachu->isowned() << "\n";
    cout << "Charmander owned: " << charmander->isowned() << "\n";

    cout << "\nAsh's Pokemon:\n";
    cout << *ash;

    cout << "\nGary's Pokemon:\n";
    cout << *gary;

    // 2. Pokemon output operator and getters
    cout << "\n========== POKEMON DETAILS ==========\n";
    cout << *pikachu;
    cout << "Name using getter: " << pikachu->getname() << "\n";
    cout << "Type using getter: " << pikachu->gettype() << "\n";
    cout << "Level using getter: " << pikachu->getlevel() << "\n";
    cout << "Attack using getter: " << pikachu->getatk() << "\n";

    // 3. Damage
    cout << "\n========== DAMAGE TEST ==========\n";

    cout << "Charmander HP before damage: "
         << charmander->gethp() << "\n";

    int damage = pikachu->dodmg("Thunderbolt", "Charmander");
    cout << "Damage returned: " << damage << "\n";

    charmander->takedmg("Thunderbolt", "Pikachu");

    cout << "Charmander HP after damage: "
         << charmander->gethp() << "\n";

    // 4. Healing
    cout << "\n========== HEALING TEST ==========\n";

    cout << "HP before healing: " << charmander->gethp() << "\n";
    charmander->heal(10);
    cout << "HP after healing by 10: " << charmander->gethp() << "\n";

    // 5. sethp
    cout << "\n========== SET HP TEST ==========\n";

    cout << "HP before sethp: " << charmander->gethp() << "\n";
    charmander->sethp(80);
    cout << "HP after sethp(80): " << charmander->gethp() << "\n";

    // 6. Trading
    cout << "\n========== TRADING TEST ==========\n";

    cout << "Before trade:\n";
    cout << "Ash owns Pikachu: "
         << (ash->getPokemon("Pikachu") != nullptr) << "\n";
    cout << "Ash owns Charmander: "
         << (ash->getPokemon("Charmander") != nullptr) << "\n";
    cout << "Gary owns Pikachu: "
         << (gary->getPokemon("Pikachu") != nullptr) << "\n";
    cout << "Gary owns Charmander: "
         << (gary->getPokemon("Charmander") != nullptr) << "\n";

    cout << "\nTrading Pikachu from Ash to Gary,\n";
    cout << "and Charmander from Gary to Ash.\n";

    bool traded = ash->trade(*gary, "Pikachu", "Charmander");
    cout << "Trade successful: " << (traded ? "Yes" : "No") << "\n";

    cout << "\nAfter trade:\n";
    cout << "Ash owns Pikachu: "
         << (ash->getPokemon("Pikachu") != nullptr) << "\n";
    cout << "Ash owns Charmander: "
         << (ash->getPokemon("Charmander") != nullptr) << "\n";
    cout << "Gary owns Pikachu: "
         << (gary->getPokemon("Pikachu") != nullptr) << "\n";
    cout << "Gary owns Charmander: "
         << (gary->getPokemon("Charmander") != nullptr) << "\n";

    cout << "\nPikachu owner ID: " << pikachu->getownerid() << "\n";
    cout << "Charmander owner ID: " << charmander->getownerid() << "\n";

    // 7. Inventory
    cout << "\n========== INVENTORY TEST ==========\n";

    cout << "Adding 2 Potions to Ash...\n";
    ash->addItem("Potion", 2);
    cout << "Ash's inventory after adding:\n";
    ash->showItems();

    cout << "\nUsing 1 Potion...\n";
    bool used = ash->useItem("Potion");
    cout << "Potion used successfully: " << (used ? "Yes" : "No") << "\n";
    cout << "Ash's inventory after using:\n";
    ash->showItems();

    // 8. Wallet
    cout << "\n========== WALLET TEST ==========\n";

    cout << "Wallet before spending: 500\n";
    bool spent = ash->spendCoins(50);
    cout << "Spend 50 coins successful: " << (spent ? "Yes" : "No") << "\n";

    ash->addCoins(100);
    cout << "Added 100 coins.\n";
    cout << "Ash's wallet after spending and adding coins: "
         << "500 - 50 + 100 = 550\n";

    // 9. Badges and progression
    cout << "\n========== PROGRESSION TEST ==========\n";

    cout << "Adding Thunder Badge...\n";
    ash->winGym("Thunder Badge");

    cout << "Has Thunder Badge: "
         << (ash->hasBadge("Thunder Badge") ? "Yes" : "No") << "\n";
    cout << "Has Water Badge: "
         << (ash->hasBadge("Water Badge") ? "Yes" : "No") << "\n";

    cout << "\nGaining 200 experience...\n";
    ash->gainExperience(200);
    ash->showProgress();

    // 10. Release Pokemon
    cout << "\n========== RELEASE TEST ==========\n";

    cout << "Before release, Ash owns Charmander: "
         << (ash->getPokemon("Charmander") != nullptr) << "\n";

    bool released = ash->releasePokemon("Charmander");
    cout << "Release successful: " << (released ? "Yes" : "No") << "\n";

    cout << "After release, Ash owns Charmander: "
         << (ash->getPokemon("Charmander") != nullptr) << "\n";
    cout << "Charmander owned by a trainer: "
         << charmander->isowned() << "\n";

    cout << "\n========== ALL TESTS COMPLETED ==========\n";

    return 0;
}
