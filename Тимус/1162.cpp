//
// Created by Asus on 13.04.2023.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* Сложность алгоритма O(n*m)
 *
 */

struct exchange_point {
    int a, b;
    double rate, com;

    exchange_point(int a, int b, double rate, double com) {
        this->a = a;
        this->b = b;
        this->rate = rate;
        this->com = com;
    }
};

vector<exchange_point> changes;
vector<double> values;

void result(bool flag) { cout << (flag ? "YES" : "NO") << endl; }

double changeValue(exchange_point current_change) {
    return (values[current_change.a] - current_change.com) * current_change.rate;
}

int main() {
    int N, M, S;
    double V;
    cin >> N >> M >> S >> V;
    //+1 т.к. дальше добавляем по S не уменьшая на единицу
    values.resize(N + 1, 0.000);
    values[S] = V;
    int a, b;
    double RAB, CAB, RBA, CBA;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> RAB >> CAB >> RBA >> CBA;
        changes.emplace_back(exchange_point(a, b, RAB, CAB));
        changes.emplace_back(exchange_point(b, a, RBA, CBA));
    }

    // O(n*m) m-количество обменных пунктов
    for (int i = 0; i < N - 1; i++) {
        for (auto &current_change : changes) {
            values[current_change.b] =
                    max(changeValue(current_change), values[current_change.b]);
        }
    }

    for (auto &i : changes) {
        if (changeValue(i) > values[i.b]) {
            result(true);
            return 0;
        }
    }
    result(false);
    return 0;
}
