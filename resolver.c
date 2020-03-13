#include "resolver.h"

int resolve(int x, int y, int grid[9][9]) {
	if (x == 9) return 1;
	if (y == 9) return resolve(x+1, 0, grid);
	if (grid[x][y] != 0) return resolve(x, y+1, grid);

	for (int i = 1; i < 10; i++) {
		if (validInLine(x, y, grid, i) && validInColumn(x, y, grid, i) && validInBlock(x, y, grid, i)) {
			grid[x][y] = i;
			if (resolve(x, y+1, grid) != 1)
				grid[x][y] = 0;
			else
				return 1;
		}
	}

	return 0;
}

int validInLine(int x, int y, int grid[9][9], int value) {
	for (int i = 0; i < 9; i++) {
		if (y == i) continue;

		if (grid[x][i] == value) return 0;
	}
	
	return 1;
}

int validInColumn(int x, int y, int grid[9][9], int value) {
	for (int i = 0; i < 9; i++) {
		if (x == i) continue;

		if (grid[i][y] == value) return 0;
	}
	
	return 1;
}

int validInBlock(int x, int y, int grid[9][9], int value) {
	int xBlock = getXBlock(x);
	int yBlock = getYBlock(y);

	for (int i = xBlock; i < xBlock+3; i++) {
		for (int j = yBlock; j < yBlock+3; j++) {
			if (i == x && j == y) continue;

			if (grid[i][j] == value) return 0;
		}
	}

	return 1;
}

int getXBlock(int x) {
	if (x < 3) return 0;
	if (x < 6) return 3;
	
	return 6;
}

int getYBlock(int y) {
	return getXBlock(y);
}