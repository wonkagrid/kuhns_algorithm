#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;
const int max_part_size = 10000;

vector<int> graph[max_part_size]; //граф задаётся неявно
int right_part[max_part_size]; // количество сопоставленных вершин из правой доли
bool visited[max_part_size];

// обход в ширину
bool bfs(int value) {
    for (int i = 0; i < graph[value].size(); i++) {
        int v = graph[value][i];
        if (!visited[v]) {
            visited[v] = true;

            if (right_part[v] == -1 || bfs(right_part[v])) {
                right_part[v] = value;
                return true;
            }
        }
    }
    return false;
};
/*bool dfs(int value) {
    for (int i = 0; i < graph[value].size(); i++) {
        int v = graph[value][i];
        if (!visited[v]) {
            visited[v] = true;

            if (right_part[v] == -1 || dfs(right_part[v])) {
                right_part[v] = value;
                return true;
            }
        }
    }
    return false;
}*/

// алгоритм куна
int kuhn(int value) {
    for (int i = 0; i < max_part_size; i++)
        right_part[i] = -1;

    int count = 0;

    for (int i = 0; i < value; i++) {
        for (int j = 0; j < max_part_size; j++)
            visited[j] = false;
        if (bfs(i))
            count++;
    }

    return count;
};

int main() {
    graph[0].push_back(6);
    graph[1].push_back(6);
    graph[1].push_back(7);
    graph[2].push_back(7);
    graph[2].push_back(8);
    graph[3].push_back(8);
    graph[3].push_back(9);
    graph[4].push_back(9);
    graph[4].push_back(10);
    graph[5].push_back(10);
    int left = 5; // сколько будет в левой доле вершин
    /*auto start = high_resolution_clock::now();
    time_t now1 = high_resolution_clock::to_time_t(start);*/
    int ez = kuhn(left);
    /*auto end = high_resolution_clock::now();
    time_t now2 = high_resolution_clock::to_time_t(end);*/
    cout << "max matching " << ez << endl;
    //cout << "time " << now2 - now1;
    return 0;
}
// с точки зрения затрат по времени c доли, где меньше вершин, лучше запускать(???????)
