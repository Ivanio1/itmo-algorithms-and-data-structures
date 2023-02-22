//
// Created by Asus on 22.02.2023.
//

#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;


/* Сложность алгоритма O(N*log(N))
 * sorting - компаратор для сортировки
 * first + second > second + first - пример: 2+20 > 20+2 => 220>202
 */
struct {
    bool operator()(const string&  first, const string&  second) { return first + second > second + first; }
} sorting;

int main()
{
    list<string> numbers;
    string line;

    while (getline(cin, line) && !line.empty()){
        numbers.push_back(line);
    }

    numbers.sort(sorting);

    for (string &element : numbers){
        cout << element;
    }

    return 0;
}
