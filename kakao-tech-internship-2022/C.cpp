#include <string>
#include <vector>
#include <algorithm>

#define MAX_POWER 150
#define MAX_REWARD 30
#define INF 301

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = INF;
    
    int alp_req = 0, cop_req = 0;
    for (int i = 0; i < problems.size(); i++) {
        if (problems[i][0] > alp_req) alp_req = problems[i][0];
        if (problems[i][1] > cop_req) cop_req = problems[i][1];
    }
    
    int dp[MAX_POWER + MAX_REWARD + 2][MAX_POWER + MAX_REWARD + 2];
    fill(&dp[0][0], &dp[MAX_POWER + MAX_REWARD + 1][MAX_POWER + MAX_REWARD + 1], INF);
    for (int a = 0; a <= alp; a++) {
        for (int c = 0; c <= cop; c++) {
            dp[a][c] = 0;
        }
    }
    
    problems.push_back({0, 0, 1, 0, 1});
    problems.push_back({0, 0, 0, 1, 1});
    
    for (int a = max(alp - MAX_REWARD, 0); a <= MAX_REWARD + alp_req; a++) {
        for (int c = max(cop - MAX_REWARD, 0); c <= MAX_REWARD + cop_req; c++) {
            for (int i = 0; i < problems.size(); i++) {
                int alp_req = problems[i][0],
                    cop_req = problems[i][1],
                    alp_rwd = problems[i][2],
                    cop_rwd = problems[i][3],
                    cost = problems[i][4];
                
                int pa = max(a - alp_rwd, 0);
                int pc = max(c - cop_rwd, 0);
                
                if (pa < alp_req || pc < cop_req) continue;
                dp[a][c] = min(dp[a][c], dp[pa][pc] + cost);
            }
        }
    }
    
    for (int a = 0; a <= MAX_REWARD; a++) {
        for (int c = 0; c <= MAX_REWARD; c++) {
            answer = min(answer, dp[alp_req + a][cop_req + c]);
        }
    }
    
    return answer;
}
