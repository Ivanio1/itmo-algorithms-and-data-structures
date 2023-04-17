//
// Created by Asus on 17.04.2023.
//

#include <iostream>
#include <vector>


using namespace std;

/* Сложность алгоритма O(N*M)
 */


#define maxN 501

struct gaspipeline {
    int a, b, c;

    gaspipeline(int a, int b, int c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

vector<gaspipeline> graph;
vector<int> used(maxN, -1);

void findMaxPath(int j) {
    if (used[graph[j].a] != -1 && used[graph[j].b] < used[graph[j].a] + graph[j].c) {
        used[graph[j].b] = used[graph[j].a] + graph[j].c;
    }
}

void printSolution(int a) {
    if (a == -1) {
        cout << "No solution";
    } else {
        cout << a;
    }
}

int main() {

    int N, M, S, F;

    //Ввод данных
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        graph.emplace_back(gaspipeline(A - 1, B - 1, C));
    }
    cin >> S >> F;

    //Основной алгоритм
    S--;
    F--;
    used[S] = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M; j++) {
            findMaxPath(j);
        }
    }

    return printSolution(used[F]), 0;
}
