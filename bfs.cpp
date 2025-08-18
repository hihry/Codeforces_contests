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
const int N = 2e5 + 5;

vector<vector<int>> adj;
void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void dfs(int cur_node , vector<int> &vis, int &size , int n){
    vis[cur_node] = 1;

    size += 1;
    for(auto &nb : adj[cur_node] ){
        if(!vis[nb]){
            dfs(cur_node , vis , size , n);
        }
    } 
}
int help(int root){
    double r = sqrt(root);
    int k = (int)r;

    if(r > k) return r += 1;
    return r;
}

void bfs(int cur_node , vector<int> &vis , int n , int &size){

    queue<int> q;
    q.push(cur_node);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(auto &nb : adj[cur_node]){
            if(!vis[nb]){
                vis[nb] = 1;
                q.push(nb);
                size += 1;
            }
        }
    }
}
void solve(int n , vector<int> &graph_from , vector<int> &graph_to) {
    adj.clear();
    adj.resize(n+1);
    for(int i = 0 ; i < graph_from.size() ; i++){
        int u = graph_from[i] , v = graph_to[i];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    vector<int> vis(n+1  , 0);
    // for(int i = 1 ; i <= n ; i++){
    //     if(!vis[i]){
    //         int size = 0 ;

    //         dfs(i , vis , size , n);

    //         ans += help(size);
    //     }
    // }

    for(int i = 1 ; i <= n; i++){
        if(!vis[i]){
            int size = 0;
            bfs(i , vis , n , size);
            ans += help(size);
        }
    }
    
    cout << ans << '\n';

}


int32_t main() {
    fastio();

    int t = 1;
    cin >> t;
    while (t--) {
        int n , m;
        cin >> n >> m;

        vector<int> graph_from(m) , graph_to(m);
        for(int i = 0 ; i < m ; i++){
            cin >> graph_from[i];
        }
        for(int i = 0 ; i < m ; i++){
            cin >> graph_to[i];
        }
    }

    return 0;
}
