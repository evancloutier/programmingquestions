#include <iostream>
#include <vector>
#include <set>
#include <cctype>

void numIslands(const std::string& str, const int& k) {
	// We can make a copy of our string
	std::string inputString(str);
	// We will use a set to store the unique substrings
	std::set<std::string> substringSet;
	// And a vector when comparing them
	std::vector<std::string> substringVector;
	// Next we need to create a variable to match the number of islands
	int islandCount = 0;
	// Finally a variable to track the number of strings that have k islands
	int stringCount = 0;

	// We can get all of the unique substrings of the given string
	for (int i = 0; i < inputString.length(); i++) {
		for (int j = 0; j <= inputString.length(); j++) {
			if (inputString.substr(i,j).empty())
				continue;
			substringSet.insert(inputString.substr(i,j));
		}
	}

	// Copying our elements into the vector
	std::copy(substringSet.begin(), substringSet.end(), std::back_inserter(substringVector));

	// Let's keep track of the current substring
	std::string currentSub;
	// We need an iterator to find substrings
	int j = 1;
	// And variables to track our indices
	int currentIndex, nextIndex;

	// Let's iterate through the vector and find substrings that form islands
	for (int i = 0; i < substringVector.size(); i++) {
		currentSub = substringVector.at(i);
		currentIndex = inputString.find(currentSub);
		nextIndex = inputString.find(currentSub, currentIndex+j);
		// Reset our incremetor for looping
		j = 0;

		while (nextIndex != -1) {
			if (abs((nextIndex - currentIndex)) <= currentSub.length()) {
				j++;
				currentIndex = nextIndex;
				nextIndex = inputString.find(currentSub, currentIndex + j);
			}
			else {
				islandCount++;
				j++;
				currentIndex = nextIndex;
				nextIndex = inputString.find(currentSub, currentIndex + j);
			}	
		}

		if (currentIndex != -1)
			islandCount++;
		if (islandCount == k)
			stringCount++;
		// Reset our variables
		j = 1;
		islandCount = 0;
	}
	std::cout << stringCount << std::endl;
}

int main() {
	int islands = 2;
	std::string testString = "abaab";
	numIslands(testString, islands);
}