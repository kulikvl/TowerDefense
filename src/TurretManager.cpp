#include "TurretManager.hpp"

TurretManager::TurretManager(vector<shared_ptr<Tank> >& tanks, Player& player) :
    tanks(tanks),
    player(player)
{
}

void TurretManager::update()
{
    for (size_t i = 0; i < turrets.size(); ++i)
    {
        turrets[i]->findTargetTank(tanks);
        turrets[i]->update();
        turrets[i]->shoot();
    }
}

void TurretManager::render()
{
    for (size_t i = 0; i < turrets.size(); ++i)
    {
        turrets[i]->render();
    }
}

void TurretManager::installTurret(TurretType type, TileTurret* tile)
{
    if (!tile->hasTurret)
    {
        int cost;
        switch (type) {
            case TurretType::FIREBIRD:
                cost = Config::getInt("firebird_cost", 5);
                break;
            case TurretType::FREEZE:
                cost = Config::getInt("freeze_cost", 5);
                break;
            case TurretType::SMOKY:
                cost = Config::getInt("smoky_cost", 5);
                break;
            default:
                cost = 3;
                break;
        }
        
        if (player.getCoins() < cost)
        {
            Log::warning( string("Not enough coins! " + to_string(player.getCoins()) + " / " + to_string(cost)) );
            return;
        }
        
        tile->hasTurret = true;
        tile->isSelected = false;
        
        switch (type) {
            case TurretType::FIREBIRD:
                turrets.push_back(make_unique<Firebird>(tile->getX(), tile->getY()));
                break;
            case TurretType::FREEZE:
                turrets.push_back(make_unique<Freeze>(tile->getX(), tile->getY()));
                break;
            case TurretType::SMOKY:
                turrets.push_back(make_unique<Smoky>(tile->getX(), tile->getY()));
                break;
        }
        
        player.substractCoins(cost);
        
    }
}
