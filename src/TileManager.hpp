#ifndef TileManager_hpp
#define TileManager_hpp

#include "Tile.hpp"
#include "TileTurret.hpp"
#include "Log.hpp"

#include <memory>
#include <vector>

using namespace std;

/// @brief Class for managing and filling in tiles in the game.
///
/// Can read map from the file and then generate and draw tiles to the game screen.
///
class TileManager
{
public:
    static const int MENU_TILES   = 8;
    static const int ROW_TILES    = 8;
    static const int GAME_TILES   = 64;
    static const int TOTAL_TILES  = 72;
    static const int TILE_SPRITES = 7;
    
private:
    /// All the tiles on the screen.
    shared_ptr<Tile> tiles[TOTAL_TILES];
    
    /// Fill the tiles to the screen.
    void fill();
    
    /// Read a map from the file.
    vector<int> readMap(string inFileName);
    
public:
    /// Init tiles.
    TileManager();
    
    /// Updates all tiles.
    void update();
    
    /// Renders all tiles.
    void render();
    
    /// Query all tiles of the specified types.
    vector<shared_ptr<Tile> > queryTilesOfTypes(const vector<Tile::Type>& types);
    
};

#endif /* TileManager_hpp */
