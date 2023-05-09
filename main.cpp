#include "Grid.h"
#include "SlimeMold.h"
#include <iostream>
#include <ctime>

int main() {
    srand(time(NULL));

    const int SIZE = 128;
    const int HIGH_VALUE_CELLS = 5;

    Grid grid(SIZE);
    SlimeMold slimeMold(SIZE);

    // Mark random high-value cells
    for (int i = 0; i < HIGH_VALUE_CELLS; i++) {
        int row = rand() % SIZE;
        int col = rand() % SIZE;
        grid.markHighValueCell(row, col);
    }

    // Start simulation from the center
    slimeMold.setPosition(SIZE / 2, SIZE / 2);
    grid.occupyCell(SIZE / 2, SIZE / 2);

int steps = 0;
int highValueCellsReached = 0;

while (highValueCellsReached < HIGH_VALUE_CELLS) {
    steps++;
    bool moved = slimeMold.move(grid);
    
    // Check if the slime mold entered a high-value cell
    int posX = slimeMold.getPositionX();
    int posY = slimeMold.getPositionY();
    if (grid.isHighValueCell(posX, posY)) {
        grid.occupyCell(posX, posY);
        highValueCellsReached++;
    }

    if (!moved)
        break;
}

std::cout << "Simulation completed in " << steps << " steps." << std::endl;

return 0;
}