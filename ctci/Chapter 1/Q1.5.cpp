/* Implement a method to perform basic string compression using
the counts of repeated characters. For example, the string
'aabcccccaaa' would become a2b1c5a3. If the compressed string
would not become smaller than the original string, your method
should return the original string. You may assume the string has
only upper and lower case letters (a-z). */
#include <iostream>
#include <string>

void compress(const std::string& str) {
	// First let's make a copy of our string
	std::string inputString(str);
	// Let's check that our string isn't empty
	if (inputString.empty())
		return;
	// We need two characters to traverse through the string
	char current;
	char next;
	// A counter to keep track of the current letter
	int count = 1;
	// And finally a string where we will keep our answer
	std::string finalString;

	for (int i = 0; i < inputString.length(); i++) {
		current = inputString[i];
		next = inputString[i+1];
		if (current == next) {
			count++;
		}
		else {
			finalString += current;
			finalString += std::to_string(count);
			count = 1;
		}
	}
	if (finalString.length() < inputString.length())
		std::cout << finalString << std::endl;
	else
		std::cout << inputString << std::endl;
}

int main() {
	std::string testString = "aabcccccaaa";
	compress(testString);
}