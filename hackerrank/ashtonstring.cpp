#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <set>
#include <algorithm>

// Look into using hash map? -- check this out

void kthCharacterSet(const std::string& str, const int& k) {
	// First let's create a copy of the string we are passed
	std::string inputString(str);
	// Next we'll make a set to store our unique results
	std::set<std::string> substringSet;
	// And a vector to store the results afterwards
	std::vector<std::string> substringVector;
	// Finally we need a string to store the sorted substrings
	std::string totalString;

	// Now we can get all the substrings of the string
	for (int i = 0; i < inputString.length(); i++) {
		for (int j = 0; j <= inputString.length(); j++) {
			if (inputString.substr(i,j).empty())
				continue;
			substringSet.insert(inputString.substr(i,j));
		}
	}

	std::copy(substringSet.begin(), substringSet.end(), std::back_inserter(substringVector));

	for (int i = 0; i < substringVector.size(); i++) {
		totalString += substringVector.at(i);
	}

	if (k > totalString.length())
		return;

	std::cout << totalString << std::endl;
	std::cout << totalString.at(k-1) << std::endl;
}

int main() {
    int cases, k;
    std::string testString;
    std::cin >> cases;
    
    for (int i = 0; i < cases; i++) {
        std::cin >> testString;
        std::cin >> k;
        kthCharacter(testString, k);
    }
}



