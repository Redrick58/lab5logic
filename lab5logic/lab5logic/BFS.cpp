#include <stdlib.h>
#include <stdio.h>
#include <queue>

using namespace std;

int find_unvisited(char* visited, int size) {

	int unvisited = -1;
	for (int i = 0; i < size; i++) {
		if (!visited[i]) {
			unvisited = i;
			break;
		}
	}
	return unvisited;
}

void BFS(char** matrix, char* visited, int size, int v) {

	queue <int> q;
	q.push(v);
	visited[v] = 1;
	while (!q.empty()) {
		v = q.front();
		q.pop();
		printf("%d ", v);
		for (int i = 0; i < size; i++) {
			if ((matrix[v][i]) && (!visited[i])) {
				q.push(i);
				visited[i] = 1;
			}
		}
	}
}

void POSH(char** matrix, int size) {

	int counter = 0;
	char* visited = (char*)calloc(size, sizeof(char));
	for (int i = 0; i < size; i++) {
		visited[i] = 0;
	}
	int v = find_unvisited(visited, size);
	while (v != -1) {
		BFS(matrix, visited, size, v);
		counter++;
		v = find_unvisited(visited, size);
	}
	printf("\n\nЧисло компонент связности: \n");
	printf("%d", counter);
}

