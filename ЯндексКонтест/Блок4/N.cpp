//
// Created by Asus on 27.03.2023.
//

#include <iostream>
#include <vector>
#include <list>

using namespace std;

/* Сложность алгоритма O()
 * Алгоритм:
 */

using namespace std;

//содержит массивы номеров копилок, которые можно открыть, взаимодействуя с
//копилкой по индексу
vector<list<int>> graph;
vector<int> used;
int ans = 0;

void dfs(int i) {
  used[i] = 1;
  for (int value : graph[i]) {
    if (!used[value]) {
      dfs(value);
    } else if (used[value] == 1) {
      ans++;
    }
  }
  used[i] = 2;
}

int main() {
  int n;
  cin >> n;
  used.resize(n, 0);
  graph.resize(n);

  int helper;
  for (int i = 0; i < n; i++) {
    cin >> helper;
    graph[helper - 1].push_back(i);
  }

  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      dfs(i);
    }
  }

  cout << ans << endl;
}
