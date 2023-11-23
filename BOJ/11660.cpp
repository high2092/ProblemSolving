#include <bits/stdc++.h>

using namespace std;

int table[1025][1025];
int acc[1025][1025];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M; cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> table[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            acc[i][j] = acc[i][j-1] + table[i][j];
        }
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            acc[i][j] += acc[i-1][j];
        }
    }

    int x1, y1, x2, y2;
    for (int i = 0; i < M; i++) {
        cin >> x1 >> y1 >> x2 >> y2; // x행 y열
        cout << acc[x2][y2] - (acc[x2][y1-1] + acc[x1-1][y2] - acc[x1-1][y1-1]) << '\n';
    }
}