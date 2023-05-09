#ifndef SLIMEMOLD_H
#define SLIMEMOLD_H

#include "Grid.h"

class SlimeMold {
private:
    int posX;
    int posY;

public:
    SlimeMold(int size);
    void setPosition(int row, int col);
    bool move(Grid& grid);
    int getPositionX();
    int getPositionY();
};

#endif
