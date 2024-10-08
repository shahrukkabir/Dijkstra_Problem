// https://www.geeksforgeeks.org/problems/minimum-cost-path3833/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCostPath(vector<vector<int>>& grid) {

        int n = grid.size();
        
        vector<vector<long long>> dist(n, vector<long long>(n, LONG_MAX));        
        priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<pair<long long, pair<int, int>>>> pq;

        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        while (!pq.empty()) {
            
            pair<int, int> u = pq.top().second;
            long long curD = pq.top().first;
            pq.pop();
    
            int x = u.first;
            int y = u.second;

            if (dist[x][y] < curD) continue;

            for (int i = 0; i < 4; i++) {
                int x1 = x + dx[i], y1 = y + dy[i];

                if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < n && curD + grid[x1][y1] < dist[x1][y1]) {
                    dist[x1][y1] = curD + grid[x1][y1];
                    pq.push({dist[x1][y1], {x1, y1}});
                }
            }
        }

        return dist[n-1][n-1];
    }
};


