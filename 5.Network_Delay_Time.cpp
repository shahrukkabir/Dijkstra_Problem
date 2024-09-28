// https://leetcode.com/problems/network-delay-time/description/

#include <bits/stdc++.h>
using namespace std;

#define    FAST            ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define    nl              '\n'
#define    F               first
#define    S               second
typedef    long long       ll;
typedef    vector<ll>      vll;
typedef    pair<ll, ll>    pll;
typedef    vector<pll>     vpl;                       
const      int             mx = 1e5+123;

vector<pair<int, int>> adj[mx];
ll dist[mx];

void dijkstra(int s, int n) {
    for (int i = 0; i <= n; i++) {
        dist[i] = LONG_MAX;
    }
    dist[s] = 0;

    priority_queue<pll, vpl, greater<pll>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        int u = pq.top().S;
        ll currD = pq.top().F;
        pq.pop();
        if (dist[u] < currD) {
            continue;
        }
        for (auto p : adj[u]) {
            int v = p.F;
            ll w = p.S;
            if (currD + w < dist[v]) {
                dist[v] = currD + w;
                pq.push({dist[v], v});
            }
        }
    }
}

//find the maximum shortest path of any node 

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for (int i = 0; i <= n; i++) adj[i].clear();
        for (auto& u : times) {
            adj[u[0]].push_back({u[1], u[2]});
        }
        dijkstra(k, n);
        ll mx = -1;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == LONG_MAX) {
                return -1;
            }
            mx = max(mx, dist[i]);
        }
        return mx;
    }
};
