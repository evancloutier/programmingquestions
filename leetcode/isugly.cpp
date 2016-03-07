#include <iostream>

bool isUgly(int num) {
	if (num < 1)
		return false;

	for (int i = 2; i <= 5; i++) {
		while (num % i == 0)
			num /= i;
	}

	if (num != 1) {
		std::cout << "The number is not ugly" << std::endl;
		return false;
	}
	std::cout << "The number is ugly" << std::endl;
	return true;
}

int main() {
	int number = 14;
	isUgly(number);
}
