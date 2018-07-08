#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdio.h>
#include <stdlib.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void printGrid(int grid[3][3]);
void toppleGrid(int grid[3][3]);
int checkGrid(int grid[3][3]);

#endif
