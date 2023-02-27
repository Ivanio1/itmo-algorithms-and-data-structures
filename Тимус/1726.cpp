#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LONG;

int main() {
    LONG n;
    cin >> n;
    LONG x[n], y[n];
    LONG Xsum = 0, Ysum = 0;
    LONG result;

    //Ввод
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    //Сортировка
    sort(x, x + n);
    sort(y, y + n);

    //Подсчитывание путей
    for (int i = 1; i < n; i++) {
        Xsum += (x[i] - x[i - 1]) * i * (n - i);
        Ysum += (y[i] - y[i - 1]) * i * (n - i);
    }
    result = (Xsum + Ysum) * 2 / (n * (n - 1));

    cout << result << endl;
}
