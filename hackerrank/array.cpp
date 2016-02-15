#include <iostream>
#include <cctype>

void reverseArray(int data[], int length) {
	for (int i = length - 1; i >= 0; i--)
		std::cout << data[i] << " ";
}

int main() {
	int length;
	std::cin >> length;
	int myArray[length];

	for (int i = 0; i < length; i++) {
		std::cin >> myArray[i];
	}

	reverseArray(myArray, length);
}