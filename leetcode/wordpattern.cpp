/* Given a pattern and a string str, find if str follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
Example: pattern = "abba", str = "dog cat cat dog" should return true.
         pattern = "abba", str = "dog cat cat fish" should return false.
         pattern = "aaaa", str = "dog cat cat dog" should return false.
         pattern = "abba", str = "dog dog dog dog" should return false.
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space. */
#include <iostream>
#include <string>
#include <map>

bool wordPattern(string pattern, string str) {
    // check our cases
    if (pattern.length() == NULL || str.length() == NULL)
        return false;
    // we can separate our string into a string array
    std::vector<std::string> stringVector = split(str, ' ');
    
    // and check for a difference in size
    if (pattern.length() != stringVector.size())
        return false;
    
    // now we can create our pattern map
    std::map<char,std::vector<int>> patternMap;
    
    for (int i = 0; i < pattern.length(); i++) {
        patternMap[pattern[i]].push_back(i);
    }
 
    for (int i = patternMap.begin(); i != patternMap.end(); i++) {
        std::vector<int> parseVector = patternMap.at(i);
        for (int j = parseVector.begin(); j != parseVector.end(); j++) {
            if (stringVector.at(parseVector.at(j)) != stringVector.at(parseVector.at(0)))
                return false;
        }       
    }
    return true;
}