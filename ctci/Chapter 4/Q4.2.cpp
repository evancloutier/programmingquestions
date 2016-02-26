/* Given a directed graph, design an algorithm to find out whether there 
is a route between two nodes. */

#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
const int MAX = 100;

bool isRoute(int a, int b, bool graph[][MAX]) {
	std::queue<int> queue;
	bool visited[MAX];
	memset(visited, false, sizeof(visited));
	queue.push(a);
	visited[a] = true;
	int tmp;

	while (!queue.empty()) {
		tmp = queue.front();
		queue.pop();
		for (int i = 0; i < MAX; i++) {
			if (graph[tmp][i] && !visited[i]) {
				if (b == i)
					return true;
				queue.push(i);
				visited[i] = true;
			}
		}
	}
	return false;
}