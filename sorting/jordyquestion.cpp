/* Given a sorted array of all non-negative numbers, return the interval 
in which a certain number repeats.

---> i.e. [1, 2, 4, 5, 5, 6] would return 3->5
		   0  1  2  3  4  5 										*/

#include <iostream>
#include <string>

void checkInterval(int array[], int size, int value) {
	// We can use a binary search method
	int start = 0, end = size - 1;
	int mid = (start + end) / 2;

	while (start <= end && array[mid] != value) {
		if (array[mid] < value)
			start = mid + 1;
		else
			end = mid - 1;
		mid = (start + end) / 2;
	}

	// We need to ensure that we have the true first occurrence
	while (array[mid] == array[mid-1])
		mid--;

	// We now have our true first occurrence
	int firstIndex = mid;
	int lastIndex = mid;
	// Track our incrementation using a count
	int count = 1;

	while (array[mid] == array[mid+count]) {
		lastIndex++;
		count++;
	}

	std::cout << "The value of 5 starts at index " << firstIndex << " and ends at index " << lastIndex << std::endl;
}

int main() {
	int myArray[] = {1, 2, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6};
	int size = 7;
	checkInterval(myArray, size, 5);
}