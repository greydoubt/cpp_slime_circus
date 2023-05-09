#include "Grid.h"
#include <iostream>

Grid::Grid(int size) {
    this->size = size;
    matrix.resize(size, std::vector<int>(size, 0));
}

void Grid::markHighValueCell(int row, int col) {
    matrix[row][col] = 1;
}

void Grid::printGrid() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool Grid::isCellOccupied(int row, int col) {
    return matrix[row][col] == 2;
}

bool Grid::isHighValueCell(int row, int col) {
    return matrix[row][col] == 1;
}

void Grid::occupyCell(int row, int col) {
    matrix[row][col] = 2;
}

int Grid::getSize() {
    return size;
}
``
