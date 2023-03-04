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
    double angle;
};

bool comparator(point i, point j) {
    return i.angle < j.angle;
}

int main() {
    int N;
    long long minX = LONG_LONG_MAX, minY = LONG_LONG_MAX;
    int minIndex;
    cin >> N;
    vector<point> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i].x >> points[i].y;
        points[i].index = i;
        if (points[i].x < minX || minY > points[i].y && points[i].x == minX) {
            minX = points[i].x;
            minY = points[i].y;
            minIndex = i;
        }
    }
    for (int i = 0; i < N; i++) {
        if (i == minIndex) {
            points[i].angle = INT_MIN;
        } else {
            points[i].angle = (double) (points[i].y - minY) / (double) (points[i].x - minX);

        }
    }

    sort(points.begin(), points.end(), comparator);

    cout << points[0].index + 1 << " " << points[N / 2].index + 1 << endl;
    return 0;
}
