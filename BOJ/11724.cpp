#include <bits/stdc++.h>

using namespace std;

vector <vector <int> > graph(1001);

bool visited[1001];

void dfs(int u) {
    visited[u] = 1;

    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    int answer = 0;

    int N, M;
    cin >> N >> M;


    int u, v;
    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            dfs(i);
            answer++;
        }
    }

    cout << answer;
}