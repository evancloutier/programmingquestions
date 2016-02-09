#include <iostream>
#include <string>
#include <map>
#include <algorithm>

void anagramDifference(const std::string& str) {
    std::string firstString;
    std::string secondString;
    
    // Testing for odd length
    if (str.length() % 2 != 0) {
        std::cout << "-1" << std::endl;
        return;
    }
    
    // We can split up our strings for comparison
    firstString = str.substr(0, str.length()/2);
    secondString = str.substr(str.length()/2);
    
    // Next we can create our maps for both strings
    std::map<char,int> firstMap;
    std::map<char,int> secondMap;
    
    // Let's create our variables for calculating the differences
    int valueDifference = 0;
    int totalDifference = 0;
    
    // Now we can hash our values to the maps
    for (int i = 0; i < firstString.length(); i++) {
        firstMap[firstString[i]]++;
        secondMap[secondString[i]]++;
    }
    
    // Next let's iterate through each map and find our difference
    for (char c = 'a'; c <= 'z'; c++) {
        if ((firstMap[c] > secondMap[c]) && firstMap[c] != 0) {
            valueDifference = firstMap[c] - secondMap[c];
            totalDifference += valueDifference;
            valueDifference = 0;
        }
    }
    std::cout << totalDifference << std::endl;
    return; 
}

int main() {
	std::string testString = "aaabbb";
	anagramDifference(testString);
	testString = "ab";
	anagramDifference(testString);
	testString = "abc";
	anagramDifference(testString);
	testString = "mnop";
	anagramDifference(testString);
	testString = "xyyx";
	anagramDifference(testString);
	testString = "xaxbbbxx";
	anagramDifference(testString);

	return 0;
}