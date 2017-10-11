#include "ai.h"

#include <vector>
#include <iostream>

using namespace std;
using namespace koala::chillin::client;
using namespace ks::models;
using namespace ks::commands;


AI::AI(World *world): RealtimeAI<World*>(world)
{
    setupRandom();
}

void AI::decide()
{
    if (getRandInt() <= 90)
    {
        Bomberman myBomberman = world->bombermans()[mySide];
        std::vector<EDir> validDirections;

        if (world->board()[myBomberman.y() - 1][myBomberman.x()].type() == ECellType::Empty)
            validDirections.push_back(EDir::Top);

        if (world->board()[myBomberman.y()][myBomberman.x() + 1].type() == ECellType::Empty)
            validDirections.push_back(EDir::Right);

        if (world->board()[myBomberman.y() + 1][myBomberman.x()].type() == ECellType::Empty)
            validDirections.push_back(EDir::Bottom);

        if (world->board()[myBomberman.y()][myBomberman.x() - 1].type() == ECellType::Empty)
            validDirections.push_back(EDir::Left);

        if (validDirections.size() >= 1)
        {
            cout << "Move" << endl;
            ks::commands::Move cmd;
            cmd.direction(validDirections[getRandInt() % validDirections.size()]);
            sendCommand(&cmd);
        }
    }
    else
    {
        cout << "Bomb" << endl;
        ks::commands::Bomb cmd;
        sendCommand(&cmd);
    }
}

void AI::setupRandom()
{
    random_device rd;
    randomGenerator = mt19937(rd());
    randomDistribution = uniform_int_distribution<>(1, 100);
}

int AI::getRandInt()
{
    return randomDistribution(randomGenerator);
}
