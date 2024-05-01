#include <bits/stdc++.h>
using namespace std;

const int max_nodes = 6;
bool visited[max_nodes] = {false};
int graph[max_nodes][max_nodes] = {
  {0, 0, 1, 0, 1, 0},
  {0, 0, 0, 0, 0, 1},
  {1, 0, 0, 1, 1, 1},
  {0, 0, 1, 0, 0, 1},
  {1, 0, 1, 0, 0, 1},
  {0, 1, 1, 1, 1, 0}
};

void dfs(int numNodes, int startNode) {
  stack<int> stack;
  stack.push(startNode);
  visited[startNode] = true;

  cout << "Depth-First Traversal: ";
  while (!stack.empty()) {
    int currentNode = stack.top();
    stack.pop();
    cout << currentNode << " ";

    for (int neighbor = 0; neighbor < numNodes; ++neighbor) {
      if (graph[currentNode][neighbor] && !visited[neighbor]) {
        stack.push(neighbor);
        visited[neighbor] = true;
      }
    }
  }
  cout << endl;
}

int main() {
  int startNode;
  cout << "Enter the starting node (index from 0 to " << max_nodes - 1 << "): ";
  cin >> startNode;

  if (startNode < 0 || startNode >= max_nodes) {
    cout << "Invalid starting node!\n";
    return 1;
  }
  dfs(max_nodes, startNode);

  return 0;
}
