//
// Created by Asus on 23.02.2023.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* Сложность алгоритма O(N*logN)
 * Алгоритм: записываем все числа, сортируем в порядке убывания, каждый к-тый
 * элемент вычитаем
 */

int main() {
  int n, k;
  cin >> n >> k;

  int helper;
  vector<int> prices;
  int overall_sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> helper;
    prices.push_back(helper);
    overall_sum += helper;
  }

  // reverse array - порядок убывания
  sort(prices.rbegin(), prices.rend());

  for (int i = k - 1; i < n; i += k) {
    overall_sum -= prices[i];
  }
  cout << overall_sum;

  return 0;
}
