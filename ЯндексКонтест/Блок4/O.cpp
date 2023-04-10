//
// Created by Asus on 10.04.2023.
//
#include <iostream>
#include <vector>

using namespace std;

/* Сложность алгоритма O(n+m) n-количество вершин, а m — количество ребер.
 *
 */

vector<vector<int>> graph;
vector<int> used;
//Если flag == 0, то граф не двухцветный, иначе двухцветный
int flag;

int x, y, n, m;


//Два цвета - 1 и 2
int getNextColor(int color) {
    if (color == 1) {
        return 2;
    } else {
        return 1;
    }
}

void dfs(int a, int color) {
    used[a] = color;
    for (int current: graph[a]) {
        if (used[current] == color) {
            //вершины a и i покрашены в одинаковый цвет, граф не двухцветный.
            flag = 0;
            return;
        } else if (!used[current]) {
            dfs(current, getNextColor(color));
        }
    }
}

int main() {
    cin >> n >> m;

    //Выделяем нужную память
    graph.resize(n);
    used.resize(n, 0);

    //Строим матрицу смежности
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--;
        y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    flag = 1;
    //Поиск в глубину, корень окрашен цветом 1
    for (int i = 0; i < n; i++){
        if (!used[i]) {
            dfs(i, 1);
        }
    }
        
    if (!flag) {
        return cout << "NO" << endl, 0;

    } else {
        return cout << "YES" << endl, 0;

    }
   
}

