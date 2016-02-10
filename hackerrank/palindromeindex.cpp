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
			return false;
		}
		start++;
		end--;
	}
	return true;
}

void palindromeIndex(const std::string& str) {
	// Let's create a copy of our string
	std::string palString(str);

	// First we can check if the string is empty
	if (palString.empty())
		return;

	// Now we can create a variable for length
	int length = palString.length();

	// And a variable to track the index
	int index = -1;

	// We can set our characters that we will traverse with
	char start = 0;
	char end = length - 1;

	
	while (start < end) {
		// If current characters don't match
		if (tolower(palString[start]) != tolower(palString[end])) {
			// Create a substring and check if a palindrome exists
			if (checkPalindrome(palString.substr(start + 1, end + 1)) == true) {
				index = start;
				std::cout << index << std::endl;
				return;
			}
			else {
				index = end;
				std::cout << index << std::endl;
				return;
			}
		}
		start++;
		end--;
	}
	std::cout << index << std::endl;
	return;
}

int main() {
	std::string testString = "hgygsvlfcwnswtuhmyaljkqlqjjqlqkjlaymhutwsnwcwflvsgygh";
	palindromeIndex(testString);

	return 0;
}