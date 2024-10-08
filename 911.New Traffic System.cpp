// https://lightoj.com/problem/new-traffic-system

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

const  int  mx  = 1e4+123;
vector<vll>adj[mx];      //adj[0]= [{2,8,3},{1,5,5},{5,9,2}] 
ll dist[12][mx];

void dijkstra( ll s, ll n, ll d ){
   for(ll i=0;i<=d;i++){
    for(ll j=0;j<n;j++){
      dist[i][j]=LLONG_MAX;
    }
   }
   priority_queue<vll,vector<vll>,greater<vll>>pq;
   dist[0][s]=0;
   pq.push({0,0,s}); //dist,type,node
    while(!pq.empty()){

        ll curD=pq.top()[0];
        ll cnt=pq.top()[1];
        ll u=pq.top()[2];

        pq.pop();

        if(curD>dist[cnt][u]) continue;

        for(auto e:adj[u]){

          ll v = e[0];
          ll w = e[1];
          ll t = e[2];

          if(cnt+t<=d && dist[cnt][u]+w<dist[cnt+t][v]){
            dist[cnt+t][v]=dist[cnt][u]+w;
            pq.push({dist[cnt+t][v],cnt+t,v});
          }
        }
    }

}

int main() {
    
     FAST
    
     ll t; cin >> t;
     for(ll i=1;i<=t;i++){
      ll n,m,k,d; cin>>n>>m>>k>>d;

      for(ll i=0;i<n;i++) adj[i].clear();

      for(ll i=0;i<m;i++){
        ll u,v,w; cin>>u>>v>>w;
        adj[u].pb({v,w,0});
      }

      for(ll i=0;i<k;i++){
        ll u,v,w; cin>>u>>v>>w;
        adj[u].pb({v,w,1});
      }

      dijkstra(0,n,d);

      ll ans=LLONG_MAX;
      for(ll i=0;i<=d;i++){
        ans=min(ans,dist[i][n-1]);
      }
      
      if(ans==LLONG_MAX){
        cout<<"Case "<<i<<": Impossible\n";
      }
      else{
        case(ans);
      }
     }
    
     return 0;
}