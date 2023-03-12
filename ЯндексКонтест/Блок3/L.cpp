//
// Created by Asus on 09.03.2023.
//


#include <iostream>
#include <set>
#include <queue>

using namespace std;


/* Сложность алгоритма O(n)
 * Алгоритм: храним данные в мультисете для ускорения алгоритма.
 */


int main() {
    int n, k;
    cin >> n >> k;
    int helper;
    queue<int> rightOrder;
    multiset<int> window;

    for(int i = 0; i < n; i++) {
        cin >> helper;
        window.insert(helper);
        rightOrder.push(helper);
        if (i+1 >= k) {
            int answer = *window.begin();
            cout << answer<< " ";
            window.erase(window.find(rightOrder.front()));
            rightOrder.pop();
        }
    }
    return 0;
}
