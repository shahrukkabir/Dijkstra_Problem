// https://cses.fi/problemset/task/1671

#include <bits/stdc++.h>
using namespace std;
 
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define nl '\n'
#define F first
#define S second
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<pll> vll; 
const ll infLL = 9000000000000000000;
                                                      //T.C : O( E + V*log2(n) )
const int mx = 1e5 + 123;
vector<pair<int, int>> adj[mx];
ll dist[mx];
 
void dijkstra(int s, int n) {
    for (int i = 0; i <= n; i++) {
        dist[i] = infLL;                              //initialization
    }
    dist[s] = 0;                                      // initializing source distance   
 
    priority_queue<pll, vll, greater<pll>> pq;        // sort small to big
    pq.push({0, s});                                  // {dist, node}
    while (!pq.empty()) {
        int u = pq.top().S;                           // u -> node
        ll currD = pq.top().F;                        // currD -> dist
        pq.pop();
        if (dist[u] < currD) {                        // dis[u] -> previous distance
            continue;
        }
        for (auto p : adj[u]) {                      // p -> {node, cost}
            int v = p.F;                             // v -> node 
            ll  w = p.S;                             // w -> cost
            if (currD + w < dist[v]) {               // currD + w -> go to node v
                dist[v] = currD + w;                 // relaxation
                pq.push({dist[v], v});
            }
        }
    }
}
 
int main() {
    FAST
 
    int n, e;
    cin >> n >> e;
    for (int i = 1; i <= e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        // adj[v].push_back({u, w});
    }
 
    dijkstra(1, n);
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << nl;
 
    return 0;
}
 
 
// 5 7
// 1 3 3
// 1 2 2
// 1 4 6
// 2 0 6
// 2 3 7
// 0 4 3
// 3 4 5
 
// 0 8 6 8 3