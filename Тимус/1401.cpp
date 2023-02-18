//
// Created by Asus on 15.02.2023
//

#include <iostream>
#include <vector>

using namespace std;


int pow(int num, int p) {
    int start_num = num;
    for (int i = 1; i < p; i++) {
        num *= start_num;
    }
    return num;
}


//Заполнение 2*2
void fill_cube(vector<vector<int>> &board, int &counter, int x, int y, int hole_x, int hole_y) {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            //Проверка, что не дыра
            if (x != hole_x - i || y != hole_y - j) {
                board[x + i][y + j] = counter;
            }
    counter++;
}

//Заполнение доски
void fill_board(vector<vector<int>> &board, int &counter, int n, int x, int y, int hole_x, int hole_y) {

    if (n == 2) {
        fill_cube(board, counter, x, y, hole_x, hole_y);
        return;
    }

    n = n / 2;

    //Заполнение центральной фигуры
    int x_center = x + n - 1;
    int y_center = y + n - 1;
    if (hole_x > x_center) {
        if (hole_y <= y_center) {//Если дыра в правой верхней
            fill_cube(board, counter, x_center, y_center, x_center + 1, y_center);

        } else { //Если дыра в правой нижней
            fill_cube(board, counter, x_center, y_center, x_center + 1, y_center + 1);
        }
    } else {
        if (hole_y <= y_center) {     //Если дыра в левой верхней
            fill_cube(board, counter, x_center, y_center, x_center, y_center);
        } else {  //Если дыра в левой нижней
            fill_cube(board, counter, x_center, y_center, x_center, y_center + 1);
        }
    }

    //Деление доски на 4 части
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (x + i * n <= hole_x && hole_x < x + i * n + n && y + j * n <= hole_y && hole_y < y + j * n + n) { //Если в квадрате есть дыра
                fill_board(board, counter, n, x + i * n, y + j * n, hole_x, hole_y);
            } else {
                fill_board(board, counter, n, x + i * n, y + j * n, x + n - 1 + i, y + n - 1 + j);
            }
        }
    }

}

int main() {

    int n;
    int hole_x, hole_y;

    //Ввод данных
    cin >> n;
    cin >> hole_x >> hole_y;

    //Размер доски
    n = pow(2, n);

    vector<vector<int>> board(n, vector<int>(n));

    //Для удобства делаем координаты левой верхней клетки (0, 0), а не (1, 1)
    hole_x--;
    hole_y--;
    board[hole_x][hole_y] = 0; // Обнуляем пустую клетку
    int counter = 1; // Номер первой фигуры

    fill_board(board, counter, n, 0, 0, hole_x, hole_y);

    //Вывод результатов
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
