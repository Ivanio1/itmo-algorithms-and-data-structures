//
// Created by Asus on 18.04.2023.
//
#include <vector>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

/* Сложность алгоритма O()
 * Веса: 1-поле, 2-лес, 3-вода
 */

#define INFINITY INT32_MAX

struct Cell {
  int x;
  int y;

  Cell(int x, int y) {
    this->x = x;
    this->y = y;
  }
};

int n, m, startX, startY, finishX, finishY;
char type;

//Хранит клетки-соседи по очереди вхождения в них
queue<Cell> queue_of_cells;

//Матрица, хранящая веса клетки в зависимости от ее типа
vector<vector<int>> weights;

//Матрица, хранящая минимальные пути до клетки
vector<vector<int>> map;

void get_right_indexes() {
  startX--;
  startY--;
  finishX--;
  finishY--;
}

void check_possibility_to_go(int prevX, int prevY, int newX, int newY) {
  if (weights[newX][newY] != 3) {
    if (map[newX][newY] > map[prevX][prevY] + weights[newX][newY]) {
      map[newX][newY] = map[prevX][prevY] + weights[newX][newY];
      queue_of_cells.emplace(Cell(newX, newY));
    }
  }
}

string generate_answer(int x, int y) {
  string answer;
  while (map[x][y] != 0) {
    if (y < m - 1) {
      //Пришли справа
      if (map[x][y + 1] == map[x][y] - weights[x][y]) {
        answer = "W" + answer;
        y++;
        continue;
      }
    }
    if (x > 0) {
      //Пришли сверху
      if (map[x - 1][y] == map[x][y] - weights[x][y]) {
        answer = "S" + answer;
        x--;
        continue;
      }
    }

    if (y > 0) {
      //Пришли слева
      if (map[x][y - 1] == map[x][y] - weights[x][y]) {
        answer = "E" + answer;
        y--;
        continue;
      }
    }
    if (x < n - 1) {
      //Пришли снизу
      if (map[x + 1][y] == map[x][y] - weights[x][y]) {
        answer = "N" + answer;
        x++;
        continue;
      }
    }
    return answer;
  }
}

int main() {
  cin >> n >> m >> startX >> startY >> finishX >> finishY;

  //Выставляем нужные размеры
  map.resize(n, vector<int>(m, INFINITY));
  weights.resize(n, vector<int>(m, 3));
  get_right_indexes();

  // Ввод весов клеток
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> type;
      switch (type) {
      case '.':
        weights[i][j] = 1;
        break;
      case 'W':
        weights[i][j] = 2;
        break;
        //        case '#':
        //            distances[i][j] = 3;
        //            break;
      }
    }
  }

  map[startX][startY] = 0;
  queue_of_cells.emplace(Cell(startX, startY));

  while (!queue_of_cells.empty()) {
    int x = queue_of_cells.front().x;
    int y = queue_of_cells.front().y;
    queue_of_cells.pop();

    if (y < m - 1) { // Есть сосед справа
      check_possibility_to_go(x, y, x, y + 1);
    }
    if (x > 0) { // Есть сосед сверху
      check_possibility_to_go(x, y, x - 1, y);
    }
    if (y > 0) { // Есть сосед слева
      check_possibility_to_go(x, y, x, y - 1);
    }

    if (x < n - 1) { // Есть сосед снизу
      check_possibility_to_go(x, y, x + 1, y);
    }
  }

  if (map[finishX][finishY] == INFINITY) {
    return cout << -1, 0;
  }

  cout << map[finishX][finishY] << endl;
  return cout << generate_answer(finishX, finishY), 0;
}
