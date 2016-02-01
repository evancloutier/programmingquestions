// Create an algorithm to determine if a string has all unique characters

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

bool uniqueChars(string str) {
	if (str.length() > 128)
		return false;
	int val;
	bool characterSet[256];
	for (int i = 0; i < str.length(); i++) {
		val = str[i];
		if (characterSet[val]) {
			cout << "The word " << str << " has a duplicate character " << str[i] << endl;
			return false;
		}
		characterSet[val] = true;
	}
	cout << "The word " << str << " has all unique characters" << endl;
	return true;
}

bool uniqueCharsHash(string str) {
	if (str.length() > 128)
		return false;

	unordered_map<char,bool> charMap;

	for (int i = 0; i < str.length(); i++) {
		if(charMap[str[i]] == 0) {
			charMap[str[i]] = 1;
		}
		else {
			cout << "The word " << str << " has a duplicate character " << str[i] << endl;
			return false;
		}
	}
	cout << "The word " << str << " has all unique characters" << endl;
	return true;
}

int main() {
	string str;
	str = "Hello";
	uniqueCharsHash(str);
}