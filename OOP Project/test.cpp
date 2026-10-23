#include "trainer.h"
int main() {
    pokemon p1("Pikachu"), p2("Charmander"), p3("Squirtle");

    // Test 1: Input and output
    cout << "Enter Pokemon: name type level HP attack number_of_attacks attacks...\n";
    cin >> p1;
    cout << "\n--- Pokemon Details ---\n" << p1 << "\n\n";

    // Test 2: Create trainers
    trainer t1("Ash", 1, 500, 5);
    trainer t2("Misty", 2, 300, 3);

    // Test 3: Catch Pokemon
    cout << "--- Catch Tests ---\n";
    t1.catchPokemon(p2);
    t2.catchPokemon(p3);

    // Test 4: Check ownership
    cout << "\nCharmander owned: " << p2.isowned() << endl;
    cout << "Pikachu owned: " << p1.isowned() << endl;

    // Test 5: Attack and damage
    cout << "\n--- Battle Test ---\n";
    cout << "Damage: " << p1.dodmg("Thunderbolt", "Squirtle") << endl;
    cout << "Squirtle HP after damage: "
         << p3.takedmg("Thunderbolt", "Pikachu") << endl;

    // Test 6: Display trainers
    cout << "\n--- Trainer Tests ---\n";
    cout << t1 << endl;
    cout << t2 << endl;

    // Test 7: Trade Pokemon
    cout << "\n--- Trade Test ---\n";
    t1.trade(t2, "Squirtle", "Charmander");

    return 0;
}
