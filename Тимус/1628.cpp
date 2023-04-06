//
// Created by Asus on 05.04.2023.
//
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

/* Сложность алгоритма O((p+n+m) * log(p+n+m)) - из-за сортировки
 */

bool compare_by_rows(pair<int, int> first, pair<int, int> second) {
    if (first.first != second.first) {
        return first.first < second.first;
    } else {
        return first.second < second.second;
    }
}

bool compare_by_columns(pair<int, int> first, pair<int, int> second) {
    if (first.second != second.second) {
        return first.second < second.second;
    } else {
        return first.first < second.first;
    }
}

vector<pair<int, int>> fill_borders(int n, int m, vector<pair<int, int>> cells) {
    for (int i = 1; i <= m; i++) {
        cells.push_back({0, i});
        cells.push_back({n + 1, i});
    }
    for (int i = 1; i <= n; i++) {
        cells.push_back({i, 0});
        cells.push_back({i, m + 1});
    }
    return cells;
}


int main() {

    int m, n, p;
    int answer = 0;
    cin >> n >> m >> p;
    vector<pair<int, int>> cells;
    set<pair<int, int>> duplicates;

    //Ввод черных дней
    for (int i = 0; i < p; i++) {
        int x, y;
        cin >> x >> y;
        cells.push_back({x, y});
    }

    //Заполнение границ
    cells = fill_borders(n, m, cells);

    int number_of_black_cells = p + n * 2 + m * 2;
    sort(cells.begin(), cells.end(), compare_by_rows);
    for (int i = 0; i < number_of_black_cells; i++) {
        int diff = cells[i + 1].second - cells[i].second;
        if (diff >= 2) {
            if (cells[i].first == cells[i + 1].first) {
                // Если расположены через одну клетку(т.е. расстояние = 2 => между ними одна белая), то запомним их.
                if (diff == 2) {
                    pair<int, int> new_pair = {cells[i].first, cells[i].second + 1};
                    duplicates.insert(new_pair);
                } else {
                    answer++;
                }
            }
        }
    }

    sort(cells.begin(), cells.end(), compare_by_columns);
    for (int i = 0; i < number_of_black_cells; i++) {
        int diff = cells[i + 1].first - cells[i].first;
        if (diff >= 2) {
            if (cells[i].second == cells[i + 1].second) {
                // Если расположены через одну клетку(т.е. расстояние = 2 => между ними одна белая), то если уже запоминали ее, добавляем к результату.
                if (diff == 2) {
                    pair<int, int> new_pair = {cells[i].first + 1, cells[i].second};
                    if (duplicates.count(new_pair) != 0) {
                        answer++;
                    }
                } else {
                    answer++;
                }
            }
        }
    }

    cout << answer;

    return 0;
}

