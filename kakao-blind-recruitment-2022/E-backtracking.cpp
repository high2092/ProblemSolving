#include <iostream>
#include <vector>

#define SHEEP 0
#define WOLF 1

using namespace std;

int type[18];
int cnt[2];
vector <vector <int> > tree(18);
vector <vector <int> > wolf(18);
int answer;
// string log = "";

void dfs(int curr, vector <int> next) {
    // string s = "->" + to_string(curr);
    // log += s;
    // cout << log << " 양" << cnt[SHEEP] << " 늑대" << cnt[WOLF] << '\n';
    cnt[type[curr]]++;
    
    if (cnt[SHEEP] > cnt[WOLF]) {
        if (cnt[SHEEP] > answer) answer = cnt[SHEEP];

        for (int n : tree[curr]) {
            next.push_back(n);
        }

        for (int i = 0; i < next.size(); i++) {
            vector <int> _next = next;
            _next.erase(_next.begin() + i);
            dfs(next[i], _next);
        }
    }
    
    cnt[type[curr]]--;
    // log = log.substr(0, log.size() - s.size());
}

int solution(vector<int> info, vector< vector <int> > edges) {
    for (int i = 0; i < info.size(); i++) {
        type[i] = info[i];
    }
    
    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        tree[u].push_back(v);
    }
    
    dfs(0, vector<int>{});
    
    return answer;
}
