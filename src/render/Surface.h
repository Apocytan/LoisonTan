// Generated by dia2code
#ifndef RENDER__SURFACE__H
#define RENDER__SURFACE__H


namespace render {
  class StaticTile;
}

namespace render {

  /// class Surface - 
  class Surface {
    // Operations
  public:
    virtual ~Surface ();
    void clear ();
    void loadTexture (const char* image_file);
    void setSpriteLocation (int id, int x, int y);
    void setSpriteTexture (int i, const StaticTile* tex);
  };

};

#endif
