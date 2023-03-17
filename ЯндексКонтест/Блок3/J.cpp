//
// Created by Asus on 17.03.2023.
//

#include <algorithm>
#include <iostream>
#include <deque>

using namespace std;

/* Сложность алгоритма O(n)
 * Алгоритм: Полная очередь состоит из двух половинок, это сделано для удобства
 * добавления в центр привилегированных гоблинов
 * На каждом шаге проверяем соответствие размеров двух половинок и в случае
 * необходимости сдвигаем.
 */

using namespace std;

int main() {
  deque<int> left, right;
  int n, number;
  char sign;
  cin >> n;
  while (n != 0) {
    cin >> sign;

    if (left.size() < right.size()) {
      left.push_back(right.front());
      right.pop_front();
    }
    switch (sign) {
    case '-':
      cout << left.front() << '\n';
      left.pop_front();
      break;
    case '*':
      cin >> number;
      right.push_front(number);
      break;
    case '+':
      cin >> number;
      right.push_back(number);
      break;
    }
    n--;
  }
  return 0;
}
