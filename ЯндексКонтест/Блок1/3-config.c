//
// Created by Asus on 13.02.2023
//

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

/* Алгоритм:
 * Для каждого нового блока храним значения переменных из предыдущего блока,
 * также храним текущие значения для каждой переменной
 */

//Хранилище текущих значений всех переменных
map<string, int> global_map;
//Хранилище блоков с предыдущими значениями
vector<map<string, int>> all_maps;

//Проверка, что элемент с ключом есть в блоке
int is_element_in_map(const string &key, const map<string, int> &new_map) {
    return new_map.count(key);
}

//Если элемента нет - приравниваем к нулю
void make_zero(string &key) {
    if (is_element_in_map(key, global_map) != 1) {
        global_map[key] = 0;
    }
}

//Проверяем, что строчка вида <variable>=<number>
bool is_var_num(const string &number) {
    return number[0] == '-' && isdigit(number[1]) || isdigit(number[0]);
}

int main() {

    //Строка считывания
    string new_str;

    //Создание начального блока
    map<string, int> new_map;
    all_maps.push_back(new_map);


    while (cin >> new_str) {
        switch (new_str[0]) {
            case '{': {
                //Создаем новый блок
                map<string, int> next_map;
                all_maps.push_back(next_map);
                break;
            }
            case '}':
                //Возвращаем предыдущие значения переменных и уничтожаем текущий блок
                for (auto &element: all_maps.back()) {
                    global_map[element.first] = element.second;
                }
                all_maps.pop_back();
                break;
            default:
                if (new_str.empty()) break;

                //Сплиттим строку по символу "="
                int i = new_str.find('=');
                string left_var = new_str.substr(0, i);
                string right_var = new_str.substr(i + 1);

                //строка в виде <variable>=<variable>
                if (!is_var_num(right_var)) {
                    int new_right_var;
                    make_zero(right_var);
                    new_right_var = global_map[right_var];
                    make_zero(left_var);
                    if (is_element_in_map(left_var, all_maps.back()) != 1) { 
                        all_maps.back()[left_var] = global_map[left_var];
                    }
                    global_map[left_var] = new_right_var;
                    cout << new_right_var << endl;
                } else {    //строка в виде <variable>=<number>
                    make_zero(left_var);            //Проверяем, существует ли переменная
                    if (is_element_in_map(left_var, all_maps.back()) !=1) {
                        all_maps.back()[left_var] = global_map[left_var];
                    }
                    //Обновляем текущее значение по ключу
                    global_map[left_var] = stoi(right_var);
                }
                break;
        }
    }
}
