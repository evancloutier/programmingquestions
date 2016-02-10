#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>

bool checkPalindrome(const std::string& str) {
	// Let's create a copy of the string
	std::string palString(str);

	// First we should check if the string is empty
	if (palString.empty())
		return false;

	// Now we can create variables for length
	int length = palString.length();

	// If our length is equal to one, we have a palindrome
	if (length <= 1)
		return true;

	// We can set our characters that we will traverse with
	char start = 0;
	char end = length - 1;

	while (start < end) {
		if (tolower(palString[start]) != tolower(palString[end])) {
			std::cout << "The string is not a palindrome" << std::endl;
			return false;
		}
		start++;
		end--;
	}

	std::cout << "The string is a palindrome" << std::endl;
	return true;
}

int main() {
	std::string testString = "Madam";
	checkPalindrome(testString);

	return 0;
}