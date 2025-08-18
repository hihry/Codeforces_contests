#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define endl '\n'
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pii>
#define YES cout << "YES\n"
#define NO cout << "NO\n"


#ifdef LOCAL
#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

template<typename T> void _print(T x) { cerr << x; }
template<typename T, typename V> void _print(pair<T, V> p) { cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}"; }
template<typename T> void _print(vector<T> v) { cerr << "["; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template<typename T> void _print(set<T> s) { cerr << "{"; for (T i : s) { _print(i); cerr << " "; } cerr << "}"; }

// ========== CONSTANTS ==========
const int INF = 1e18;
const int MOD = 1e9 + 7;  // or 998244353
const int N = 2e5 + 100;

void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int n;
vector<int , pair<int , int>> adj(N);
int par[N];
int col[N];
int vis[N];
vector<vector<int>> cnt(N); 
int weight[N];
int total_cost = 0;

void clr() {
  for(int i = 1;i <= n;i++) {
    adj[i].clear();
    vis[i] = false;
    cnt[i].clear();
    weight[i] = 0;
  }
   total_cost = 0;
}
void dfs(int cur_node){
    vis[cur_node] = true;

    for(pair<int ,int> nb : adj[cur_node]){
        int node = nb.first , c = nb.second;
        if(vis[node]){
            par[node] = cur_node;
            continue;
        }

        if(col[cur_node] != col[])
    }
}
int find(int node , int x){
    if(node != 1){

    }
}
void solve() {
    clr();
    int q;
    cin >> n >> q;

    for(int i = 1 ; i <= n ; i++) cin >> col[i];

    for(int i = 0 ; i < n ; i++){
        int u , v , c;
        cin >> u >> v >> c;

        adj[u].push_back({v , c});
        adj[v].push_back({u , c});
    }

    dfs(1);
    while(q--){
        int node , x;
        cin >> node >> x;

    }
}


int32_t main() {
    fastio();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
