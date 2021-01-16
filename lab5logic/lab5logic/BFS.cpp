#include <stdlib.h>
#include <stdio.h>
#include <queue>

using namespace std;

int find_unvisited(char* visited, int size) {
	for (int i = 0; i < size; i++) {
		if (visited[i] == 0) {
			return i;
		}
	}
	return -1;
};

void BFS(char** matrix, char* visited, int v, int size) {

	queue <int> q;
	q = {};
	q.push(v);
	visited[v] = 1;
	while (!q.empty()) {
		v = q.front();
		q.pop();
		printf("%d ", v);
		for (int i = 0; i < size; i++) {
			if ((matrix[v][i]) && (visited[i] == 0)) {
				q.push(i);
				visited[v] = 1;
			}
		}
	}

}

void POG(char** matrix, int size) {
	char* visited = (char*)calloc(size, sizeof(char));
	for (int i = 0; i < size; i++) {
		visited[i] = 0;
	}
	int v = find_unvisited(visited, size);
	while (v != -1) {
		if (visited[v] == 0) {
			BFS(matrix, visited, v, size);
		}
		v = find_unvisited(visited, size);
	}
}