#include <iostream>
#include <vector>

long sumOfIntegers(std::vector<int> arr) {
	int sum = 0;

	for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); ++it) {
		sum += *it;
	}

	return sum;
}

int main() {
	int n;
	std::cin >> n;
	std::vector<int> myVector(n);
	int vectorVal;

	for (int i = 0; i < n; i++) {
		std::cin >> vectorVal;
		myVector.push_back(vectorVal);
	}
	
	std::cout << sumOfIntegers(myVector) << std::endl;
}