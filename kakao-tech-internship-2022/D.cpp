#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 10000001

using namespace std;

int visited[50001];
vector <vector <pair <int, int> > > graph(50001);
int isGate[50001];
int isSummit[50001];


vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    
    priority_queue <pair <int, int>, vector <pair <int, int> >, greater<pair <int, int> > > pq;
    
    for (int gate : gates) {
        pq.push({0, gate});
        isGate[gate] = 1;
    }
    
    for (int summit : summits) {
        isSummit[summit] = 1;
    }
    
    for (auto path : paths) {
        graph[path[0]].push_back({ path[2], path[1] });
        graph[path[1]].push_back({ path[2], path[0] });
    }
    
    for (int i = 1; i <= n; i++) {
        visited[i] = INF;
    }
    
    while (!pq.empty()) {
        int cost = pq.top().first, curr = pq.top().second;
        pq.pop();
        
        if (cost >= visited[curr] || (isGate[curr] && visited[curr] != INF)) continue;
        // printf("%d의 비용으로 %d 도달 가능\n", cost, curr);
        visited[curr] = cost;
        
        if (isSummit[curr]) continue;
        
        for (int i = 0; i < graph[curr].size(); i++) {
            pq.push({ max(graph[curr][i].first, cost), graph[curr][i].second });
        }
    }
    
    int summit = 0, intensity = INF;
    
    sort(summits.begin(), summits.end());
    
    for (int i = 0; i < summits.size(); i++) {
        if (visited[summits[i]] < intensity) {
            summit = summits[i];
            intensity = visited[summits[i]];
        }
    }
    
    answer.push_back(summit);
    answer.push_back(intensity);
    
    return answer;
}
