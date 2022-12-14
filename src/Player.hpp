#ifndef Player_h
#define Player_h

#include "DamageableObject.hpp"

/// @brief Class, which represents player and it's game data.
class Player : public DamageableObject
{
private:
    /// Player's coins.
    int coins;
    
public:
    /// Init.
    Player(int initialHp, int initialCoins);
    
    void addCoins(int value);
    
    void substractCoins(int value);
    
    int getCoins() const;
    
    virtual void destroy() override;
    
};

#endif /* Player_h */
