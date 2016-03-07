#include <iostream>
#include <algorithm>

/* {12.1, 12.3, 12.2, 13.1, 13.2, 12.6, 12.1, 11.2, 10.5, 11.9} */

int findMaxIndex(float array[], int size, int currentIndex) {
	float max = array[currentIndex];
	int maxIndex = currentIndex;

	for (int i = currentIndex; i < size; i++) {
		if (array[i] > max) {
			max = array[i];
			maxIndex = i;
		}
	}
	return maxIndex;
}

float maxProfit(float array[], int size) {
	// First we need to find our max index
	int index = 0, highestIndex;
	float currentDifference, totalProfit;

	while (index < size) {
		// We can find our max index
		highestIndex = findMaxIndex(array, size, index);
		std::cout << "The highest index is: " << highestIndex << std::endl;

		while (index <= highestIndex) {
			std::cout << "The current index is: " << index << std::endl;
			currentDifference = array[highestIndex] - array[index];
			std::cout << "The current difference is: " << currentDifference << std::endl;

			if (currentDifference > 0) {
				totalProfit += currentDifference;
			}
			index++;
		}
	}
	std::cout << "The total profit is: " << totalProfit << std::endl;
	return totalProfit;
}

int main() {
	float myArray[] = {12.1, 12.3, 12.2, 13.1, 13.2, 12.6, 12.1, 11.2, 10.5, 11.9};
	int size = 10;

	maxProfit(myArray, size);
}
