#include <bits/stdc++.h>

using namespace std;

pair <int, int> lines[1000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    int answer = 0;
    int N; cin >> N;

    int s, e;

    for (int i = 0; i < N; i++) {
        cin >> s >> e;
        lines[i] = make_pair(s, e);
    }

    sort(lines, lines + N);

    s = lines[0].first;
    e = lines[0].second;

    for (int i = 1; i < N; i++) {
        auto line = lines[i];
        if (e < line.first) { // 끊김
            answer += e - s;

            s = line.first;
            e = line.second;
        } else {
            e = max(line.second, e);
        }
    }

    answer += e - s;

    cout << answer;
}