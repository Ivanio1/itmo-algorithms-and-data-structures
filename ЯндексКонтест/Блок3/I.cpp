//
// Created by Asus on 19.03.2023.
//

#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;

/* Сложность алгоритма O(p*log(k)) - p-цикл, log(k) - find и count в map
 * Алгоритм: Идем по запросам Пети, достаём нужный индекс текущей машинки, если с таким
 * типом машинка уже на полу, то обновляем индекс, если нет, то либо ставим на пол, либо убираем
 * машинку с максимальным следующим индексом и ставим текущую.
 * Используем map для автоматической сортировки элементов, ключ - индекс следующей машинки такого типа, значение - тип машинки
 */

int operations = 0;
map<int, int> floor;

int main() {
    int n, k, p = 0;
    cin >> n >> k >> p;


    vector<int> commands(p);
    vector<list<int>> indexesByTypes(n);


    //Ввод данных
    for (int i = 0; i < p; i++) {
        cin >> commands[i];
        indexesByTypes[commands[i] - 1].push_back(i);
    }

    //Основной алгоритм
    for (int i = 0; i < p; i++) {
        if (floor.count(indexesByTypes[commands[i] - 1].front()) != 0) {
            floor.erase(floor.find(indexesByTypes[commands[i] - 1].front())); //Если на полу есть машинка такого типа, обновляем следующий индекс
        } else {
            if (floor.size() == k) {
                auto iterator = floor.end();
                iterator--;
                floor.erase(iterator);
            }
            operations++;
        }
        indexesByTypes[commands[i] - 1].pop_front();

        auto currentIndexes = indexesByTypes[commands[i] - 1];

        if(!currentIndexes.empty()){
            floor[currentIndexes.front()] = commands[i];
        } 
    }
    cout << operations;

    return 0;
}
