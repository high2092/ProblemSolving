#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

char dirString[4] = {'d', 'l', 'r', 'u'};
int dir[4][2] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
bool visited[51][51][2501];
bool flag;

int N, M, R, C;

vector <string> answers;

void dfs(int rr, int cc, int k, string pp) {
    if (flag) return;

    if (k == 0) {
        // 방문 우선순위를 설정하고 DFS를 실행했기 때문에 첫 경로가 정답이다
        if (rr == R && cc == C) {
            answers.push_back(pp);
            flag = true;
        }
        return;
    }
    
    for (int d = 0; d < 4; d++) {
        int nr = rr + dir[d][0], nc = cc + dir[d][1];
        string np = pp + dirString[d];
        
        if (nr <= 0 || nr > N || nc <= 0 || nc > M) continue;
        if (visited[nr][nc][k-1]) continue;
        
        visited[nr][nc][k-1] = 1;
        dfs(nr, nc, k-1, np);
        
        if (flag) return;
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    N = n;
    M = m;
    R = r;
    C = c;
    
    dfs(x, y, k, "");
    
    answer = answers.size() == 0 ? "impossible" : answer = answers[0];
    
    return answer;
}