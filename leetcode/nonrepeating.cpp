// Find first non-repeating character in a string
#include <iostream>
#include <string>
#include <map>

char firstNonRepeating(std::string str) {
	// Use hash map to check occurrences
	std::map<char,int> charMap;
	char firstChar;

	// Ensure string has a length
	if (str.length() == NULL)
		return NULL;
	
	for (int i = 0; i < str.length(); i++) {
		charMap[str[i]]++;
	}

	// Find element that has one occurrence
	for (int i = 0; i < str.length(); i++) {
		if (charMap[str[i]] == 1) {
			firstChar = str[i];
			std::cout << "The first non-repeating character is: " << firstChar << std::endl;
			return firstChar;
		}
	}
	std::cout << "There is no non-repeating character" << std::endl;
	return NULL;
}

int main() {
	std::string myString = "aatttmmmmmmcc";
	firstNonRepeating(myString);
}