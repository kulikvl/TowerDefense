#ifndef Tank_hpp
#define Tank_hpp

#include "GameObject.hpp"
#include "MoveableObject.hpp"
#include "DamageableObject.hpp"
#include "Sprite.hpp"
#include "MazeSolver.hpp"
#include "ParticleTankExplosion.cpp"
#include "TimerCounter.hpp"
#include "Player.hpp"
#include "Config.hpp"
#include "Utils.hpp"
#include "TileManager.hpp"
#include "Player.hpp"

/// \brief Class that represents enemy as a tank.
///
/// It is moveble, damageable and has main characteristics of standart game object.
///
class Tank : public GameObject, public MoveableObject, public DamageableObject
{
protected:
    /// Object that tells the road on which the tank is moving.
    const MazeSolver& mazeSolver;
    
    /// Image of the tank
    Sprite sprite;
    
    /// The road on which the tank is moving.
    vector<string> path;
    
    /// Current path of the road on which the tank is moving.
    size_t currentPathTile = 0;
    
    /// Particle inited on Tank destruction.
    ParticleTankExplosion part;
    
    /// Timer used after death to set this object inactive.
    TimerCounter timerAfterDeath;
    
    /// Player object
    Player& player;
    
    /// Sets direction of the tank which is moving.
    void setDirection();
    
    /// Move the tank.
    void move();
    
    /// It's a unique function for child Tank classes representing the specific kind of Tank.
    virtual void selectPath() = 0;
    
    /// Init the tank.
    Tank(const MazeSolver& mazeSolver, const Sprite& sprite, float velocity, int hp, Player& player);
    
    virtual void destroy() override;
    
public:
    virtual void update() override;
    
    virtual void render() override;
    
    /// Get the pointer to the image of this tank.
    Sprite* getSprite();
    
};

#endif /* Tank_hpp */
