#include <iostream>
#include <string>
#include <cctype>

void lexMinString(const std::string& str1, const std::string& str2) {
	// Let's make copies of both strings
	std::string aString(str1);
	std::string bString(str2);
	// We'll also need to make string to store the result
	std::string totalString;

	if (aString.empty() || bString.empty())
		return;

	// We also need two incrementors to follow our strings
	int i = 0, j = 0;

	while (i < aString.length() || j < bString.length()) {
		if (aString[i] < bString[j]) {
			totalString += aString[i];
			i++;
			std::cout << "i: " << i << std::endl;
		}
		else if (bString[j] < aString[i]) {
			totalString += bString[j];
			j++;
			std::cout << "j: " << j << std::endl;
		}
		else {
			totalString += aString[i];
			i++;
			std::cout << "i: " << i << std::endl;
		}
	}

	std::cout << totalString << std::endl;
}

int main() {
	std::string testString1 = "BAB";
	std::string testString2 = "BAC";
	lexMinString(testString1, testString2);
}