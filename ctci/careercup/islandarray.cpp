#include <iostream>
#include <string>

void print2DArray(int array[][5], int height, int width) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			std::cout << array[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void findIslands(int array[][5], int height, int width) {
	// Let's make a variable to keep track of our island count
	int islandCount = 0;

	// We can traverse through our array and search for points
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (array[i][j] == 1) {
				array[i][j] = 2; // mark as visited
				if (array[i+1][j] == 1) {
					array[i+1][j] = 2; // mark as visited
				}
				if (array[i-1][j] == 1) {
					array[i-1][j] = 2; // mark as visited
				}
				if (array[i][j+1] == 1) {
					array[i][j+1] = 2; // mark as visited
				}
				if (array[i][j-1] == 1) {
					array[i][j-1] = 2; // mark as visited
				}
				islandCount++;
			}
			else if (array[i][j] == 2) {
				continue; // already visited
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
	int height = 5, width = 5;
	findIslands(myArray, height, width);
	print2DArray(myArray, height, width);
}











