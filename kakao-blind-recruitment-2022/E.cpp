#include <iostream>
#include <queue>

#define SHEEP 0
#define WOLF 1

using namespace std;

vector <int> tree[18];
int visited[1 << 17];

int solution(vector<int> info, vector< vector <int> > edges) {
    int answer = 0;

    int n = info.size();
    for (auto edge : edges) {
        tree[edge[0]].push_back(edge[1]);
    }
    
    queue <int> q;
    q.push(1);
    visited[1] = 1;
    
    while (!q.empty()) {
        int state = q.front();
        q.pop();
        
        int cnt[2] = {};
        for (int i = 0; i < n; i++) {
            if ((state >> i) & 1) {
                cnt[info[i]]++;
            }
        }
        
        if (cnt[WOLF] >= cnt[SHEEP]) continue;
        if (cnt[SHEEP] > answer) answer = cnt[SHEEP];
        
        for (int i = 0; i < n; i++) {
            if ((state >> i) & 1) {
                for (int next : tree[i]) {
                    int newState = state | (1 << next);
                    if (!visited[newState]) {
                        q.push(newState);
                        visited[newState] = 1;
                    }
                }
            }
        }
    }
    
    return answer;
}
