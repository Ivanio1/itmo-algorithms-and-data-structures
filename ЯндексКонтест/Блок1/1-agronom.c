#include <stdio.h>

int main() {
    int n; //количество цветков на грядке
    int start = 1, end = 1, begin = 1; //индексы первого и последнего цветка и индекс начала последовательности
    int current_x; //переменная для текущего значения
    int pre_previous_x, previous_x; //переменные для сохранения двух предыдущих значений
    int max_length = 0; //максимальная длина искомой последовательности

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &current_x);
        if (current_x == pre_previous_x &
            current_x == previous_x) { //Если три одинаковых, то смещаем начало нашей последовательности
            begin = i - 1;
        }
        int new_length = i - begin;
        if (new_length > max_length) {  //Ищем максимальную подходящую последовательность
            max_length = new_length;
            start = begin;
            end = i;
        }
        pre_previous_x = previous_x; //Смещаем предыдущие значения
        previous_x = current_x;
    }
    printf("%d", start);
    printf("%s", " ");
    printf("%d", end);
}
