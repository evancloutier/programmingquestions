#include <iostream>
#include <string>

void staircase(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n-1; j++)
			std::cout << " ";
		for (int k = 1; k <= i; k++)
			std::cout << "#";
		std::cout << std::endl;
	}
}

int main() {
	int myNumber = 4;
	staircase(myNumber);
}