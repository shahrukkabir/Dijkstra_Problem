// https://lightoj.com/problem/country-roads

#include<bits/stdc++.h>
using namespace std;

//typedefs
typedef         long long           ll;
typedef         double              dl;
typedef         vector<int>         vin;
typedef         vector<ll>          vll;
typedef         pair<int, int>      pii;
typedef         pair<ll, ll>        pll;
typedef         vector<pll>         vpl;

// Macros
#define         FAST                ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define         nl                  '\n'
#define         yes                 cout<<"YES"<<nl
#define         no                  cout<<"NO"<<nl
#define         case(x)             cout<<"Case "<<i<<": "<<x<<nl
#define         F                   first
#define         S                   second
#define         pb                  push_back
#define         sz(x)               (int)x.size()
#define         all(x)              x.begin(), x.end()
#define         input(v)            for (auto& u : v) cin >> u
#define         output(v)           for (const auto& u : v) cout << u << " "
#define         mem(a,b)            memset(a, b, sizeof(a) )

//Debugger
template<typename T>ostream&operator<<(ostream&os,const vector<T>&v){os<<"{";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"}";}
#define dbg(args...) do {cerr << #args << " : "; srk(args); } while(0)
void srk(){cerr << endl;}
template<typename T>void srk(T a[],int n){for(int i=0;i<n;++i)cerr<<a[i]<<' ';cerr<<endl;}
template<typename T,typename...hello>void srk(T arg,const hello&...rest){cerr<<arg<<' ';srk(rest...);}

//Const
const   ll    mod  =  1e7+7;
const   int   mx   =  523;

vector<pll>adj[mx];                       
ll dist[mx];

void dijkstra(int s,int n) {
    for (ll i=0;i<n;i++) {
        dist[i]=LLONG_MAX;                             
    }
    dist[s]=0;                                
    priority_queue<pll, vpl, greater<pll>> pq;    
    pq.push({0,s});                                
    while (!pq.empty()) {
        ll currD=pq.top().F;                    
        ll u=pq.top().S;                           
        pq.pop();
        if (currD>dist[u]) {                      
            continue;                                
        }
        for (auto p:adj[u]) {                     
            ll v=p.F;                              
            ll w=p.S;                              
            ll maxCost = max(currD,w);
            if(dist[v]>maxCost){
              dist[v]=maxCost;
              pq.push({dist[v],v});
            }
        }
    }
}


int main() {
    
     FAST
    
     int t; cin>>t; 
     for(ll i=1;i<=t;i++){
        cout<<"Case "<<i<<":"<<nl;
        int n,m; cin>>n>>m;
        for(int i=0;i<n;i++) adj[i].clear();
        while(m--){
          int u,v,w; cin>>u>>v>>w;
          adj[u].pb({v,w});
          adj[v].pb({u,w});
        }
        int d; cin>>d;
        dijkstra(d,n);
        for(int i=0;i<n;i++){
          if(dist[i]==LLONG_MAX){
            cout<<"Impossible"<<nl;
          }
          else{
            cout<<dist[i]<<nl;
          }
        }
     }
    
    
     return 0;
}