// https://lightoj.com/problem/not-the-best

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
#define    F               first
#define    S               second
#define    pb              push_back
#define    all(x)          x.begin(), x.end()
#define    rev(x)          reverse(all(x))
#define    com             greater<int>()
#define    input(v)        for (auto& u : v) cin >> u
#define    output(v)       for (const auto& u : v) cout << u << " "

const int mx = 5e3;
vpl adj[mx];
ll dist[3][mx];

struct info {
    int u, v, w;
};

void dijkstra ( int s, int n, int f1 )
{
    for ( int i = 1; i <= n; i++ ) dist[f1][i] = LONG_MAX;

    priority_queue< pll, vpl, greater<pll> > pq;

    dist[f1][s] = 0;
    pq.push ( { 0, s } );

    while ( !pq.empty() ) {
        int u = pq.top().S;
        ll curD = pq.top().F;
        pq.pop();

        if ( curD > dist[f1][u] ) continue;

        for ( auto v : adj[u] ) {
            if ( v.S + curD < dist[f1][v.F] ) {
                dist[f1][v.F] =  v.S + curD;
                pq.push( { dist[f1][v.F], v.F } );
            }
        }

    }
}


int main()
{
	FAST

    int T;
    cin >> T;
    for ( int tc = 1; tc <= T; tc++ ) {
        for( int i = 1; i <= 5e3; i++ ) adj[i].clear();

        vector<info> edge;
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].pb ( { v, w } );
            adj[v].pb ( { u, w } );
            edge.pb   ( {u, v, w} );
        }

        dijkstra( 1, n, 0 );
        dijkstra( n, n, 1 );

        ll s1 = dist[0][n];
        ll s2 = LONG_MAX;

        for(auto e:edge){
            ll currD = min( dist[0][e.u]+dist[1][e.v] , dist[1][e.u]+dist[0][e.v]);
            if(currD+e.w>s1){
                s2=min(s2,currD+e.w);
            }
            if(currD+e.w==s1){
                s2=min(s2,currD+(e.w*3));
            }
        }
        cout<<"Case "<<tc<<": "<<s2<<nl;

    }


	return 0;
}
