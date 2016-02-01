/* Implement a method to perform basic string compression using the counts of
repeated characters. For example, the string aabcccccaaa would be come a2b1c5a3.
If the "compressed" string would not become smaller than the original string,
your method should return the original string. You can assume the string has only
upper and lower case letters (a-z). */

#include <iostream>
#include <sstream>
#include <unordered_map>
#include <string>

using namespace std;

string compress(const string& str) {

}


// This doesn't work - fix it eventually!
string compressHash(const string& str) {
	// First let's create a copy of the string
	string comString (str);
	// We also need a string where our final string will take place
	string finalString = "";
	// Finally we need to string stream
	ostringstream oss;

	// Next we will create a hash map to store the elements and their occurances
	unordered_map<char,int> comMap;
	// We also need a variable to track the next character
	char next = comString.at(0);

	// Now we can iterate through the string to map the elements
	for (int i = 0; i < comString.length(); i++) {
		// Get the next character
		next = comString.at(i+1);

		// First we check if the value is the same as the next value
		if (comString[i] == next) {
			cout << "Match at: " << i << endl;
			// Increment the value of the hash
			comMap[comString[i]]++;
		}
		else {
			cout << "No match at: " << i << endl;
			// Append the letter and repetitions to finalString
			finalString += comString.at(i);
			cout << "The value of " << comString.at(i) << " is: " << comMap.at(comString[i]) << endl;
			// Reset the value of the hash
			comMap[comString[i]] = 0;
		}
	}
	return finalString;
}

int main() {
	string str = "aaccddd";
	cout << compress(str) << endl;
}