/* Assume you have a method isSubstring which checks if one word
is a substring of another. Given two strings, s1 and s2, write
code to check if s2 is a rotation of s1 using only one call
to isSubstring. */

#include <iostream>
#include <string>

/* The logic behind this question is intuitive - no matter
where the first string is rotated, it will always be a 
substring of the first string repeated twice. 
---> i.e. "erbottlewat" in "waterbottlewaterbottle" */

bool isRotation(const std::string& s1, const std::string& s2) {
	int length = s1.length();

	if ((length == s2.length()) && length > 0) {
		std::string newString = s1 + s1;
		return isSubstring(newString, s2);
	}
}