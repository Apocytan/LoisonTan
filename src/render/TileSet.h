// Generated by dia2code
#ifndef RENDER__TILESET__H
#define RENDER__TILESET__H


namespace render {
  class StaticTile;
  class Tile;
}

namespace render {

  /// class TileSet - 
  class TileSet {
    // Operations
  public:
    virtual ~TiletSet ();
    int getCellWidth () const;
    int getCellHeight (const char* image_file) const;
    const char* getImageFile () const;
    void getElementTile (int i, const StaticTile* tex);
    const Tile* getCharTile (char c) const;
  };

};

#endif
