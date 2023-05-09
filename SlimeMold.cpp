SlimeMold#include "SlimeMold.h"
#include <cstdlib>
#include <ctime>

SlimeMold::SlimeMold(int size) {
    srand(time(NULL));
    posX = size / 2;
    posY = size / 2;
}

void SlimeMold::setPosition(int row, int col) {
    posX = row;
    posY = col;
}

bool SlimeMold::move(Grid& grid) {
    // Check adjacent cells and select a valid move
    int size = grid.getSize();
    int moves[4][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };

    for (int i = 0; i < 4; i++) {
        int newRow = posX + moves[i][0];
        int newCol = posY + moves[i][1];

        if (newRow >= 0 && newRow < size && newCol >= 0 && newCol < size &&
            !grid.isCellOccupied(newRow, newCol) && !grid.isHighValueCell(newRow, newCol)) {
            // Move to the new cell
            grid.occupyCell(newRow, newCol);
            posX = newRow;
            posY = newCol;
            return true;
        }
    }

    return false; // No valid moves available
}

int SlimeMold::getPositionX() {
    return posX;
}

int SlimeMold::getPositionY() {
    return posY;
}
