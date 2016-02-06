// Implement a function which reverses a null-terminated string

#include <iostream>
#include <string>
#include <algorithm>

void reverse(char* str) {
	char* start = str; // Signifies the start of the string
	char* end = start + strlen(str) - 1; // Signifies the end of the string

	// Swapping
	while(start < end) { 
		char temp = *end; // Setting temp value equal to the end of the string
		*end = *start; // Setting the end value equal to the start of the string
		*start = temp; // Setting the start of the string the end (temp) value
		start++; // Incrementing the start to continue swap
		end--; // Decrememnting the end to continue swap
	}
}

int main() {
	char str[] = "Interior crocodile alligator";
	std::cout << str << std::endl;
	reverse(str);
	std::cout << str << std::endl;
}