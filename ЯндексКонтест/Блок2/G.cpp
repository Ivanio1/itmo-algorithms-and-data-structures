//
// Created by Asus on 27.02.2023.
//

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

/* Сложность алгоритма O(n*logN) из-за сортировки
 * Алгоритм: Делим на 2 группы: Парные буквы и одиночки.
 */

map<char, int> weights;

int main() {
    //Ввод
    string input_string;
    cin >> input_string;
    map<char, int> counts;
    for (int i = 0; i < 26; i++){
        cin >> weights[i + 'a'];
    }
    for (char c : input_string){
        counts[c] += 1;
    }

    //Деление на группы
    string lonelyLetters;
    string groupLetters;
    string duplicates;
    for (char letter : input_string) {
        if (counts[letter]>=2){
            if (count(groupLetters.begin(), groupLetters.end(), letter) == 0) {
                groupLetters.push_back(letter);
            } else if (count(duplicates.begin(), duplicates.end(), letter) == 0) {
                duplicates.push_back(letter);
            } else {
                lonelyLetters.push_back(letter);
            }
        } else {
            lonelyLetters.push_back(letter);
        }
    }


    //Сортировка по весам
    sort(groupLetters.begin(), groupLetters.end(), [](char i, char j) {
        return weights.find(i)->second > weights.find(j)->second;
    });

    cout << groupLetters;
    cout << lonelyLetters;
    string reversedLetters;
    for (int i = groupLetters.size() - 1; i >= 0; i--) {
        reversedLetters += groupLetters[i];
    }
    cout << reversedLetters << endl;
}
