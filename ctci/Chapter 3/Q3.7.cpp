/* An animal shelter holds only dogs and cats, and operates strictly on 
a "first in, first out" basis. People must adopt either the "oldest" 
(based on arrival time) of all animals at the shelter, or they can select 
whether they would prefer a dog or a cat (and will receive the oldest 
animal of that type). They cannot select which specific animal they
would like. Create the data structures to maintain this system and 
implement operations such as enqueue, dequeueAny, dequeueDog, and 
dequeueCat. You may use the built-in LinkedList data structure. */

#include <iostream>
#include <queue>
#include <string>
#include <climits>

class Animal {
private:
	std::queue<int> dog, cat;
	int order;
public:
	Animal() {
		order = 1;
	}

	void enqueue(std::string a) {
		if (a == "dog") {
			dog.push(order);
			order++;
		}
		else if (a == "cat") {
			cat.push(order);
			order++;
		}
		return;
	}

	int dequeueAny() {
		int temp;
		// Note that the 'oldest' has the smallest order value
		if (dog.front() > cat.front()) {
			temp = cat.front();
			cat.pop();
		}
		else {
			temp = dog.front();
			dog.pop();
		}
		return temp;
	}

	int dequeueDog() {
		if (dog.empty()) {
			return INT_MIN;
		}
		int temp = dog.front();
		dog.pop();
		return temp;
	}

	int dequeueCat() {
		if (cat.empty()) {
			return INT_MIN;
		}
		int temp = cat.front();
		cat.pop();
		return temp;
	}
};

int main() {
	Animal myAnimal;
	myAnimal.enqueue("dog");
	myAnimal.enqueue("dog");
	myAnimal.enqueue("dog");
	myAnimal.enqueue("dog");
	myAnimal.enqueue("cat");
	myAnimal.enqueue("cat");
	myAnimal.enqueue("cat");
	myAnimal.enqueue("dog");
	std::cout << myAnimal.dequeueAny() << std::endl;
	std::cout << myAnimal.dequeueDog() << std::endl;
	std::cout << myAnimal.dequeueCat() << std::endl;
}


