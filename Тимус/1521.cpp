//
// Created by Asus on 30.03.2023.
//
#include <iostream>
#include <vector>


using namespace std;

/* Сложность алгоритма O(n^2) n - цикл, n - операции с вектором
 */

using namespace std;

int main() {

    int n, k;
    cin >> n >> k;

    vector<int> allSoldiers(n);

    for (int i = 0; i < n; i++) {
        allSoldiers[i] = i + 1;
    }

    int toGo = k - 1;
    for (int i = 0; i < n; i++) {
        cout << allSoldiers[toGo] << ' ';
        allSoldiers.erase(allSoldiers.begin() + toGo);
        size_t size = allSoldiers.size();
        if (size!=0) {
            toGo = ((toGo + (k-1)) % size);
        }

    }

    return 0;
}

