// Determine if a string is a pangram (every letter at least once)

#include <iostream>
#include <cctype>
#include <unordered_map>
#include <string>

bool pangramHash(const std::string& str) {
	// Creating a copy of our string
	std::string s = str;

	// Transforming our string to lowercase
	std::transform(s.begin(), s.end(), s.begin(), ::tolower);

	// Let's create a hash map to store our data
	std::unordered_map<char,bool> pangramMap;

	// We can traverse through our string and map the characters
	for (int i = 0; i < s.length(); i++) {
		pangramMap[s[i]] = 1;
	}

	for (char c = 'a'; c <= 'z'; c++) {
		if (pangramMap[c] == 0) {
			std::cout << "The string provided is not a pangram" << std::endl;
			return false;
		}
	}
	std::cout << "The string provided is a pangram" << std::endl;
	return true;
}

int main() {
	std::string str;
	getline(std::cin, str);
	pangramHash(str);

	return 0;
}




