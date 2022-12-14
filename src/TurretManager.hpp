#ifndef TurretManager_hpp
#define TurretManager_hpp

#include "Turret.hpp"
#include "Tank.hpp"
#include "Player.hpp"
#include "Firebird.hpp"
#include "Freeze.hpp"
#include "Smoky.hpp"
#include "TileTurret.hpp"
#include "Log.hpp"
#include "Config.hpp"

#include <vector>
#include <memory>

using namespace std;

enum TurretType
{
    FIREBIRD,
    FREEZE,
    SMOKY
};

/// \brief Class for controlling and creating turrets.
class TurretManager
{
private:
    /// All current turrets.
    vector<unique_ptr<Turret> > turrets;
    
    /// All current tanks.
    vector<shared_ptr<Tank> >& tanks;
    
    /// Player object.
    Player& player;
    
public:
    /// Init with getting reference to vector of current tanks.
    TurretManager(vector<shared_ptr<Tank> >& tanks, Player& player);

    void update();
    
    void render();
    
    /// Install turret to the specific tile of the specific type.
    void installTurret(TurretType type, TileTurret* tile);
};

#endif /* TurretManager_hpp */
