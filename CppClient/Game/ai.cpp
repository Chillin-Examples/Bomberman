#include "ai.h"

#include <vector>
#include <iostream>

using namespace koala::chillin::client;
using namespace ks::models;
using namespace ks::commands;


AI::AI(World *world): RealtimeAI<World*>(world)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    dis = std::uniform_int_distribution<>(1, 100);
}

void AI::decide()
{
    if (dis(gen) <= 90)
    {
        Bomberman myBomberman = this->world->bombermans()[this->mySide];

        std::vector<EDir> validDirections;
        if (this->world->board()[myBomberman.y() - 1][myBomberman.x()].type() == ECellType::Empty) {
            validDirections.push_back(EDir::Top);
        }
        if (this->world->board()[myBomberman.y()][myBomberman.x() + 1].type() == ECellType::Empty) {
            validDirections.push_back(EDir::Right);
        }
        if (this->world->board()[myBomberman.y() + 1][myBomberman.x()].type() == ECellType::Empty) {
            validDirections.push_back(EDir::Bottom);
        }
        if (this->world->board()[myBomberman.y()][myBomberman.x() - 1].type() == ECellType::Empty) {
            validDirections.push_back(EDir::Left);
        }

        if (validDirections.size() >= 1)
        {
            std::cout << "Move" << std::endl;
            ks::commands::Move cmd;
            cmd.direction(validDirections[dis(gen) % validDirections.size()]);
            sendCommand(&cmd);
        }
    }
    else
    {
        std::cout << "Bomb" << std::endl;
        ks::commands::Bomb cmd;
        sendCommand(&cmd);
    }
}
