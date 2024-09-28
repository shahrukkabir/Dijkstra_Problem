// https://cses.fi/problemset/task/1671

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
                                                      
const int mx = 1e5 + 123;
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
            ll  w = p.S;                          
            if (currD + w < dist[v]) {             
                dist[v] = currD + w;                 
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