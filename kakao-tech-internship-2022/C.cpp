#include <string>
#include <vector>
#include <algorithm>

#define MAX_POWER 150
#define INF 301

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {

    int alp_req = 0, cop_req = 0;
    for (int i = 0; i < problems.size(); i++) {
        alp_req = max(alp_req, problems[i][0]);
        cop_req = max(cop_req, problems[i][1]);
    }

    alp = min(alp, alp_req);
    cop = min(cop, cop_req);

    int dp[MAX_POWER + 1][MAX_POWER + 1];
    fill(&dp[0][0], &dp[MAX_POWER][MAX_POWER]+1, INF);
    dp[alp][cop] = 0;

    problems.push_back({0, 0, 1, 0, 1});
    problems.push_back({0, 0, 0, 1, 1});

    for (int a = alp; a <= alp_req; a++) {
        for (int c = cop; c <= cop_req; c++) {
            for (int i = 0; i < problems.size(); i++) {
                int _alp_req = problems[i][0],
                    _cop_req = problems[i][1],
                    alp_rwd = problems[i][2],
                    cop_rwd = problems[i][3],
                    cost = problems[i][4];

                int na = min(a + alp_rwd, alp_req);
                int nc = min(c + cop_rwd, cop_req);

                if (a < _alp_req || c < _cop_req) continue;

                dp[na][nc] = min(dp[na][nc], dp[a][c] + cost);
            }
        }
    }

    return dp[alp_req][cop_req];
}
