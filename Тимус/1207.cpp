//
// Created by Asus on 04.03.2023.
//

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;


/* Сложность алгоритма O(n*log(n))
 * Алгоритм: Считываем точки в массив точек, одновременно находим "минимальную точку" - самую нижнюю и самую левую.
 * Для всех точек из массива считаем тангенс угла между прямой, которая проходит через "минимальную точку" и текущую, и положительным направлением оси ОХ.
 * Сортируем все точки согласно тангенсу угла.
 * Выводим номера "минимальной точки" и номер точки из середины массива
 */

struct point {
    long long x;
    long long y;
    int index;
    double tangens;
};

bool comparator(point i, point j) {
    return i.tangens < j.tangens;
}

int main() {
    int N;
    long long minX = LONG_LONG_MAX, minY = LONG_LONG_MAX;
    int minIndex;
    cin >> N;
    vector<point> points(N);
    for (int i = 0; i < N; i++) {
        point currentPoint = points[i];
        cin >> currentPoint.x >>currentPoint.y;
        currentPoint.index = i;
        if (currentPoint.x < minX || minY > currentPoint.y && currentPoint.x == minX) {
            minX = currentPoint.x;
            minY = currentPoint.y;
            minIndex = i;
        }
    }
    for (int i = 0; i < N; i++) {
        point currentPoint = points[i];
        if (i == minIndex) {
            currentPoint.tangens = INT_MIN;
        } else {
            currentPoint.tangens = (double) (currentPoint.y - minY) / (double) (currentPoint.x - minX);

        }
    }

    sort(points.begin(), points.end(), comparator);

    cout << points[0].index + 1 << " " << points[N / 2].index + 1 << endl;
    return 0;
}
