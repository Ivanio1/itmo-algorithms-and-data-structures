//
// Created by Asus on 27.02.2023.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/* Сложность алгоритма O(n*log(n))
 * Алгоритм: Бинарный поиск по ответу
 */

bool checker(int answer, int k, vector<int> &coordinates) {
  int counter_of_cows = 1; //Первую корову ставим всегда в начало
  int last_cow = coordinates[0];
  for (int element : coordinates) {
    if (element - last_cow > answer) {
      counter_of_cows++;
      last_cow = element;
      if (counter_of_cows >= k)
        return true;
    }
  }
  return false;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> coordinates;

  for (int i = 0; i < n; i++) {
    int input;
    cin >> input;
    coordinates.push_back(input);
  }

  int left = 0;
  int right = coordinates[n - 1];
  while (right > left) {
    int answer = (right + left) / 2;
    if (checker(answer, k, coordinates)) {
      left = answer + 1;
    } else {
      right = answer;
    }
  }
  cout << left;
  return 0;
}
