https://lightoj.com/problem/not-the-best

///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///



#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef double dl;

#define endl '\n'
#define PB push_back
#define F first
#define S second
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) (int)x.size()

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007

#define mem(a,b) memset(a, b, sizeof(a) )
#define sqr(a) ((a) * (a))

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
//
//debug
template<typename F,typename S>ostream&operator<<(ostream&os,const pair<F,S>&p){return os<<"("<<p.first<<", "<<p.second<<")";}
template<typename T>ostream&operator<<(ostream&os,const vector<T>&v){os<<"{";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"}";}
template<typename T>ostream&operator<<(ostream&os,const set<T>&v){os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<",";os<<*it;}return os<<"]";}
template<typename T>ostream&operator<<(ostream&os,const multiset<T>&v) {os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"]";}
template<typename F,typename S>ostream&operator<<(ostream&os,const map<F,S>&v){os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<it->first<<" = "<<it->second;}return os<<"]";}
#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void faltu(){cerr << endl;}
template<typename T>void faltu(T a[],int n){for(int i=0;i<n;++i)cerr<<a[i]<<' ';cerr<<endl;}
template<typename T,typename...hello>void faltu(T arg,const hello&...rest){cerr<<arg<<' ';faltu(rest...);}
//#else
//#define dbg(args...)

ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
ll lcm ( ll a, ll b ) { return a * ( b / gcd ( a, b ) ); }


int dx[] = { 0, 0, +1, -1, -1  +1, -1, +1 };
int dy[] = { +1, -1, 0, 0, -1, +1, +1, -1 };


const int mx = 5e3;
vii adj[mx];
ll dist[3][mx];

struct info {
    int u, v, w;
};

void dijkstra ( int s, int n, int f1 )
{
    for ( int i = 1; i <= n; i++ ) dist[f1][i] = inf;

    priority_queue< pll, vll, greater<pll> > pq;

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
	optimize();

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
            adj[u].PB ( { v, w } );
            adj[v].PB ( { u, w } );
            edge.PB ( {u, v, w} );
        }

        dijkstra( 1, n, 0 );
        dijkstra( n, n, 1 );

        ll s1 = dist[0][n];
        ll s2 = infLL;

        for ( auto e : edge ) {
            ll curD = min ( dist[0][e.u] + dist[1][e.v], dist[1][e.u] + dist[0][e.v] );

            if ( curD + e.w > s1 ) {
                s2 = min ( s2, curD + e.w );
            }

            if ( curD + e.w == s1 )  s2 = min ( s2, curD + ( e.w * 3 ) );
        }

        cout << "Case " << tc << ": " << s2 << endl;

    }


	return 0;
}
