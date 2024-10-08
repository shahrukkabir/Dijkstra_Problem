// https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

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

vpl adj[mx];
ll  dist[mx];

void dijkstra ( int s, int n, int k )
{
    for ( int i = 0; i <= n; i++ ) dist[i] = LONG_MAX;
    priority_queue< vll, vector<vll>, greater<vll>> pq;

    dist[s] = 0;
    pq.push ( { 0, 0, s } );

    while ( !pq.empty() ) {
        int stops = pq.top()[0];
        ll  curD  = pq.top()[1];
        int u     = pq.top()[2];
        pq.pop();

        for ( auto p : adj[u] ) {
            int v = p.F;
            int w = p.S;
            if ( curD + w < dist[v] && stops <= k ) {
                dist[v] = curD + w;
                pq.push( { stops+1, dist[v], v } );  //{stops, dis, node}
            }
        }
    }
}



class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {

        for ( int i = 0; i <= n; i++ ) adj[i].clear();

        for ( auto u : flights ) {
            adj[u[0]].push_back ( { u[1], u[2] } );
        }

        dijkstra ( src, n, K );

        if ( dist[dst] == LONG_MAX ) dist[dst] = -1;

        return dist[dst];
    }
};


