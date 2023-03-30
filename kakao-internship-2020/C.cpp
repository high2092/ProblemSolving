#include <bits/stdc++.h>

#define INF INT_MAX
#define WALL 1

using namespace std;

int solution(vector<vector<int>> board) {
    int answer[25][25][4];
    
    int len = board.size();
    
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            for (int k = 0; k < 4; k++) {
                if (board[i][j] == 0) answer[i][j][k] = INF;
                else answer[i][j][k] = -1;
            }
        }
    }
    
    
    queue <pair <pair <int, int>, int>> q;
    
    for (int d = 0; d < 4; d++) {
        answer[0][0][d] = 0;
        q.push({{0, 0}, d});
    }
    
    int dydx[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
    
    while (!q.empty()) {
        int y = q.front().first.first, x = q.front().first.second, dir = q.front().second;
        q.pop();
        for (int d = 0; d < 4; d++) {
            int yy = y + dydx[d][0], xx = x + dydx[d][1];
            
            if (yy < 0 || yy >= len || xx < 0 || xx >= len) continue;
            if (board[yy][xx] == WALL) continue;
            
            int cost = (d == dir ? 100 : 600); // 주의: 커브 자체가 500원
            
            if (answer[y][x][dir] + cost >= answer[yy][xx][d]) continue;
            
            answer[yy][xx][d] = answer[y][x][dir] + cost;
            q.push({{yy, xx}, d});
        }
    }
    
    int ans = INF;
    
    for (int d = 0; d < 4; d++) {
        ans = min(ans, answer[len-1][len-1][d]);
    }
    
    return ans;
}