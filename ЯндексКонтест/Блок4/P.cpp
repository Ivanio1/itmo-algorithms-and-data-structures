//
// Created by Asus on 15.04.2023.
//

#include <iostream>
#include <vector>

using namespace std;

/* Сложность алгоритма O(n*log(n)) n-dfs , log(n)-бинпоиск
 */

vector<vector<int>> graph;
//Храним вершины графа в обе стороны
vector<int> nodes_straight, nodes_reverse;

int count;

int getMiddle(int x, int y) { return (x + y) / 2; }

//Проходим по графу сверху вниз
int dfs_straight(int i, int current_res) {
  int counter = 1;
  nodes_straight[i] = 1;
  for (int j = 0; j < nodes_straight.size(); j++) {
    int value = graph[i][j];
    if (!nodes_straight[j] && value <= current_res) {
      counter += dfs_straight(j, current_res);
    }
  }
  return counter;
}

//Проходим по графу снизу вверх
int dfs_reverse(int i, int current_res) {
  int counter = 1;
  nodes_reverse[i] = 1;
  for (int j = 0; j < nodes_reverse.size(); j++) {
    int value = graph[j][i];
    if (!nodes_reverse[j] && value <= current_res) {
      counter += dfs_reverse(j, current_res);
    }
  }
  return counter;
}

int main() {
  int n, result;
  int left = 0;
  int right = 2000000000;

  cin >> n;
  vector<vector<int>> graph_helper(n, vector<int>(n));
  graph = graph_helper;

  //Заполняем граф
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int helper;
      cin >> helper;
      graph[i][j] = helper;
    }
  }

  //Запускаем бинпоиск
  while (left < right) {
    int flag = 0;
    result = getMiddle(left, right);
    vector<int> helper(n, 0);
    nodes_straight = helper;
    nodes_reverse = helper;

    //Проходим в обе стороны и проверяем, были ли посещены все вершины графа при
    //обходе в глубину
    if (dfs_straight(0, result) == n) {
      //Проверяем, были ли посещены все вершины графа при обходе в глубину
      if (dfs_reverse(0, result) == n) {
        flag = 1;
      } else {
        flag = 0;
      }
    }
    if (!flag) {
      left = result + 1;
    } else
      right = result;
  }
  cout << getMiddle(left, right);
  return 0;
}
