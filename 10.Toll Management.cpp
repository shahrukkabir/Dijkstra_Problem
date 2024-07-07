https://lightoj.com/problem/toll-management

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
const           ll              mod    =   1e7+7;
const           int             inf    =   2e9;
const           ll              infLL  =   1e18;
const           int             mx     =   1e4+123;

vector<pair<int,int>>adj[3][mx];
ll dist[3][mx];

struct info{
     int u,v,w; 
};

void dijkstra(int s, int n, int f){
     for(int i=1;i<=n;i++) dist[f][i]=infLL;
     dist[f][s]=0;
     priority_queue<pll,vpl,greater<pll>>pq;
     pq.push({0,s});
     while(!pq.empty()){
          int curD = pq.top().F;
          int u = pq.top().S;
          pq.pop();
          if(curD>dist[f][u]) continue;
          for(auto e:adj[f][u]){
               int v = e.F;
               int w = e.S;
               if(curD+w<dist[f][v]){
                    dist[f][v]=curD+w;
                    pq.push({dist[f][v],v});
               }
          }
     }

}
     

int main() {
    
     FAST
    
     int t; cin >> t;
     for(int i=1;i<=t;i++){
          int n,m,s,t,p; cin>>n>>m>>s>>t>>p;
          vector<info>edge;
          for(int j=0;j<=n;j++){
               adj[0][j].clear();
               adj[1][j].clear();
          }
          for(int i=0;i<m;i++){
               int u,v,w; cin>>u>>v>>w;
               adj[0][u].pb({v,w});
               adj[1][v].pb({u,w});
               edge.pb({u,v,w});
          }
          dijkstra(s,n,0);
          dijkstra(t,n,1);
          ll ans=-1;
          for(auto e : edge){
               int u=e.u;
               int v=e.v;
               int w=e.w;
               ll cost = dist[0][u]+w+dist[1][v];
               if(cost<=p){
                    ans=max(ans,(ll)w);
               } 
          }
          case(ans);
     }
    
     return 0;
}