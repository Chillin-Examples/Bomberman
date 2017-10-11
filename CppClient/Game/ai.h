#ifndef AI_H
#define AI_H

#include <random>

#include <ChillinClient>

#include "ks/models.h"
#include "ks/commands.h"


class AI : public koala::chillin::client::RealtimeAI<ks::models::World*>
{
private:
    std::mt19937 randomGenerator;
    std::uniform_int_distribution<> randomDistribution;
    void setupRandom();
    int getRandInt();

public:
    AI(ks::models::World *world);

    void decide();
};

#endif // AI_H
