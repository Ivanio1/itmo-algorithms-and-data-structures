#include <stdio.h>

int main() {
  int a, b, c, d, k; //Начальные переменные

  //Считывание данных
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);
  scanf("%d", &d);
  scanf("%d", &k);

  //Значение для ускорения алгоритма(пройти TL)
  int prev_a = -1;
  //Основной алгоритм
  for (int i = 1; i <= k; i++) {
    a = a * b;
    if (a < c) {
      a = 0;
      break;
    }
    a = a - c;
    if (a > d) {
      a = d;
    }
    if (a == prev_a) {
      //Значение в этот день останется таким же и итерация даст то же число -
      //дальнейшие итерации аналогично, можно завершать цикл
      break;
    }
    prev_a = a;
  }
  printf("%d", a);
}
