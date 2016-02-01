/* Write a method to replace all spaces in a string with '%20'. You may assume
that the string has sufficient space at the end of the string to hold the 
additional characters, and that you are given the 'true' length of the string. */

#include <iostream>
#include <string>

using namespace std;

string ReplaceSpaces(string str) {

	int newLength, spaceCount = 0;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ')
			spaceCount++;
	}

	// Calcuting the length of the new string
	newLength = str.length() + spaceCount * 2;
	// Creating new string with required length
	string newString(newLength, ' ');

	/* We are working backwards from the end of the string to the front.
	We want to start from the string length minus one because we need to include
	the index of zero. */
	for (int i = str.length() - 1; i >= 0; i--) {
		if (str[i] == ' ') {
			newString[newLength - 1] = '0';
			newString[newLength - 2] = '2';
			newString[newLength - 3] = '%';
			newLength -= 3;
		}
		else {
			newString[newLength - 1] = str[i];
			newLength--;
		}
	}
	return newString;
}

int main() {
	string str = "The number of fucks I give: ";
	cout << str << endl;
	cout << ReplaceSpaces(str) << endl;
}