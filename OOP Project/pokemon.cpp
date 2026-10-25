#include "pokemon.h"

pokemon::pokemon(
    int pokemonId,
    const std::string& name,
    const std::string& type,
    int level,
    int maxHp,
    int atk,
    const std::vector<std::string>& attacks
)
    : pokemonId(pokemonId),
      name(name),
      type(type),
      level(level),
      trainerId(-1),
      hp(maxHp),
      maxHp(maxHp),
      atk(atk),
      attacks(attacks)
{
    if (pokemonId <= 0 || name.empty() ||
        level < 1 || maxHp <= 0 || atk < 0) {
        throw std::invalid_argument("Invalid Pokemon attributes");
    }
}


bool pokemon::isFainted() const {
    return hp == 0;
}

int pokemon::calculateDamage(const std::string& move) const {
    if (isFainted()) {
        return 0;
    }

    // The Pokemon must know the move.
    auto knownMove = std::find(
        attacks.begin(),
        attacks.end(),
        move
    );

    if (knownMove == attacks.end()) {
        return 0;
    }

    // Look up damage without inserting an unknown move.
    auto it = atkdmg.find(move);

    if (it == atkdmg.end()) {
        return 0;
    }

    return it->second;
}

int pokemon::attack(pokemon& target, const std::string& move) const {
    if (&target == this || target.isFainted()) {
        return 0;
    }

    int damage = calculateDamage(move);

    if (damage == 0) {
        return 0;
    }

    return target.takeDamage(damage);
}

int pokemon::takeDamage(int damage) {
    if (damage <= 0 || isFainted()) {
        return 0;
    }

    int actualDamage = std::min(damage, hp);
    hp -= actualDamage;

    return actualDamage;
}