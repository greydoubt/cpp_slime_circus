#ifndef GRID_H
#define GRID_H

#include <vector>

class Grid {
private:
    std::vector<std::vector<int>> matrix;
    int size;

public:
    Grid(int size);
    void markHighValueCell(int row, int col);
    void printGrid();
    bool isCellOccupied(int row, int col);
    bool isHighValueCell(int row, int col);
    void occupyCell(int row, int col);
    int getSize();
};

#endif
