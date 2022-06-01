#ifndef Player_h
#define Player_h

/// @brief Small static class container for 'player' statistics
class Player
{
public:
    /// Max coins = 17.
    /// @note Define in 'Game' modul.
    static int coins;
    
    /// Max (inital) hp = 3.
    /// @note Always is fixed amount.
    static int hp;
};

#endif /* Player_h */
