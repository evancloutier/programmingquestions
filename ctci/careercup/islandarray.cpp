#include <iostream>
#include <string>

void print2DArray(int array[5][5], int height, int width) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			std::cout << array[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void checkConnections(int array[], int i, int j) {
	std::cout << array[1][1] << std::endl;

	// if (array[i+1][j] == 1) {
	// 	array[i+1][j] = 2;
	// 	checkConnections(array, i+1, j);
	// }
	// if (array[i-1][j] == 1) {
	// 	array[i-1][j] = 2;
	// 	checkConnections(array, i-1, j);
	// }
	// if (array[i][j+1] == 1) {
	// 	array[i][j+1] = 2;
	// 	checkConnections(array, i, j+1);
	// }
	// if (array[i][j-1] == 1) {
	// 	array[i][j-1] = 2;
	// 	checkConnections(array, i, j-1);
	// }
}

void findIslands(int array[5][5], int height, int width) {
	// Variable to access 2D array via pointers
	int (*pointerArray)[5];
	pointerArray = array;
	// Let's make a variable to keep track of our island count
	int islandCount = 0;

	// We can traverse through our array and search for points
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (array[i][j] == 1) {
				checkConnections(pointerArray, i, j);
			}
		}
	}
	std::cout << "The number of islands is: " << islandCount << std::endl;
}

int main() {
	int myArray[5][5] = { };
	myArray[1][1] = 1;
	myArray[2][1] = 1;
	myArray[3][2] = 1;
	myArray[3][3] = 1;
	myArray[3][4] = 1;
	int height = 5, width = 5;
	findIslands(myArray, height, width);
	// print2DArray(myArray, height, width);
}











