#ifndef RESOLVER_H
#define RESOLVER_H

int resolve(int x, int y, int grid[9][9]);
int validInLine(int x, int y, int grid[9][9], int value);
int validInColumn(int x, int y, int grid[9][9], int value);
int validInBlock(int x, int y, int grid[9][9], int value);
int getXBlock(int x);
int getYBlock(int y);

#endif