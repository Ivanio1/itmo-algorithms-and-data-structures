//
// Created by Asus on 09.02.2023.
//

#include <iostream>
#include <string>

#include <vector>

using namespace std;

bool is_animal(char current_letter) {
  return 97 <= current_letter & current_letter <= 122;
}

bool is_cage(char current_letter) {
  return 65 <= current_letter & current_letter <= 90;
}

bool check(char current_letter, vector<char> letters) {
  return (is_cage(letters.back()) && is_animal(current_letter) ||
          is_animal(letters.back()) && is_cage(current_letter)) &&
         tolower(letters.back()) == tolower(current_letter);
}

int main() {
  //Начальная строка
  string my_string;
  std::cin >> my_string;

  //Размер строки
  auto size = (size_t)my_string.size();
  if (size % 2 == 1) {
    printf("Impossible"); //Если ловушек или зверей больше
    return 0;
  }
  if (size == 0) {
    printf("Impossible"); //Если пустая строка
    return 0;
  }

  //Счетчик индексов животных
  int animal_counter = 0;
  //Счетчик индексов ловушек
  int cage_counter = 0;

  //Хранилища всех букв
  vector<char> letters;
  //Хранилища индексов животных и ловушек
  vector<int> animals, cages;
  //Массив индексов животных
  int *result = new int[size / 2];

  //Первое заполнение
  char first_letter = my_string[0];
  letters.push_back(first_letter);
  if (is_animal(first_letter)) {
    animal_counter++;
    animals.push_back(animal_counter);
  } else {
    cage_counter++;
    cages.push_back(cage_counter);
  }

  for (int i = 1; i < size; i++) {
    char current_letter = my_string[i];
    if (is_animal(current_letter)) {
      animal_counter++;
      animals.push_back(animal_counter);
    } else {
      cage_counter++;
      cages.push_back(cage_counter);
    }

    if (check(current_letter, letters)) {
      result[cages.back() - 1] = animals.back();
      animals.pop_back();
      cages.pop_back();
      letters.pop_back();
    } else {
      letters.push_back(current_letter);
    }
  }
  //Вывод
  if (letters.empty()) {
    printf("%s", "Possible\n");
    string rez;
    for (int i = 0; i < size / 2; i++) {
      rez += to_string(result[i]) + " ";
    }
    std::cout << rez;

  } else {
    printf("%s", "Impossible");
  }

  return 0;
}
