#include<bits/stdc++.h>
using namespace std;

//typedefs
typedef         long long           ll;
typedef         double              dl;
typedef         vector<int>         vin;
typedef         vector<ll>          vll;
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
const       ll       mod    =   1e7+7;
const       int      mx     =   1e3+123;

vector<pair<int, int>> adj[mx];                       
ll dist[mx];

void dijkstra(int s, int n) {
    for (int i = 0; i <= n; i++) {
        dist[i] = LLONG_MAX;                             
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
    
     int t; cin >> t;
     for(int i=1;i<=t;i++){
      int n,m; cin>>n>>m;
      for(int i=1;i<=n;i++) adj[i].clear();
      for(int i=1;i<=m;i++){
        int u,v,w; cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
      }
      dijkstra(1,n);
      if(dist[n]==LLONG_MAX){
        cout<<"Case "<<i<<": "<<"Impossible"<<nl; 
      }
      else{
        case(dist[n]);
      }
     }
    
    
     return 0;
}