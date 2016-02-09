#include <iostream>
#include <string>
#include <algorithm>

void alternateDelete(const std::string& str) {
	// First we can create characters to compare
	char currentChar;
	char nextChar;
	// We can also declare a variable to keep track of deletions
	int deletions = 0;

	// Now we can iterate through our string to find number of deletions
	for (int i = 0; i < str.length(); i++) {
		currentChar = str[i];
		nextChar = str[i+1];

		if (currentChar == nextChar) {
			deletions++;
		}
	}
	std::cout << "The number of required deletions is: " << deletions << std::endl;
}

int main() {
	std::string testString;
	getline(std::cin, testString);
	alternateDelete(testString);

	return 0;
}