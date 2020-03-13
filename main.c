#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "resolver.h"

int main(int argc, char *argv[]) {
	if (argc != 81+1) {
		printf("Invalid arguments, please enter sudoku values only from 0 to 9\n");
		printf("%d\n", argc-1);
		abort();
	}

	int grid[9][9];
	size_t argvIndex = 1;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			grid[i][j] = atoi(argv[argvIndex]);
			argvIndex++;
		}
	}

	if (!resolve(0, 0, grid)) {
		printf("Unable to resolve\n");
		return 0;
	}

	printSudoku(grid, stdout);

	return 0;
}

void printSudoku(int grid[9][9], FILE * output) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			fprintf(output, "%d ", grid[i][j]);
		}

		fprintf(output, "\n");
	}
}

