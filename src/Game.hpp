#ifndef Game_hpp
#define Game_hpp

#include "TileManager.hpp"
#include "TankManager.hpp"
#include "TurretManager.hpp"
#include "ButtonManager.hpp"
#include "TabManager.hpp"
#include "MazeSolver.hpp"
#include "Player.hpp"
#include "Sprite.hpp"
#include "Config.hpp"
#include "Utils.hpp"

using namespace std;

/// \brief Class for managing general game logic a main game loop.
///
/// Class, in which the main game loop is running.
/// It checks for input, updates, clears and renders the screen every frame.
///
class Game
{
public:
    /// Game state.
    enum State
    {
        PLAYING,
        ENDSCREEN
    };
    
private:
    /// Player object.
    Player player;
    
    /// Organise and create tiles.
    TileManager tileManager;
    
    /// Find all paths in the maze (BFS).
    MazeSolver mazeSolver;
    
    /// Organise and create tanks.
    TankManager tankManager;
    
    /// Organise and install turrets.
    TurretManager turretManager;
    
    /// Control buttons.
    ButtonManager buttonManager;

    /// Organise tab menu and buttons.
    TabManager tabManager;
    
    /// Current game state.
    State state;
    
    /// Image of the end screen with the resolution of the game-window
    Sprite endScreenImage;
    
public:
    /// Initializes pretty much everything.
    Game();

    /// Main entry point and game loop.
    ///
    /// This is where it all happens. The game never leaves this
    /// method.
    ///
    /// @note If we leave this method, the game quits, as seen on *main.cpp*.
    void run();

};

#endif /* Game_hpp */
