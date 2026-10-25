#include "trainer.h"

trainer::trainer(const std::string& name, int trainerId,
                 int wallet, int level)
    : name(name),
      trainerId(trainerId),
      wallet(wallet),
      level(level) {
}

int trainer::getId() const {
    return trainerId;
}

const std::string& trainer::getName() const {
    return name;
}