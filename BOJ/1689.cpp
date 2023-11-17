#include <bits/stdc++.h>

using namespace std;

pair <int, int> record[2000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int answer = 0;

    int N; cin >> N;

    int s, e;

    for (int i = 0; i < N; i++) {
        cin >> s >> e;
        record[i] = make_pair(s, 1);
        record[i+N] = make_pair(e, -1);
    }

    sort(record, record + 2*N);

    int overlap = 0;

    for (int i = 0; i < 2*N; i++) {
        auto line = record[i];
        overlap += record[i].second;

        answer = max(overlap, answer);
    }

    cout << answer;
}