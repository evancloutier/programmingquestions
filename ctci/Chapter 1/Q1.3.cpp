// Given two strings, write a method to decide if one is a permutation of the other

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

// using namespace std;

bool permutationHash(const std::string& s, const std::string& t) {
	// Create copies of strings
	std::string stringA (s);
	std::string stringB (t);

	// Create hash maps to store elements
	std::unordered_map<char,int> aMap;
	std::unordered_map<char,int> bMap;

	if (stringA.length() != stringB.length()) {
		std::cout << "The two strings are not permutations" << std::endl;
		return false;
	}

	// Set length of string
	int length = stringA.length();

	// Iterate through strings to map elements
	for (int i = 0; i < length; i++) {
		aMap[stringA[i]]++;
		bMap[stringB[i]]++;
	}

	// Compare maps to determine if they are equal
	if (aMap.size() == bMap.size()) {
		for (int i = 0; i < aMap.size(); i++) {
			if (aMap[i] != bMap[i]) {
				std::cout << "The two strings are not permutations" << std::endl;
				return false;
			}
		}
		std::cout << "The two strings are permutations" << std::endl;
		return true;
	}
	return false;
}

int main() {
	std::string string1 = "aaaaabbbbbccccc";
	std::string string2 = "aaaaacccccbbbbb";
	permutationHash(string1, string2);

	return 0;
}


