#include <iostream>
#include <vector>

#define ATTACK 1
#define HEAL 2

using namespace std;

int range[1001][1001];

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    
    int type, r1, c1, r2, c2, degree;
    for (auto sk : skill) {
        type = sk[0];
        r1 = sk[1];
        c1 = sk[2];
        r2 = sk[3];
        c2 = sk[4];
        degree = sk[5];
        
        if (type == HEAL) degree *= -1;
        
        range[r1][c1] -= degree;
        range[r2+1][c1] += degree;
        range[r1][c2+1] += degree;
        range[r2+1][c2+1] -= degree;
    }
    
    
    for (int i = 0; i < board.size(); i++) {
        for (int j = 1; j < board[i].size(); j++) {
            range[i][j] += range[i][j-1];
        }
    }
    
    for (int i = 1; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            range[i][j] += range[i-1][j];
        }
    }
    
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] + range[i][j] > 0) answer++;
        }
    }
    
    return answer;
}