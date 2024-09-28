// https://codeforces.com/problemset/problem/20/C

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

#define    F               first
#define    S               second
#define    pb              push_back
#define    all(x)          x.begin(), x.end()
#define    rev(x)          reverse(all(x))
#define    com             greater<int>()
#define    input(v)        for (auto& u : v) cin >> u
#define    output(v)       for (const auto& u : v) cout << u << " "



ll dist[mx];
vector<pair<int,int>> adj[mx];
ll par[mx];

void dijkstra(int s, int n) {
    for (int i = 1; i <= n; i++) dist[i] = LONG_MAX;
    priority_queue<pll, vpl, greater<pll>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        int u = pq.top().S;
        ll curD = pq.top().F;
        pq.pop();
        if (curD > dist[u]) continue;
        for (auto p : adj[u]) {
            int v = p.F;
            int w = p.S;
            if (curD + w < dist[v]) {
                dist[v] = curD + w;
                par[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    FAST
    
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    dijkstra(1, n);
    if (dist[n] == LONG_MAX) {
        cout << -1 << nl;
        return 0;
    }

    int u = n;
    vector<int> ans;
    ans.pb(n);
    while (par[u] != 0) {
        ans.pb(par[u]);
        u = par[u];
    }
    rev(ans);
    output(ans);
    cout << nl;

    return 0;
}