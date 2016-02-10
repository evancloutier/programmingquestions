#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>

// Look into using hash map?

void kthCharacter(const std::string& str, const int& k) {
	// First we should create a copy of the string we are passed
	std::string inputString(str);
	// Next we'll make a vector to store our results
	std::vector<std::string> substrings;
	// We'll also need a string to store for the concatenation
	std::string totalString;

	for (int i = 0; i < inputString.length(); i++) {
		for (int j = 0; j <= inputString.length(); j++) {
			if ((inputString.substr(i,j).empty()))
				continue;
			substrings.push_back(inputString.substr(i,j));
		}
	}

	// Now we can elimiate the duplicates in the vector
	substrings.erase(std::unique(substrings.begin(), substrings.end()), substrings.end());
	// Sort them lexicographically
	std::sort(substrings.begin(), substrings.end());

	// And transfer them into our string
	for (int i = 0; i < substrings.size(); i++) {
		totalString += substrings.at(i);
	}

	std::cout << totalString[k-1] << std::endl;
}

int main() {
	std::string testString = "wcweojncpqwcofrhxnzgbdrd";
	int k = 251;
	kthCharacter(testString, k);
}

/* Test Input 

5
nvzjkcahjwlhmdiuobjdwbanmvrtadopapbktdtezellktgywrdstdhhayaadqrdhspavjgxprk
2071
szkkcedhlkhjnjofbrnvhntsushncjavkmfn
465
wcweojncpqwcofrhxnzgbdrd
251
pfpgrnlorzzhdoxzsnemubzvkcbbfb
77
judaioobpoiteiszvzlscmpmpqqwuvtdqzdapudfimaowsnttalwndievaapwusmtyoksrpcfpqbkgvfiibvlkbjkcy
2473

*/

/* Test Output

b
d
d
o
w

*/